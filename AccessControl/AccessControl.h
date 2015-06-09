#ifndef _ACCESSCONTROL_H
#define _ACCESSCONTROL_H

#include <wx/wx.h>
#include <wx/sqlite3.h>
#include <stdio.h>

class AccessControl{
    public:
        AccessControl();
        
        //M�todos para abrir e fechar conex�o com bd
        int open_bd();
        int close_bd();
        
        //M�todo para inserir dados de usu�rio
        int insere(); 
        
    private:
        //bd
        sqlite3 *db;
        //constante para receber retorno da abertura do bd
        int rc;
        //string para fazer querys
        char *sql;  
        //msg de erro
        char *zErrMsg;
};


#endif
