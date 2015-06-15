#ifndef _LOGINFRAME_H
#define _LOGINFRAME_H

#include <wx/wx.h>
#include "../AccessControl/AccessControl.h"
#include "../Frame/MainFrame.h"
#include <string.h>
#include <stdio.h>

//Essa classa implementa uma janela de login que é aberta ao iniciar a aplicação
class LoginFrame: public wxFrame{
    public:
        //Construtor
        LoginFrame(const wxString &name); 
        
        
    private:
        //Caixas de texto para login e senha
        wxTextCtrl *login;
        wxTextCtrl *password;
        
        //Textos
        wxStaticText *txlogin;
        wxStaticText *txpassword;
        
        //Botões
        wxButton *btLogin;
        wxButton *btCancel; 
        
        //Variáveis para armazenar o login e a senha atuais
        wxString loginCurrent;
        wxString passwordCurrent;
        
        void entrar(wxCommandEvent &event);
        void cancel(wxCommandEvent &event);
        bool confirmLogin(wxString user, wxString pass);
        
        //Objeto de controle de acesso
        AccessControl acc;
    
};


#endif
