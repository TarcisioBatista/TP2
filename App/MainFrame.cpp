#include "MainFrame.h"

//Construtor da Frame
MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size) 
                :wxFrame(NULL, wxID_ANY, title, pos, size){
    
    //Cria��o do Menu
    //menuBar = new Menu();
    //this->SetMenuBar(menuBar);
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
    
};
