#include "MainApp.h"

IMPLEMENT_APP(MainApp)  

bool MainApp::OnInit(){
    
     MainFrame *frame = new MainFrame(nameMain, posMain, sizeMain);
    
    return true;                                  
};
