#include "Menu.h"
#include "../About/About.h"
   
Menu::Menu()
        :wxMenuBar(){
    
    //menu arquivo -> novo - salvar - sair            
    FileMenu = new wxMenu();
    	FileMenu->Append(ID_NEW, "&Novo", "Novo Arquivo");
    	FileMenu->Append(ID_OPEN, "&Abrir", "Abrir");
        FileMenu->Append(ID_SAVE, "&Salvar", "Salvar");
    	FileMenu->AppendSeparator();
    	FileMenu->Append(wxID_EXIT, "&Sair", "Sair");
    	this->Append(FileMenu, "&Arquivo");
	
	// Menu Ferramentas -> idiomas -> portugues - ingles
    ToolsMenu = new wxMenu();
    LanguagesSubMenu = new wxMenu();        
        LanguagesSubMenu->AppendRadioItem(ID_PORTUGUESE, "&Portugu�s", "Traduzir para o Portug�s");
        LanguagesSubMenu->AppendRadioItem(ID_ENGLISH, "&English", "Translate to English");
        ToolsMenu->AppendSubMenu(LanguagesSubMenu, "&Idiomas", "idiomas");
        this->Append(ToolsMenu, "Ferramentas");
        
	
	// Menu About - About - Help
	AboutMenu = new wxMenu();
    	AboutMenu->Append(wxID_ABOUT, "&Sobre", "Exibe informa��es sobre o software");
       	AboutMenu->Append(ID_HELP, "&Ajuda", "Abre a op��o de ajuda.");
        this->Append(AboutMenu, "&Sobre");       
        
}    

//M�todos de cada op��o do menu    
void Menu::OnNew(wxCommandEvent& event){
        wxMessageBox( "Um novo arquivo foi selecionado.",
            "Novo", wxOK | wxICON_INFORMATION );
}
void Menu::OnOpen(wxCommandEvent &event){
  wxFileDialog *dlg = new wxFileDialog(this, "Open a text file",
									   "", "", "All files(*.*)|*.*|Text Files(*.txt)|*.txt",
									   wxFD_OPEN, wxDefaultPosition);
  if ( dlg->ShowModal() == wxID_OK )
  {
	    wxMessageBox(dlg->GetPath(),"Salvar", wxOK | wxICON_INFORMATION );
  }
  dlg->Destroy();
}
void Menu::OnSave(wxCommandEvent& event){
        wxMessageBox( "O Arquivo foi salvo.",
            "Salvar", wxOK | wxICON_INFORMATION );
}
void Menu::OnPortuguese(wxCommandEvent& event){
        wxMessageBox( "testando tratamento de eventos3",
            "portugues", wxOK | wxICON_INFORMATION );
}
void Menu::OnEnglish(wxCommandEvent& event){
        wxMessageBox( "testando tratamento de eventos4",
            "ingles", wxOK | wxICON_INFORMATION );
}
void Menu::OnHelp(wxCommandEvent& event){
        wxMessageBox( "Op��o de ajuda.",
            "Ajuda", wxOK | wxICON_INFORMATION );
}
void Menu::OnExit(wxCommandEvent& event)
{
    Close( true );
}
void Menu::OnAbout(wxCommandEvent& event)
{
    About *dlg = new About(this);
    dlg->SetText("Este sotware foi desenvovido por \nTarcisio Batista e J�ssica Ferreira \ncomo segundo trabalho pr�tico \n da disciplina de Projeto Assistido \npor Computador - PAC, \n5� per�odo de \nEngenharia de Sistemas. \nUnimontes - 2015");
    dlg->ShowModal();
    dlg->Destroy();
}
