#ifndef _ACCESSCONTROL_H
#define _ACCESSCONTROL_H

#include <wx/wx.h>
#include <wx/sqlite3.h>
#include <stdio.h>

//Essa classe faz o controle de acesso ao programa por meio de logins e senhas
//Por enquanto apenas armazena logins e senhas no bd, nada mais.
class AccessControl{
    public:
        //Construtor
        AccessControl();
        
        //M�todos para abrir e fechar conex�o com bd
        void open_bd();
        void close_bd();
        
        //M�todo para executar instru��es sql
        void executa(char *sql); 
        
        void insere();
          
        
    private:
        //bd
        sqlite3 *db;
        //constante para receber retorno das execu��es de sqls
        int rc;  
        //msg de erro
        char *err_msg;
        //Cbjeto para converter sql em uma instru��o preparada antes de ser executada
        sqlite3_stmt *statement;
};


#endif
