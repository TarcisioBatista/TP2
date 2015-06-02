#include "MainFrame.h"
#include "../Menu/Menu.h"
#include "../ToolBar/ToolBar.h"

//Construtor da Frame
MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size) 
                :wxFrame(NULL, wxID_ANY, title, pos, size){
    
    //Criação do Menu
    Menu *MenuBar = new Menu();
    SetMenuBar(MenuBar);
    Centre();
    
    // connectando eventos de menu da frame aos "handlers" da classe menu
    Connect(ID_NEW, wxEVT_COMMAND_MENU_SELECTED,
      wxCommandEventHandler(Menu::OnNew)); 
    Connect(ID_SAVE, wxEVT_COMMAND_MENU_SELECTED,
      wxCommandEventHandler(Menu::OnSave));   
    Connect(ID_PORTUGUESE, wxEVT_COMMAND_MENU_SELECTED,
      wxCommandEventHandler(Menu::OnPortuguese));       
    Connect(ID_ENGLISH, wxEVT_COMMAND_MENU_SELECTED,
      wxCommandEventHandler(Menu::OnEnglish));       
    Connect(wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED,
      wxCommandEventHandler(Menu::OnExit));   
    Connect(wxID_ABOUT, wxEVT_COMMAND_MENU_SELECTED,
      wxCommandEventHandler(Menu::OnAbout));
      
    //Setando o ícone
    SetIcon(wxIcon(wxString(_T("/../Images/Icones/icone"), wxBITMAP_TYPE_BMP)));
    
    //Criando barra de ferramentas
    m_toolbar = CreateToolBar(wxTB_FLAT | wxTB_HORIZONTAL | wxTB_TEXT,wxID_ANY);   
    
    m_toolbar->AddTool(ID_NEWTOOLS, wxString(wxT("Novo")), wxBitmap(wxT("../../Images/Icones/newfile.bmp"), wxBITMAP_TYPE_BMP), wxString(wxT("Novo")));
    m_toolbar->AddTool(ID_SAVETOOLS, wxString(wxT("Salvar")), wxBitmap(wxT("../../Images/Icones/save.bmp"), wxBITMAP_TYPE_BMP), wxString(wxT("Salvar")));
    m_toolbar->AddTool(ID_OPENTOOLS, wxString(wxT("Abrir")), wxBitmap(wxT("../../Images/Icones/open.bmp"), wxBITMAP_TYPE_BMP), wxString(wxT("Abrir")));
    
    m_toolbar->AddSeparator();
    
    m_toolbar->AddTool(ID_HELPTOOLS, wxString(wxT("Ajuda")), wxBitmap(wxT("../../Images/Icones/help.bmp"), wxBITMAP_TYPE_BMP), wxString(wxT("Ajuda")));
    m_toolbar->AddTool(ID_CLOSETOOLS, wxString(wxT("Sair")), wxBitmap(wxT("../../Images/Icones/close.bmp"), wxBITMAP_TYPE_BMP), wxString(wxT("Sair")));

    m_toolbar->Realize();
    
    SetToolBar(m_toolbar);
    
};
