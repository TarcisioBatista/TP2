#include "AccessControl.h"

//Construtor
AccessControl::AccessControl(){
    //abrir bd
    open_bd();
}

//Destrutor
AccessControl::~AccessControl(){
    //fecha bd
    close_bd();   
}

//Esse método abre a conexão com o banco de dados
void AccessControl::open_bd(){
    rc = sqlite3_open("dbtp2.db3", &db);
    if(rc != SQLITE_OK)
        wxMessageBox( _("Erro ao abrir banco de dados!"),_("Erro"), wxOK | wxICON_INFORMATION ); 
}
//Esse método fecha a conexão com o bando de dados
void AccessControl::close_bd(){
    sqlite3_close(db);    
}

//Esse método executa uma sql no banco de dados e retorna o resultado como string. 
//Caso retorne "0" a instrução não foi executada ou o registro procurado não foi encontrado
std::string AccessControl::executa(const char *sql){
    std::string result;  
    
    //prepara sql para ser executada
    rc = sqlite3_prepare_v2(db, sql , -1, &statement, 0);    
    if(rc != SQLITE_OK)
        return "0";
        //wxMessageBox( _("Erro na conexão com banco de dados!"),_("Erro"), wxOK | wxICON_INFORMATION );
    
    //executa sql
    rc = sqlite3_exec(db,sql,0,0,&err_msg);
    if(rc != SQLITE_OK)
        wxLogMessage(err_msg, _("Erro"), wxOK | wxICON_INFORMATION);
        
    //receber resultado da consulta
    rc = sqlite3_step(statement);
    if(rc ==  SQLITE_ROW)
            result = (char*)sqlite3_column_text(statement, 0);
    else
        result = "0";    
    sqlite3_finalize(statement);
    
    return result;
}

//Esse método converte uma wxString para std::string
std::string AccessControl::convertToString(wxString text){
    std::string newText = std::string(text.mb_str());
    return newText;
}

//Esse método converte um char* para uma string
std::string AccessControl::convertToString1(const char* text){
    std::string result = text;
    return result;
}

//Esse método converte uma std::string para wxString
wxString AccessControl::convertTowxString(std::string text){
    wxString newText(text);
    return newText;
}

//Esse método converte uma string para um char*
const char *AccessControl::convertToChar(std::string text){
    const char *result = text.c_str();
    return result;
}

//Esse método monta uma consulta sql com a variável passada como parâmetro
//option indica qual consulta será feita.
std::string AccessControl::createQuery(std::string field, int option){
    std::string query;
    //opção == 1 verifica a senha
    if(option==1)
        query = "SELECT idUser from user WHERE senha = '" + field + "';";
    //opção == 2 verifica login
    else if (option == 2)
        query = "SELECT idUser from user WHERE login = '" + field + "';";
    return query;   
}

//Esse método checa o id correspondente à senha ou login digitado armazenado no bd e o retorna como string
std::string AccessControl::checkLogin(wxString text, int option){
    //Criar query
    std::string textString = convertToString(text);
    std::string query = createQuery(textString,option);
    
    //Executar query
    const char *queryChar = convertToChar(query);  
    std::string resultQuery = executa(queryChar);

    return resultQuery;
}

//Esse método monta as instruções sql para inserir o log no banco de dados
//A instrução é montada de acordo com o valor de option
std::string AccessControl::sqlLog(std::string text, int option){
    std::string query;
    
    switch (option){
        case 1:
            //começa a sql de inserir até o idAcao 
            query = "INSERT INTO acao(idAcao, idDescAcao, idUser, data, hora) VALUES (NULL, " + text + ", ";
            //Como a instrução sql ainda não está completa ela é armazenada temporariamente nesse variável
            logString = query;
            break;
        case 2:
            //coloca o idUser, a data e a hora
            //Hora e data atual do sistema
            char dateStr [9];
            char timeStr [9];
            _strdate(dateStr);
            _strtime(timeStr);
            //Monta instrução sql
            //Soma a instrução temporária armazenada, o idUser que foi passado no parâmetro text, a data e a hora atuais            
            query = logString + text + ", '" + dateStr + "', '" + timeStr + "');";
            break;
        case 3:
            //insere na tabela de log a acao executada
            //text é o idAcao
            query = "INSERT INTO log(idLog, idAcao) VALUES (NULL, " + text + ");";
            break;
        case 4:
            //seleciona o id da ação executada
            query = "SELECT idDescAcao from descAcao WHERE descricao = '" + text + "';";
            break;
        case 5:
            //seleciona o id da última ação adicionada ao bd  
            query = "SELECT MAX(idAcao) from acao;";
            break;  
        case 6:
            //Seleciona o idAcao do último ação executada (identificada no text)
            query = "SELECT MAX(idAcao) from acao WHERE idDescAcao = " + text + ";";
            break;
        case 7:
            //Seleciona o id do usuário que fez o ultimo login
            query = "SELECT idUser FROM acao WHERE idAcao = " + text + ";";    
    }
    //retorna instrução sql pronta
    return query; 
}

//Esse método insere o log das ações executadas no banco de dados
void AccessControl::log(int option){
    std::string query;
    const char *queryChar;
    std::string idDescAcao;
    
    if(option == 1)
        //opção == 1 armazena login
        //Monta sql para pegar id do login
        query = sqlLog("login", 4);
    else if(option == 2){
        //opção == 2 armazena logout        
        
        //recebe o idAcao do ultimo login executado
        query = sqlLog("1",6);
        queryChar = convertToChar(query);
        std::string idAcao = executa(queryChar);
        //recebe o id do usuário que executou o último login
        query = sqlLog(idAcao,7);
        queryChar = convertToChar(query);
        idUser = executa(queryChar);
        
        //Monta sql para encontrar id do logout 
        query = sqlLog("logout", 4); 
        }
        
    //pega id da ação realizada    
    queryChar = convertToChar(query);
    idDescAcao = executa(queryChar);
    
    //faz sql e insere a acao na tabela de acao
    query = sqlLog(idDescAcao, 1);
    query = sqlLog(idUser, 2);
    queryChar = convertToChar(query);
    executa(queryChar);
       
    //Pega o id da ultima acao armazenada
    query = sqlLog("", 5);
    queryChar = convertToChar(query);
    std::string idAcao = executa(queryChar);
    
    //Monta sql com esse id e coloca na tabela de log do bd
    query = sqlLog(idAcao, 3); 
    queryChar = convertToChar(query);     
    executa(queryChar);
}
