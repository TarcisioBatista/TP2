#include "MainApp.h"

IMPLEMENT_APP(MainApp)
  
//O m�todo OnInit cria uma frame na tela com os dados dos menus e barras de ferramentas.
//Tamb�m cria a frame inicial de login no sistema
bool MainApp::OnInit(){    
 
    
    //Frame de login 
    LoginFrame *lframe = new LoginFrame(wxT("Login"));
    lframe->Show(true);
    SetTopWindow(lframe);                                
         
    return true;                                  
};
