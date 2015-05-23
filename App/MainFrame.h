#ifndef _MAINFRAME_H
#define _MAINFRAME_H

#include <wx/wx.h>
#include "../Menu/Menu.h"

//Esta classe gerencia todos os métodos que atuam no frame.
class MainFrame: public wxFrame{    
    public:
        // Constructor
        MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
        Menu *menuBar;       
};


#endif
