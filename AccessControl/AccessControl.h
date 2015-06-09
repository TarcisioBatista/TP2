#ifndef _ACCESSCONTROL_H
#define _ACCESSCONTROL_H

#include <wx/wx.h>
#include <wx/sqlite3.h>
#include <stdio.h>

class AccessControl{
    public:
        AccessControl();
        
        //M�todos para abrir e fechar conex�o com bd
        void open_bd();
        void close_bd();
        
        //M�todo para inserir dados de usu�rio
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
