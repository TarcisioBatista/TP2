#ifndef _ACCESSCONTROL_H
#define _ACCESSCONTROL_H

#include <wx/wx.h>
#include <wx/sqlite3.h>
#include <stdio.h>

class AccessControl{
    public:
        AccessControl();
        
        //Métodos para abrir e fechar conexão com bd
        void open_bd();
        void close_bd();
        
        //Método para inserir dados de usuário
        void executa(); 
          
        
    private:
        //bd
        sqlite3 *db;
        //constante para receber retorno da abertura do bd
        int rc;  
        //msg de erro
        char *err_msg;
        sqlite3_stmt *statement;
};


#endif
