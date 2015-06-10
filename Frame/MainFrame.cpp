#include "MainFrame.h"
#include "../Menu/Menu.h"

//Construtor da Frame
MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size) 
                :wxFrame(NULL, wxID_ANY, title, pos, size){
    
    //Criação do Menu
    Menu *MenuBar = new Menu();
    SetMenuBar(MenuBar);
    Centre();
    
    // connectando eventos de menu da frame aos "handlers" da classe menu

      
    //Setando o ícone
    SetIcon(wxIcon(wxString(_T("/../Images/Icones/icone"), wxBITMAP_TYPE_BMP)));
    
    //Criando barra de ferramentas
    m_toolbar = CreateToolBar(wxTB_FLAT | wxTB_HORIZONTAL | wxTB_TEXT,wxID_ANY);   
    
    m_toolbar->AddTool(ID_NEW, wxString(wxT("Novo")), wxBitmap(wxT("../../Images/Icones/newfile.bmp"), wxBITMAP_TYPE_BMP), wxString(wxT("Novo")));
    m_toolbar->AddTool(ID_SAVE, wxString(wxT("Salvar")), wxBitmap(wxT("../../Images/Icones/save.bmp"), wxBITMAP_TYPE_BMP), wxString(wxT("Salvar")));
    m_toolbar->AddTool(ID_OPEN, wxString(wxT("Abrir")), wxBitmap(wxT("../../Images/Icones/open.bmp"), wxBITMAP_TYPE_BMP), wxString(wxT("Abrir")));
    
    m_toolbar->AddSeparator();
    
    m_toolbar->AddTool(ID_HELP, wxString(wxT("Ajuda")), wxBitmap(wxT("../../Images/Icones/help.bmp"), wxBITMAP_TYPE_BMP), wxString(wxT("Ajuda")));
    m_toolbar->AddTool(wxID_EXIT, wxString(wxT("Sair")), wxBitmap(wxT("../../Images/Icones/close.bmp"), wxBITMAP_TYPE_BMP), wxString(wxT("Sair")));

    //Para atualizar a barra de ferramentas com os ícones bitmap
    m_toolbar->Realize();
    
    //Setanto barra de ferramentas
    SetToolBar(m_toolbar);

    //Barra de Status
    CreateStatusBar(3);
    SetStatusText("TP2 PAC", 0);
    
    Connect(ID_NEW, wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(Menu::OnNew)); 
    Connect(ID_OPEN, wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(Menu::OnOpen));
    Connect(ID_SAVE, wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(Menu::OnSave));   
    Connect(ID_HELP, wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(Menu::OnHelp));
    Connect(ID_PORTUGUESE, wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(Menu::OnPortuguese));       
    Connect(ID_ENGLISH, wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(Menu::OnEnglish));       
    Connect(wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(Menu::OnExit));   
    Connect(wxID_ABOUT, wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(Menu::OnAbout));
    
    

};
