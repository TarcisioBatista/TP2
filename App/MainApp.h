#ifndef _MAINAPP_H
#define _MAINAPP_H

#include<wx/wxprec.h>
#ifdef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "../AccessControl/LoginFrame.h"
 

//Essa classe irá iniciar a aplicação por meio do método OnInit
class MainApp : public wxApp {   
    public:
        virtual bool OnInit();      
};

DECLARE_APP(MainApp) 
#endif
