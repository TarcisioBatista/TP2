#include "Menu.h"

BEGIN_EVENT_TABLE(Menu, wxMenuBar)
    EVT_MENU(ID_NEW, Menu::OnNew)
    EVT_MENU(ID_SAVE, Menu::OnSave)
    EVT_MENU(ID_PORTUGUESE, Menu::OnPortuguese)
    EVT_MENU(ID_ENGLISH, Menu::OnEnglish)
    EVT_MENU(wxID_EXIT, Menu::OnExit)
    EVT_MENU(wxID_ABOUT, Menu::OnAbout)
END_EVENT_TABLE()
   
Menu::Menu()
        :wxMenuBar(){
    
    //menu arquivo -> novo - salvar - sair            
    FileMenu = new wxMenu();
	FileMenu->Append(ID_NEW, "&Novo", "Novo");
	FileMenu->Append(ID_SAVE, "&Salvar", "Salvar");
	FileMenu->AppendSeparator();
	FileMenu->Append(wxID_EXIT, "&Sair", "Sair");
	this->Append(FileMenu, "&Arquivo");
	
	// Menu Ferramentas -> idiomas ->portugues - ingles
    ToolsMenu = new wxMenu();
    ToolsMenu->AppendSubMenu(LanguagesSubMenu, "&Idiomas", "idiomas");
    LanguagesSubMenu->Append(ID_PORTUGUESE, "&Português", "Traduzir para o Portugês");
    LanguagesSubMenu->Append(ID_ENGLISH, "&English", "Translate to English");
    this->Append(ToolsMenu, "Ferramentas");
	
	// Menu About - About
	AboutMenu = new wxMenu();
	AboutMenu->Append(wxID_ABOUT, "&About", "Exibe informações");
    this->Append(AboutMenu, "&About");       
        
}    
    
void Menu::OnNew(wxCommandEvent& event){
        wxMessageBox( "testando tratamento de eventos1",
            "sobre", wxOK | wxICON_INFORMATION );
}
void Menu::OnSave(wxCommandEvent& event){
        wxMessageBox( "testando tratamento de eventos2",
            "sobre", wxOK | wxICON_INFORMATION );
}
void Menu::OnPortuguese(wxCommandEvent& event){
        wxMessageBox( "testando tratamento de eventos3",
            "sobre", wxOK | wxICON_INFORMATION );
}
void Menu::OnEnglish(wxCommandEvent& event){
        wxMessageBox( "testando tratamento de eventos4",
            "sobre", wxOK | wxICON_INFORMATION );
}
void Menu::OnExit(wxCommandEvent& event)
{
    Close( true );
}
void Menu::OnAbout(wxCommandEvent& event)
{
    wxMessageBox( "Este sotware foi desenvovido por Tarcisio Batista",
            "sobre", wxOK | wxICON_INFORMATION );
}
