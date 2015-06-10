#include "MainApp.h"
#include "Constant.h"
#include "../Frame/MainFrame.h"
#include "../SplashScreen/SplashScreen.h"
#include "../Translation/Translation.h"

IMPLEMENT_APP(MainApp)
  
//O método OnInit cria uma frame na tela com os dados dos menus e barras de ferramentas.
//Também cria a frame inicial de login no sistema
bool MainApp::OnInit(){    
    //Frame de login 
//    LoginFrame *lframe = new LoginFrame(_("Login"));
//    lframe->Show(true);
//    SetTopWindow(lframe);
    Translation *T;
    T->SetLanguage(wxLANGUAGE_PORTUGUESE_BRAZILIAN); 
    RecreateGUI();
    SplashScreen* ss;
    ss->SetSS();
    return true;                                  
};

void MainApp::RecreateGUI(){
    wxWindow * topwindow = GetTopWindow();
    if(topwindow)
    {
        topwindow->Destroy();
    }
    MainFrame * frame = new MainFrame(wxT("TP2 - PAC"), posMain, sizeMain);
    frame->Centre();
    frame->Show();
}


