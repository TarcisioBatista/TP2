#include "ToolBar.h"


ToolBar::ToolBar()
            :wxToolBar(){
    
    //Criar barra de ferramentas
    m_toolbar = new wxToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_TEXT);
    
    //Imagens da toolbar
    newfile.LoadFile("../../Images/Icones/newfile.bmp");
    //savefile.LoadFile("../../Images/Icones/open.bmp");
    
    //Setando botões
    m_toolbar->AddTool(ID_NEWTOOLS, wxString(wxT("Novo")), newfile, wxString(wxT("Novo")));
    m_toolbar->AddTool(ID_SAVETOOLS, wxString(wxT("Salvar")), wxBitmap(wxT("../../Images/Icones/save.bmp"), wxBITMAP_TYPE_BMP), wxString(wxT("Salvar")));
    m_toolbar->AddTool(ID_OPENTOOLS, wxString(wxT("Abrir")), wxBitmap(wxT("../../Images/Icones/open.bmp"), wxBITMAP_TYPE_BMP), wxString(wxT("Abrir")));
    
    m_toolbar->AddSeparator();
    
    m_toolbar->AddTool(ID_HELPTOOLS, wxString(wxT("Ajuda")), wxBitmap(wxT("../../Images/Icones/help.bmp"), wxBITMAP_TYPE_BMP), wxString(wxT("Ajuda")));
    m_toolbar->AddTool(ID_CLOSETOOLS, wxString(wxT("Sair")), wxBitmap(wxT("../../Images/Icones/close.bmp"), wxBITMAP_TYPE_BMP), wxString(wxT("Sair")));

    //m_toolbar->Realize();
};
