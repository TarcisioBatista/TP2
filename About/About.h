#ifndef _ABOUT_H
#define _ABOUT_H

#include <wx/wx.h>

//Essa classe implementa a janela "Sobre", na opção do menu ou na toolbar
class About: public wxDialog{
    public:
        //Construtur
        About(wxWindow *parent);
        //Setar texto about
        void SetText(const wxString& text);
        
    private:
        wxStaticText *m_InfoText;
        wxButton *Ok_Button;
};


#endif
