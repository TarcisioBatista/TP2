#ifndef _MAINAPP_H
#define _MAINAPP_H

#include "Constant.h"
#include "MainFrame.h"

//Essa classe ir� iniciar a aplica��o por meio do m�todo OnInit
class MainApp : public wxApp {   
    public:
        virtual bool OnInit();      
};

DECLARE_APP(MainApp) 
#endif
