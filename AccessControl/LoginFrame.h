#ifndef _LOGINFRAME_H
#define _LOGINFRAME_H

#include <wx/wx.h>
#include "../AccessControl/AccessControl.h"
#include "../Frame/MainFrame.h"
//#include "../App/Constant.h"

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
        
        void entrar(wxCommandEvent &event);
        void cancel(wxCommandEvent &event);
        bool checkLogin(wxString user, wxString pass);
    
};


#endif
