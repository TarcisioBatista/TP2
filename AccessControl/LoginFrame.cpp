#include "LoginFrame.h"

LoginFrame::LoginFrame(const wxString &name) 
            : wxFrame(NULL, -1, name, wxDefaultPosition, wxSize(290, 180)){
    
    //Criar painel e Boxsizers            
    wxPanel *painel = new wxPanel(this, -1);
    wxBoxSizer *boxprincipal = new wxBoxSizer(wxVERTICAL);
    wxGridSizer *boxtexto = new wxGridSizer(3, 2, 5, 5);
    wxBoxSizer *boxbotoes = new wxBoxSizer(wxHORIZONTAL);

    //Caixas de texto
    login = new wxTextCtrl(painel, -1, wxT(""));
    password = new wxTextCtrl(painel, -1, wxT(""));  
    txlogin = new wxStaticText(painel, -1, _("Login:"));
    txpassword = new wxStaticText(painel, -1, _("Senha:"));

    //Botões
    btLogin = new wxButton(painel, 1000, _("Entrar"));
    Connect(1000, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(LoginFrame::enter));

    btCancel = new wxButton(painel, 1001, wxT("Cancelar"));
    Connect(1001, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(LoginFrame::cancel));
    
    //Colocando caixas de texto e botões no boxsizer
    boxtexto->Add(txlogin, 1, wxALL, 10);
    boxtexto->Add(login, 1, wxALL, 5);
    boxtexto->Add(txpassword, 1, wxALL, 10);
    boxtexto->Add(password, 1, wxALL, 5);

    boxbotoes->Add(btLogin, 1, wxALL, 0);
    boxbotoes->Add(btCancel, 1, wxALL, 0);
    
    boxprincipal->Add(boxtexto, 1, wxEXPAND);
    boxprincipal->Add(boxbotoes, 1, wxEXPAND);
    
    //Colocar boxsizer principal no painel
    painel->SetSizer(boxprincipal);
    login->SetFocus();
    Centre();
    
    //Objeto de controle de acesso
    AccessControl acc;

                    
}

void LoginFrame::enter(wxCommandEvent &event){

    //Verificar se o usuário digigou valores nas caixas de texto.
    //Se não tiver digitado, aviso. Se tiver digitado, continua execução
    if(login->IsEmpty() || password->IsEmpty())
        wxMessageBox( "Por favor, preencha todos os campos!","Aviso", wxOK | wxICON_INFORMATION );
    else{   
        //receber valores das caixas de texto
        loginCurrent = login->GetValue();
        passwordCurrent = password->GetValue();
        //verificar login
        if(checkLogin(loginCurrent, passwordCurrent)){
            Close(true);
            //Frame principal
            MainFrame *frame = new MainFrame("TP2", wxPoint(-1,-1), wxSize(900,700));
            frame->Show(true);   
        }
        else {
            wxMessageBox( "Login ou senha incorretos!","Aviso", wxOK | wxICON_INFORMATION );
            login->Clear();
            password->Clear();
        }
    }
}
//Esse método fecha a frame de login
void LoginFrame::cancel(wxCommandEvent &event){
    Close( true );   
}
//Esse método verifica se o login digitadp está correto e armazenado no bd.
//Se estiver retorna true, se não estiver retorna false.
bool LoginFrame::checkLogin(wxString user, wxString pass){
    
    //return false;
    return true;   
}
