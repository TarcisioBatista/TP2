#include <wx/html/helpctrl.h>

class Help: public wxHtmlHelpController{
	    public:
            // Constructor
            Help(wxWindow *parent);
        private:
            wxHtmlHelpController *helpController;                    
};


