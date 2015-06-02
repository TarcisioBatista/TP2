#ifndef _MAINFRAME_H
#define _MAINFRAME_H

#include <wx/wx.h>


//Esta classe gerencia todos os métodos que atuam no frame.
class MainFrame: public wxFrame{    
    public:
        // Constructor
        MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
        
        wxToolBar *m_toolbar;
        
        enum{
            ID_NEWTOOLS,
            ID_SAVETOOLS,
            ID_OPENTOOLS,
            ID_HELPTOOLS,
            ID_CLOSETOOLS                          
        };
             
};


#endif
