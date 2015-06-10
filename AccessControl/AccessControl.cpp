#include "AccessControl.h"

AccessControl::AccessControl(){
    //abrir bd
    open_bd();
    // executa();    
 
    //executa("INSERT INTO user(idUser, login, senha) VALUES (NULL, 'hugo.mendes', '123');");    
    
    createHash();
    //fecha bd
    close_bd();
}

//Esse método abre a conexão com o banco de dados
void AccessControl::open_bd(){
    rc = sqlite3_open("dbtp2.db3", &db);
    if(rc != SQLITE_OK)
        wxMessageBox( _("Erro ao abri banco de dados!"),_("Erro"), wxOK | wxICON_INFORMATION ); 
}
//Esse método fecha a conexão com o bando de dados
void AccessControl::close_bd(){
    sqlite3_close(db);    
}

//Esse método executa uma sql no banco de dados
void AccessControl::executa(char *sql){
    //prepara sql para ser executada
    rc = sqlite3_prepare_v2(db, sql, -1, &statement, 0);    
    if(rc != SQLITE_OK)
       wxMessageBox( _("Falha ao buscar dados!"),_("Erro"), wxOK | wxICON_INFORMATION );
    
    //executa sql
    rc = sqlite3_exec(db,sql,0,0,&err_msg);
    if(rc != SQLITE_OK)
        wxLogMessage(err_msg, _("Erro"), wxOK | wxICON_INFORMATION);

}

void AccessControl::insere(){
        
}

void AccessControl::createHash(){
}

