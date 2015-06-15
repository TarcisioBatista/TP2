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
        
        //M�todos de tratamento dos eventos de clique nos bot�es entrar e cancelar
        void entrar(wxCommandEvent &event);
        void cancel(wxCommandEvent &event);
        
        //M�todo para confirmar se o login e senha digitados est�o corretos
        bool confirmLogin(wxString user, wxString pass);       
        
        //Objeto de controle de acesso
        AccessControl acc;        
    
};


#endif
