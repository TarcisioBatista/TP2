#ifndef _MAINAPP_H
#define _MAINAPP_H

#include <wx/wx.h> 

//Essa classe ir� iniciar a aplica��o por meio do m�todo OnInit
class MainApp : public wxApp {   
    public:
        virtual bool OnInit();      
};

DECLARE_APP(MainApp) 
#endif _MAINAPP_H
