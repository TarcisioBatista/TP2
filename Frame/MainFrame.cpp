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
    
};
