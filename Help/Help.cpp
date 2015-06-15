#include "Help.h"

Help::Help(wxWindow *parent){
    wxHtmlHelpController *helpController = new wxHtmlHelpController(wxHF_DEFAULT_STYLE,parent);	
	helpController->AddBook("../../Help/help/unnamed.hhp", false);
	helpController->Display("../../Help/help/doc-0003.htm");
}
