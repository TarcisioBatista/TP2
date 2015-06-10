#include<wx/wxprec.h>
#ifdef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <wx/intl.h>
#include "../AccessControl/LoginFrame.h"


//Essa classe irá iniciar a aplicação por meio do método OnInit
class MainApp : public wxApp {   
    public:
        virtual bool OnInit();
        void RecreateGUI();
        void SetLanguage(wxLanguage language);
    private:
        wxLocale* locale;
        
        
};
DECLARE_APP(MainApp)
