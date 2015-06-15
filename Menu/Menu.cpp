#include <wx/intl.h>
#include "Menu.h"
#include "../App/MainApp.h"
#include "../About/About.h"
#include "../Help/Help.h"
   
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
	
	// Menu Ferramentas -> idiomas -> portugues - ingles - espanhol
    ToolsMenu = new wxMenu();
    LanguagesSubMenu = new wxMenu();        
        LanguagesSubMenu->Append(ID_PORTUGUESE, _("&Portuguese"), _("Traduzir para o Portuges"));
        LanguagesSubMenu->Append(ID_ENGLISH, _("&English"), _("Translate to English"));
        LanguagesSubMenu->Append(ID_SPANISH, _("&Espa�ol"), _("Traducir al Espa�ol"));
        ToolsMenu->AppendSubMenu(LanguagesSubMenu, _("&Idiomas"), _("idiomas"));
        this->Append(ToolsMenu, _("Ferramentas"));
        
	
	// Menu About - About - Help
	AboutMenu = new wxMenu();
    	AboutMenu->Append(wxID_ABOUT, _("&Sobre"), _("Exibe informa��es sobre o software"));
       	AboutMenu->Append(ID_HELP, _("&Ajuda"), _("Abre a op��o de ajuda."));
        this->Append(AboutMenu, _("&Sobre"));       
        
}    

//M�todos de cada op��o do menu

//ao selecionar o menu novo uma mensagem � mostrada   
void Menu::OnNew(wxCommandEvent& event){
        wxMessageBox( _("Um novo arquivo foi selecionado."),
            _("Novo"), wxOK | wxICON_INFORMATION );
}
//ao selecionar o menu abrir � aberta uma caixa de dialogo do sistema
// que possibilita navegar pelas pastas do windows, quando um aquivo � selecionado
//� mostrado na tela todo o caminho daquele arquivo.
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
//ao selecionar o menu salvar o � mostrado uma mensagem na tela
void Menu::OnSave(wxCommandEvent& event){
        wxMessageBox( _("O Arquivo foi salvo."),
            _("Salvar"), wxOK | wxICON_INFORMATION );
            
}
//ao selecionar o menu portugues o locale � setado com idioma portugues
//em seguida a frame � refeita em portugues. O mesmo acontece com as 
//linguagens subsequentes mas com suas respectivas linguagens.
void Menu::OnPortuguese(wxCommandEvent& event){
        wxGetApp().SetLanguage(wxLANGUAGE_PORTUGUESE_BRAZILIAN);
        wxGetApp().RecreateGUI();       
}
void Menu::OnEnglish(wxCommandEvent& event){
        wxGetApp().SetLanguage(wxLANGUAGE_ENGLISH);
        wxGetApp().RecreateGUI();       
}
void Menu::OnSpanish(wxCommandEvent& event){
        wxGetApp().SetLanguage(wxLANGUAGE_SPANISH);
        wxGetApp().RecreateGUI();        
}

//chama a classe help que mapeia o as op��es de help e mostra
void Menu::OnHelp(wxCommandEvent& event){
    Help *helpController = new Help(this->GetParent());
}
// ao selecionado o menu sair a aplica��o � encerrada.
void Menu::OnExit(wxCommandEvent& event)
{
    //wxLogMessage("Aqui!", _("Erro"), wxOK | wxICON_INFORMATION);
    AccessControl acc;
    acc.log(2);
    Close( true );
}
// ao selecionado o menu sobre � mostrado informa��es dos desenvolvedores
void Menu::OnAbout(wxCommandEvent& event)
{
    About *dlg = new About(this);
    dlg->SetText(_("Este sotware foi desenvovido por\nTarcisio Batista e J�ssica Ferreira\ncomo segundo trabalho pr�tico\n da disciplina de Projeto Assistido \npor Computador - PAC,\n5� per�odo de \nEngenharia de Sistemas.\nUnimontes - 2015"));
    dlg->ShowModal();
    dlg->Destroy();
}
