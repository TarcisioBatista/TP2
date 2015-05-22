#include <wx/wx.h>

class Menu: public wxMenuBar{

    public:
        Menu();
        void OnFile(wxCommandEvent& event);
        void OnNew(wxCommandEvent& event);
        void OnSave(wxCommandEvent& event);
        void OnExit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnHelp(wxCommandEvent& event);
        void OnTools(wxCommandEvent& event);
        void OnPortuguese(wxCommandEvent& event);
        void OnEnglish(wxCommandEvent& event);
        
        
    private:
        //acho q aqui só precisa colocar os menus principais
        // sem os submenus
        wxMenu *FileMenu;
        wxMenu *ToolsMenu;
        wxMenu *LanguagesSubMenu;
        wxMenu *AboutMenu;
        wxMenu *HelpMenu;
        
    DECLARE_EVENT_TABLE();
};

const int ID_FILE = 1;
const int ID_NEW = 2;
const int ID_SAVE = 3;
const int ID_TOOLS = 4;
const int ID_PORTUGUESE = 5;
const int ID_ENGLISH = 6;
const int ID_HELP = 7;

