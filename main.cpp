#include "headerKamila.h"
#include <sys/stat.h>
#include "headerIdzika.h"
#include "hederJanka.h"


int main() {
	
	string ini_path = "";

	vector <string> image_paths;

	plik_ini(image_paths);
		/* WERSJA DRUGA WCZYTANIA INI ZOSTAWCIE POKI CO
		TCHAR inipath[32];
		GetPrivateProfileString("Image", "PATH1", ".\\default.jpg", inipath, 32, ".\\Paths.ini"); //generalnie to tez pobiera co chcemy
		*/

	przetworzobraz(image_paths[0]);

	//przetworzobraz("C:\\POS2017\\POS2017\\Hydrangeas.jpg");

	//save_modified_picture(image2);

	return 0;
}