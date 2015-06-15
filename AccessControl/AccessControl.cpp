#include "AccessControl.h"

AccessControl::AccessControl(){
    //abrir bd
    open_bd();
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

//Esse m�todo executa uma sql no banco de dados
std::string AccessControl::executa(const char *sql){
    std::string result;  
    
    //prepara sql para ser executada
    rc = sqlite3_prepare_v2(db, sql , -1, &statement, 0);    
    if(rc != SQLITE_OK)
       wxMessageBox( _("Erro na conex�o com banco de dados!"),_("Erro"), wxOK | wxICON_INFORMATION );
    
    //executa sql
    rc = sqlite3_exec(db,sql,0,0,&err_msg);
    if(rc != SQLITE_OK)
        wxLogMessage(err_msg, _("Erro"), wxOK | wxICON_INFORMATION);
        
    //receber resultado da consulta
    rc = sqlite3_step(statement);
    if(rc ==  SQLITE_ROW)
        result = (char*)sqlite3_column_text(statement, 0);
    else
        result = "falha";    
    sqlite3_finalize(statement);
    
    return result;
}

void AccessControl::createHash(){
    
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

//Esse m�todo monta uma consulta sql com a vari�vel passada como par�metro
//a op��o indica qual consulta ser� feita.
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

//Esse m�todo converte uma string para um char*
const char *AccessControl::convertToChar(std::string text){
    const char *result = text.c_str();
    return result;
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
//Destrutor
AccessControl::~AccessControl(){
    //fecha bd
    close_bd();   
}
