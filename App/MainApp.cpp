#include "MainApp.h"
#include "Constant.h"


IMPLEMENT_APP(MainApp)
  
//O método OnInit cria uma frame na tela com os dados dos menus e barras de ferramentas.
//Também cria a frame inicial de login no sistema
bool MainApp::OnInit(){                                   
    RecreateGUI();         
    return true;                                  
};

void MainApp::RecreateGUI(){
    wxWindow * topwindow = GetTopWindow();
    if(topwindow)
    {
        SetTopWindow(NULL);
        topwindow->Destroy();
    }
    //Frame de login 
    LoginFrame *lframe = new LoginFrame(_("Login"));
    SetTopWindow(lframe);
    lframe->Centre();
    lframe->Show(true);
}
void MainApp::SetLanguage(wxLanguage language){
    // carrega outra lingua se possivel, se não volta para a lingua padrão
    if(wxLocale::IsAvailable(language)){
        
        locale = new wxLocale(language);
        // add locale search paths
        locale->AddCatalogLookupPathPrefix(wxT("./Languages"));
        locale->AddCatalogLookupPathPrefix(wxT("../../Languages"));
        locale->AddCatalog(wxT("myapp"));
        RecreateGUI();
    }
}

