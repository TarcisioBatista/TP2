#ifndef _MAINAPP_H
#define _MAINAPP_H

#include <wx/wx.h> 

//Essa classe irá iniciar a aplicação por meio do método OnInit
class MainApp : public wxApp {   
    public:
        virtual bool OnInit();      
};

DECLARE_APP(MainApp) 
#endif _MAINAPP_H
