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

        //Métodos para abrir e fechar conexão com bd
        void open_bd();
        void close_bd();

        //Método para executar instruções sql
        std::string executa(const char *sql);

        //Método para fazer hash nas senhas de usuário
        void createHash();

        //Métodos para conversão entre tipos
        std::string convertToString(wxString text);
        std::string convertToString1(const char* text);
        wxString convertTowxString(std::string text);
        const char *convertToChar(std::string text);

        //Método para criar consulta sql
        std::string createQuery(std::string field, int option);
        
        //Método que verifica se o login digitado confere com o armazenado no bd
        std::string checkLogin(wxString text, int option);

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
