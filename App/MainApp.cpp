#include "MainApp.h"
#include "Constant.h"
#include "../Frame/MainFrame.h"
#include "../SplashScreen/SplashScreen.h"

IMPLEMENT_APP(MainApp)
  
//O método OnInit cria uma frame na tela com os dados dos menus e barras de ferramentas.
//Também cria a frame inicial de login no sistema
bool MainApp::OnInit(){
    
    //Frame de login 
    SetLanguage(wxLANGUAGE_PORTUGUESE_BRAZILIAN);
    LoginFrame *lframe = new LoginFrame(_("Login"));
    lframe->Centre();
    lframe->Show(true);
    SplashScreen *SS;
    SS->SetSS();  
    return true;                                  
};

void MainApp::RecreateGUI(){
    wxWindow * topwindow = GetTopWindow();
    if(topwindow)
    {
        SetTopWindow(NULL);
        topwindow->Destroy();
    }
    MainFrame *frame = new MainFrame(wxT("TP2 - PAC"),posMain, sizeMain);
    frame->Show(true);
    frame->Centre();
}

void MainApp::SetLanguage(wxLanguage language){
    // carrega outra lingua se possivel, se nÃ£o volta para a lingua padrÃ£o
     if(wxLocale::IsAvailable(language)){
        
        locale = new wxLocale(language);
        // add locale search paths
        locale->AddCatalogLookupPathPrefix(wxT("./Languages"));
        locale->AddCatalogLookupPathPrefix(wxT("../../Languages"));
        locale->AddCatalog(wxT("myapp"));
    } 
}


