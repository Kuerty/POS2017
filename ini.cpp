#include <windows.h>

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \fn	INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR lStart, INT nShow)
///
/// \brief	Window main.
///
/// \author	Kuna Jan
/// \date	2017-05-24
///
/// \param	hInst	  	Section.
/// \param	parameter2	Key.
/// \param	lStart	  	Text.
/// \param	nShow	  	Path.
///
/// \return	A WINAPI.
////////////////////////////////////////////////////////////////////////////////////////////////////

INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR lStart, INT nShow)
{
    WritePrivateProfileString("Sekcja pliku", "Klucz", "zapisywany_tekst", "D:\\plik INI.ini");
	CHAR wartosc[256]; 
	GetPrivateProfileString("Sekcja pliku", "Klucz", "Odczytywana_wartoœæ_nie_istnieje!", wartosc, 256,"D:\\plik INI.ini");
	MessageBox(0, wartosc, "Plik INI", MB_OK);
	
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// End of ini.cpp
// Do utworzenia automatyczych komentarzy u¿ywam na razie rozszerzenia Atomineer Pro Documentation
// Informacje jak zapisywaæ i odczytywaæ plik ini mo¿ecie znaleŸæ na stronie:
// http://lublin.webd.pl/crayze/cpp-winapi/winapi8_1.html
////////////////////////////////////////////////////////////////////////////////////////////////////

