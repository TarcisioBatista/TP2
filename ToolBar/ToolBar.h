#ifndef _TOOLBAR_H
#define _TOOLBAR_H

#include <wx/wx.h>

class ToolBar: public wxToolBar{
    public:
        ToolBar();
        
        enum{
            ID_NEWTOOLS,
            ID_SAVETOOLS,
            ID_OPENTOOLS,
            ID_HELPTOOLS,
            ID_CLOSETOOLS                          
        };
        
        wxToolBar *m_toolbar;
        
        wxBitmap newfile, savefile, openfile, help, closefile;
};

#endif
