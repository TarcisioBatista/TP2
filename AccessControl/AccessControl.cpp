#include "AccessControl.h"

AccessControl::AccessControl(){
    //abrir bd
    if(open_bd())
        wxMessageBox( "Erro ao abri banco de dados!","Erro", wxOK | wxICON_INFORMATION );
    
    insere();    
    
    
    
    
    //fecha bd
    close_bd();
}

//Esse m�todo abre a conex�o com o banco de dados
int AccessControl::open_bd(){
    rc = sqlite3_open("bdtp2.db", &db);
    return rc;
}
//Esse m�todo fecha a conex�o com o bando de dados
int AccessControl::close_bd(){
    sqlite3_close(db);    
}

int AccessControl::insere(){

}
