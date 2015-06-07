#include "About.h"

About::About(wxWindow *parent)
            : wxDialog(parent, -1, "TP2 - PAC", wxDefaultPosition, wxSize(200, 200), 
            wxDEFAULT_DIALOG_STYLE){
    
    //Constrói Dialog
    SetAutoLayout(TRUE);
    
    wxLayoutConstraints *layout = new wxLayoutConstraints();
    
    layout->top.SameAs(this, wxTop, 10);
    layout->centreX.SameAs(this, wxCentreX);
    layout->width.AsIs();
    layout->height.AsIs();
    
    m_InfoText = new wxStaticText(this, -1, "", wxPoint(-1, -1), wxDefaultSize, wxALIGN_CENTER);
    m_InfoText->SetConstraints(layout);
    
    layout = new wxLayoutConstraints();
    layout->top.Below(m_InfoText, 10);
    layout->centreX.SameAs(this, wxCentreX);
    layout->width.PercentOf(this, wxWidth, 80);
    layout->height.AsIs();
            
    //Botão Ok        
    Ok_Button = new wxButton(this, wxID_OK, "Ok", wxPoint(-1, -1));
    Ok_Button->SetConstraints(layout);
    
    Layout();                    
}

//Método que seta o texto que será mostrado na dialog sobre
void About::SetText(const wxString& text)
{
  m_InfoText->SetLabel(text);
  Layout();
}
