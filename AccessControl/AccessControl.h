#ifndef _ACCESSCONTROL_H
#define _ACCESSCONTROL_H

#include <wx/wx.h>
#include <wx/wx.h>
#include <wx/sqlite3.h>
#include <stdio.h>
#include  <string.h>

//Essa classe faz o controle de acesso ao programa por meio de logins e senhas
//Por enquanto apenas armazena logins e senhas no bd, nada mais.
class AccessControl{
    public:
        //Construtor
        AccessControl();
        //Destrutor
        ~AccessControl();

        //M�todos para abrir e fechar conex�o com bd
        void open_bd();
        void close_bd();

        //M�todo para executar instru��es sql
        std::string executa(const char *sql);

        //M�todo para fazer hash nas senhas de usu�rio
        void createHash();

        //M�todos para convers�o entre tipos
        std::string convertToString(wxString text);
        std::string convertToString1(const char* text);
        wxString convertTowxString(std::string text);
        const char *convertToChar(std::string text);

        //M�todo para criar consulta sql
        std::string createQuery(std::string field, int option);
        
        //M�todo que verifica se o login digitado confere com o armazenado no bd
        std::string checkLogin(wxString text, int option);

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
