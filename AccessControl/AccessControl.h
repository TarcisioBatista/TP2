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
        
        //Métodos para abrir e fechar conexão com bd
        void open_bd();
        void close_bd();
        
        //Método para executar instruções sql
        void executa(char *sql); 
        
        void insere();
          
        
    private:
        //bd
        sqlite3 *db;
        //constante para receber retorno das execuções de sqls
        int rc;  
        //msg de erro
        char *err_msg;
        //Cbjeto para converter sql em uma instrução preparada antes de ser executada
        sqlite3_stmt *statement;
};


#endif
