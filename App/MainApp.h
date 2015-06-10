#ifndef _MAINAPP_H
#define _MAINAPP_H

#include<wx/wxprec.h>
#ifdef WX_PRECOMP
#include <wx/wx.h>
#include <wx/intl.h>
#endif
#include "../AccessControl/LoginFrame.h"
 
//Essa classe irá iniciar a aplicação por meio do método OnInit
class MainApp : public wxApp {   
    public:
        virtual bool OnInit();
        void RecreateGUI();
        void SetLanguage(wxLanguage language);
    private:
        wxLocale* locale;
        wxLanguage language;   
};

DECLARE_APP(MainApp)
#endif
