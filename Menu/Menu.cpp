#include <wx/intl.h>
#include "Menu.h"
#include "../App/MainApp.h"
#include "../About/About.h"
//#include "../Translation/Translation.h"

   
Menu::Menu()
        :wxMenuBar(){
            
    
    
    //menu arquivo -> novo - salvar - sair            
    FileMenu = new wxMenu();
    	FileMenu->Append(ID_NEW, _("&Novo"), _("Novo Arquivo"));
    	FileMenu->Append(ID_OPEN, _("&Abrir"), _("Abrir"));
        FileMenu->Append(ID_SAVE, _("&Salvar"), _("Salvar"));
    	FileMenu->AppendSeparator();
    	FileMenu->Append(wxID_EXIT, _("&Sair"), _("Sair"));
    	this->Append(FileMenu, _("&Arquivo"));
	
	// Menu Ferramentas -> idiomas -> portugues - ingles
    ToolsMenu = new wxMenu();
    LanguagesSubMenu = new wxMenu();        
        LanguagesSubMenu->Append(ID_PORTUGUESE, _("&Portuguese"), _("Traduzir para o Portuges"));
        LanguagesSubMenu->Append(ID_ENGLISH, _("&English"), _("Translate to English"));
        LanguagesSubMenu->Append(ID_SPANISH, _("&Español"), _("Traducir al Español"));
        ToolsMenu->AppendSubMenu(LanguagesSubMenu, _("&Idiomas"), _("idiomas"));
        this->Append(ToolsMenu, _("Ferramentas"));
        
	
	// Menu About - About - Help
	AboutMenu = new wxMenu();
    	AboutMenu->Append(wxID_ABOUT, _("&Sobre"), _("Exibe informações sobre o software"));
       	AboutMenu->Append(ID_HELP, _("&Ajuda"), _("Abre a opção de ajuda."));
        this->Append(AboutMenu, _("&Sobre"));       
        
}    

//Métodos de cada opção do menu    
void Menu::OnNew(wxCommandEvent& event){
        wxMessageBox( _("Um novo arquivo foi selecionado."),
            _("Novo"), wxOK | wxICON_INFORMATION );
}
void Menu::OnOpen(wxCommandEvent &event){
  wxFileDialog *dlg = new wxFileDialog(this, _("Abrir um arquivo"),
									   "", "", "All files(*.*)|*.*|Text Files(*.txt)|*.txt",
									   wxFD_OPEN, wxDefaultPosition);
  if ( dlg->ShowModal() == wxID_OK )
  {
	    wxMessageBox(dlg->GetPath(),_("Salvar"), wxOK | wxICON_INFORMATION );
  }
  dlg->Destroy();
}
void Menu::OnSave(wxCommandEvent& event){
        wxMessageBox( _("O Arquivo foi salvo."),
            _("Salvar"), wxOK | wxICON_INFORMATION );
            
}
//void Menu::OnPortuguese(wxCommandEvent& event){
//        wxGetApp().SetLanguage(wxLANGUAGE_PORTUGUESE_BRAZILIAN);   
//        wxGetApp().RecreateGUI();    
//}
//void Menu::OnEnglish(wxCommandEvent& event){  
//        wxGetApp().SetLanguage(wxLANGUAGE_ENGLISH);             
//        wxGetApp().RecreateGUI();
//}
//void Menu::OnSpanish(wxCommandEvent& event){  
//        wxGetApp().SetLanguage(wxLANGUAGE_SPANISH);
//        wxGetApp().RecreateGUI();
//}


void Menu::OnHelp(wxCommandEvent& event){
        wxMessageBox( _("Opção de ajuda."),
            _("Ajuda"), wxOK | wxICON_INFORMATION );
}
void Menu::OnExit(wxCommandEvent& event)
{
    Close( true );
}
void Menu::OnAbout(wxCommandEvent& event)
{
    About *dlg = new About(this);
    dlg->SetText(_("Este sotware foi desenvovido por\nTarcisio Batista e Jéssica Ferreira\ncomo segundo trabalho prático\n da disciplina de Projeto Assistido \npor Computador - PAC,\n5º período de \nEngenharia de Sistemas.\nUnimontes - 2015"));
    dlg->ShowModal();
    dlg->Destroy();
}
