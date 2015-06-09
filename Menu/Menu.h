#ifndef _MENU_H
#define _MENU_H

#include <wx/wx.h>

class Menu: public wxMenuBar{

    public:
        //Construtor
        Menu();
        //Métodos para tratamento de eventos do menu
        void OnNew(wxCommandEvent& event);
        void OnOpen(wxCommandEvent& event);
        void OnSave(wxCommandEvent& event);
        void OnExit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnHelp(wxCommandEvent& event);
        void OnPortuguese(wxCommandEvent& event);
        void OnEnglish(wxCommandEvent& event);
        
    private:
        //Opções do Menu
        wxMenu *FileMenu;
        wxMenu *ToolsMenu;
        wxMenu *LanguagesSubMenu;
        wxMenu *AboutMenu;
        
        wxTextCtrl *m_pTextCtrl;
        
};

//Constantes que identificam os eventos de cliques nas respectivas opções do menu
const int ID_NEW = 1;
const int ID_SAVE = 2;
const int ID_OPEN = 3;
const int ID_PORTUGUESE = 4;
const int ID_ENGLISH = 5;
const int ID_HELP = 6;


#endif
