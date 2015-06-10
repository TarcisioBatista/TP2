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
    txlogin = new wxStaticText(painel, -1, wxT("Login:"));
    txpassword = new wxStaticText(painel, -1, wxT("Senha:"));
    
    //Botões
    btLogin = new wxButton(painel, 1000, wxT("Entrar"));
    Connect(1000, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(LoginFrame::entrar));
    btCancel = new wxButton(painel, 1001, wxT("Cancelar"));
    Connect(1001, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(LoginFrame::cancelar));
    
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

void LoginFrame::entrar(wxCommandEvent &event){
    wxMessageBox( "Teste OK! ","Teste", wxOK | wxICON_INFORMATION );
}

void LoginFrame::cancelar(wxCommandEvent &event){
    Close( true );   
}
