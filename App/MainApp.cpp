#include "MainApp.h"

IMPLEMENT_APP(MainApp)
  
//O método OnInit cria uma frame na tela com os dados dos menus e barras de ferramentas.
bool MainApp::OnInit(){
    
     MainFrame *frame = new MainFrame(nameMain, posMain, sizeMain);
     frame->Show(true);                                 
     SetTopWindow(frame);
    
    return true;                                  
};
