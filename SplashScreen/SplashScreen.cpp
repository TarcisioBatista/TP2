#include "SplashScreen.h"

// a classe SplashScren contem apenas um metodo
// que recebe o caminho da imagem atraves de uma string
// e seta a splash screen.
void SplashScreen::SetSS(wxString img){
    wxInitAllImageHandlers();
    wxBitmap bitmap;
    if (bitmap.LoadFile(img ,wxBITMAP_TYPE_BMP)){      
     wxSplashScreen* splash = new wxSplashScreen(bitmap,
        wxSPLASH_CENTRE_ON_SCREEN|wxSPLASH_TIMEOUT,
        3500, NULL, -1, wxDefaultPosition, wxDefaultSize,
        wxBORDER_SIMPLE|wxSTAY_ON_TOP);
    splash->Show(true);
    }    
}
