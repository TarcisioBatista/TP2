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

//Esse m�todo abre a conex�o com o banco de dados
void AccessControl::open_bd(){
    rc = sqlite3_open("dbtp2.db3", &db);
    if(rc != SQLITE_OK)
        wxMessageBox( _("Erro ao abrir banco de dados!"),_("Erro"), wxOK | wxICON_INFORMATION ); 
}
//Esse m�todo fecha a conex�o com o bando de dados
void AccessControl::close_bd(){
    sqlite3_close(db);    
}

//Esse m�todo executa uma sql no banco de dados e retorna o resultado como string. 
//Caso retorne "0" a instru��o n�o foi executada ou o registro procurado n�o foi encontrado
std::string AccessControl::executa(const char *sql){
    std::string result;  
    
    //prepara sql para ser executada
    rc = sqlite3_prepare_v2(db, sql , -1, &statement, 0);    
    if(rc != SQLITE_OK)
        return "0";
        //wxMessageBox( _("Erro na conex�o com banco de dados!"),_("Erro"), wxOK | wxICON_INFORMATION );
    
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

//Esse m�todo converte uma wxString para std::string
std::string AccessControl::convertToString(wxString text){
    std::string newText = std::string(text.mb_str());
    return newText;
}

//Esse m�todo converte um char* para uma string
std::string AccessControl::convertToString1(const char* text){
    std::string result = text;
    return result;
}

//Esse m�todo converte uma std::string para wxString
wxString AccessControl::convertTowxString(std::string text){
    wxString newText(text);
    return newText;
}

//Esse m�todo converte uma string para um char*
const char *AccessControl::convertToChar(std::string text){
    const char *result = text.c_str();
    return result;
}

//Esse m�todo monta uma consulta sql com a vari�vel passada como par�metro
//option indica qual consulta ser� feita.
std::string AccessControl::createQuery(std::string field, int option){
    std::string query;
    //op��o == 1 verifica a senha
    if(option==1)
        query = "SELECT idUser from user WHERE senha = '" + field + "';";
    //op��o == 2 verifica login
    else if (option == 2)
        query = "SELECT idUser from user WHERE login = '" + field + "';";
    return query;   
}

//Esse m�todo checa o id correspondente � senha ou login digitado armazenado no bd e o retorna como string
std::string AccessControl::checkLogin(wxString text, int option){
    //Criar query
    std::string textString = convertToString(text);
    std::string query = createQuery(textString,option);
    
    //Executar query
    const char *queryChar = convertToChar(query);  
    std::string resultQuery = executa(queryChar);

    return resultQuery;
}

//Esse m�todo monta as instru��es sql para inserir o log no banco de dados
//A instru��o � montada de acordo com o valor de option
std::string AccessControl::sqlLog(std::string text, int option){
    std::string query;
    
    switch (option){
        case 1:
            //come�a a sql de inserir at� o idAcao 
            query = "INSERT INTO acao(idAcao, idDescAcao, idUser, data, hora) VALUES (NULL, " + text + ", ";
            //Como a instru��o sql ainda n�o est� completa ela � armazenada temporariamente nesse vari�vel
            logString = query;
            break;
        case 2:
            //coloca o idUser, a data e a hora
            //Hora e data atual do sistema
            char dateStr [9];
            char timeStr [9];
            _strdate(dateStr);
            _strtime(timeStr);
            //Monta instru��o sql
            //Soma a instru��o tempor�ria armazenada, o idUser que foi passado no par�metro text, a data e a hora atuais            
            query = logString + text + ", '" + dateStr + "', '" + timeStr + "');";
            break;
        case 3:
            //insere na tabela de log a acao executada
            //text � o idAcao
            query = "INSERT INTO log(idLog, idAcao) VALUES (NULL, " + text + ");";
            break;
        case 4:
            //seleciona o id da a��o executada
            query = "SELECT idDescAcao from descAcao WHERE descricao = '" + text + "';";
            break;
        case 5:
            //seleciona o id da �ltima a��o adicionada ao bd  
            query = "SELECT MAX(idAcao) from acao;";
            break;  
        case 6:
            //Seleciona o idAcao do �ltimo a��o executada (identificada no text)
            query = "SELECT MAX(idAcao) from acao WHERE idDescAcao = " + text + ";";
            break;
        case 7:
            //Seleciona o id do usu�rio que fez o ultimo login
            query = "SELECT idUser FROM acao WHERE idAcao = " + text + ";";    
    }
    //retorna instru��o sql pronta
    return query; 
}

//Esse m�todo insere o log das a��es executadas no banco de dados
void AccessControl::log(int option){
    std::string query;
    const char *queryChar;
    std::string idDescAcao;
    
    if(option == 1)
        //op��o == 1 armazena login
        //Monta sql para pegar id do login
        query = sqlLog("login", 4);
    else if(option == 2){
        //op��o == 2 armazena logout        
        
        //recebe o idAcao do ultimo login executado
        query = sqlLog("1",6);
        queryChar = convertToChar(query);
        std::string idAcao = executa(queryChar);
        //recebe o id do usu�rio que executou o �ltimo login
        query = sqlLog(idAcao,7);
        queryChar = convertToChar(query);
        idUser = executa(queryChar);
        
        //Monta sql para encontrar id do logout 
        query = sqlLog("logout", 4); 
        }
        
    //pega id da a��o realizada    
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
