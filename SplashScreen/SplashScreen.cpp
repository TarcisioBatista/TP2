#include "SplashScreen.h"

void SplashScreen::SetSS(){
    wxInitAllImageHandlers();
    wxBitmap bitmap;
    if (bitmap.LoadFile("../../Images/splash.bmp",wxBITMAP_TYPE_BMP)){      
     wxSplashScreen* splash = new wxSplashScreen(bitmap,
        wxSPLASH_CENTRE_ON_SCREEN|wxSPLASH_TIMEOUT,
        6000, NULL, -1, wxDefaultPosition, wxDefaultSize,
        wxBORDER_SIMPLE|wxSTAY_ON_TOP);
    splash->Show(true);
    }    
}
