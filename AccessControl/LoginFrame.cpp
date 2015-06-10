//ja existe esse loginframe na mainapp.h, inclusive ele nao sai de lá, se tirar da pau kkk
//#include "LoginFrame.h"
#include "../App/MainApp.h"

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
                   
}
//Esse método verifica se o usuário digitou o login e senha corretos, e só "entra"
//no software se esses dados estiverem corretos
void LoginFrame::entrar(wxCommandEvent &event){
    //Verificar se o usuário digigou valores nas caixas de texto.
    //Se não tiver digitado, aviso. Se tiver digitado, continua execução
    if(login->IsEmpty() || password->IsEmpty())
        wxMessageBox( _("Por favor, preencha todos os campos!"),_("Aviso"), wxOK | wxICON_INFORMATION );
    else{   
        //receber valores das caixas de texto
        loginCurrent = login->GetValue();
        passwordCurrent = password->GetValue();
        //verificar login
        if(confirmLogin(loginCurrent, passwordCurrent)){
            //Se o login estiver correto, fecha frame de login e abre frame principal
             Close(true);
            //Frame principal 
            wxGetApp().RecreateGUI();  
        }
        else {
            //se o login não estiver correto, mostra mensagem de erro e limpa os campos de digitação
            wxMessageBox(_( "Login ou senha incorretos!"),_("Aviso"), wxOK | wxICON_INFORMATION );
            login->Clear();
            password->Clear();
        }
    }
}
//Esse método fecha a frame de login
void LoginFrame::cancel(wxCommandEvent &event){
    Close( true );   
}
//Esse método verifica se o login digitado está correto e armazenado no bd.
//Se estiver retorna true, se não estiver retorna false.
bool LoginFrame::confirmLogin(wxString user, wxString pass){
    std::string userString = acc.convertToString(user);
    
    //Verifica o login correpondente a senha digitada no banco de dados
    std::string loginbd = acc.checkLogin(pass);
    
    //Se o login for igual ao digitado, login correto e retorna true
    if(userString == loginbd)    
        return true;
    //se não for igual, login ou senha incorretos e retorna false    
    else return false;   
}


