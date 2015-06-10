#ifndef _LOGINFRAME_H
#define _LOGINFRAME_H

#include <wx/wx.h>
#include "../AccessControl/AccessControl.h"
#include "../Frame/MainFrame.h"
#include <string.h>
#include <stdio.h>

//Essa classa implementa uma janela de login que � aberta ao iniciar a aplica��o
class LoginFrame: public wxFrame{
    public:
        //Construtor
        LoginFrame(const wxString &name); 
        
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
        std::string createQuery(std::string field);
        //M�todo que verifica se o login digitado confere com o armazenado no bd
        std::string checkLogin(wxString pass);
          
        //bd
        sqlite3 *db;
        //constante para receber retorno das execu��es de sqls
        int rc;  
        //msg de erro
        char *err_msg;
        //Cbjeto para converter sql em uma instru��o preparada antes de ser executada
        sqlite3_stmt *statement;
        
        
    private:
        //Caixas de texto para login e senha
        wxTextCtrl *login;
        wxTextCtrl *password;
        
        //Textos
        wxStaticText *txlogin;
        wxStaticText *txpassword;
        
        //Bot�es
        wxButton *btLogin;
        wxButton *btCancel; 
        
        //Vari�veis para armazenar o login e a senha atuais
        wxString loginCurrent;
        wxString passwordCurrent;
        
        void entrar(wxCommandEvent &event);
        void cancel(wxCommandEvent &event);
        bool confirmLogin(wxString user, wxString pass);
        
        //Objeto de controle de acesso
        AccessControl acc;
    
};


#endif
