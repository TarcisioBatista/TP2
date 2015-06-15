#include "MainApp.h"
#include "Constant.h"
#include "../Frame/MainFrame.h"
#include "../SplashScreen/SplashScreen.h"

IMPLEMENT_APP(MainApp)
  
//O método OnInit inicia com a splash screen em seguida abre a tela de login.
//caso o login tenha sucesso o a frame sera aberta de dentro da classe login frame.
bool MainApp::OnInit(){
    
    //colocando o idioma padrão portugues
    SetLanguage(wxLANGUAGE_PORTUGUESE_BRAZILIAN);
    //Frame de login 
    LoginFrame *lframe = new LoginFrame(_("Login"));
    lframe->Centre();
    lframe->Show(true);
    SplashScreen *SS;
    SS->SetSS("../../Images/splash.bmp");  
    return true;                                  
};

//metodo para recriar a aplicação, util pois após o locale ter sido escolhido
//é necessário recriar a frame.
void MainApp::RecreateGUI(){
    wxWindow * topwindow = GetTopWindow();
    if(topwindow)
    {
        //destruindo a janela principal
        SetTopWindow(NULL);
        topwindow->Destroy();
    }
    //criando nova frame
    MainFrame *frame = new MainFrame(wxT("TP2 - PAC"),posMain, sizeMain);
    frame->Show(true);
    frame->Centre();
}

void MainApp::SetLanguage(wxLanguage language){
     if(wxLocale::IsAvailable(language)){
        
        //locale recebendo nova linguagem
        locale = new wxLocale(language);
        // aicionando os caminos de busca do locale
        locale->AddCatalogLookupPathPrefix(wxT("./Languages"));
        locale->AddCatalogLookupPathPrefix(wxT("../../Languages"));
        locale->AddCatalog(wxT("myapp"));
    } 
}


