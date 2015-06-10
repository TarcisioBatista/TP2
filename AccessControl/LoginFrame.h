#ifndef _LOGINFRAME_H
#define _LOGINFRAME_H

#include <wx/wx.h>
#include "../AccessControl/AccessControl.h"

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
        
        void entrar(wxCommandEvent &event);
        void cancelar(wxCommandEvent &event);
    
};


#endif
