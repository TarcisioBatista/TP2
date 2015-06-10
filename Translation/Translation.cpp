#include "Translation.h"


void Translation::SetLanguage(wxLanguage language){
    // carrega outra lingua se possivel, se não volta para a lingua padrão
    if(wxLocale::IsAvailable(language)){
        
        locale = new wxLocale(language);
        // add locale search paths
        locale->AddCatalogLookupPathPrefix(wxT("./Languages"));
        locale->AddCatalogLookupPathPrefix(wxT("../../Languages"));
        locale->AddCatalog(wxT("myapp"));
    }
}