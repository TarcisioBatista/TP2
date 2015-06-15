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
    
    //Bot�es
    btLogin = new wxButton(painel, 1000, wxT("Entrar"));
    Connect(1000, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(LoginFrame::entrar));
    btCancel = new wxButton(painel, 1001, wxT("Cancelar"));
    Connect(1001, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(LoginFrame::cancel));
    
    //Colocando caixas de texto e bot�es no boxsizer
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
//Esse m�todo verifica se o usu�rio digitou o login e senha corretos, e s� "entra"
//no software se esses dados estiverem corretos
void LoginFrame::entrar(wxCommandEvent &event){
    //Verificar se o usu�rio digigou valores nas caixas de texto.
    //Se n�o tiver digitado, aviso. Se tiver digitado, continua execu��o
    if(login->IsEmpty() || password->IsEmpty())
        wxMessageBox( _("Por favor, preencha todos os campos!"),_("Aviso"), wxOK | wxICON_INFORMATION );
    else{   
        //receber valores das caixas de texto
        loginCurrent = login->GetValue();
        passwordCurrent = password->GetValue();
        //verificar login
        if(confirmLogin(loginCurrent, passwordCurrent)==true){
            //Se o login estiver correto, fecha frame de login e abre frame principal
             Close(true);
            //Frame principal 
            wxGetApp().RecreateGUI();  
        }
        else {
            //se o login n�o estiver correto, mostra mensagem de erro e limpa os campos de digita��o
            wxMessageBox(_( "Login ou senha incorretos!"),_("Aviso"), wxOK | wxICON_INFORMATION );
            login->Clear();
            password->Clear();
        }
    }
}
//Esse m�todo fecha a frame de login
void LoginFrame::cancel(wxCommandEvent &event){
    Close( true );   
}
//Esse m�todo verifica se o login e a senha digitados est�o corretos
//Se estiver retorna true, se n�o estiver retorna false.
bool LoginFrame::confirmLogin(wxString user, wxString pass){
    std::string userString = acc.convertToString(user);
    std::string passString = acc.convertToString(pass);
    
    //Verifica o id do login e o id da senha
    std::string idpassword = acc.checkLogin(passString,1);
    std::string  idlogin = acc.checkLogin(userString,2);
    
    //Se algum dos dois id's for igual a zero quer dizer que n�o foi encontrado no bd
    if(idpassword == "0" || idlogin == "0")
        return false;
    //Se o id do login for igual ao id da senha, login correto e retorna true     
    if(idpassword == idlogin){ 
        acc.idUser = idpassword;
        acc.log(1);   
        return true;
    }
    //se n�o for igual, login ou senha n�o correspondem no bd e retorna false    
    else return false;   
}


