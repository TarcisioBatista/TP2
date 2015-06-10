#include <wx/intl.h>

class Translation{   
    public:
        void SetLanguage(wxLanguage language);
    private:
        wxLocale* locale;
};

