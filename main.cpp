#include "headerKamila.h"
#include <sys/stat.h>
#include "headerIdzika.h"
#include "hederJanka.h"


int main() {
	
	string ini_path = "";

	vector <string> image_paths;
	Mat obraz_do_testow,sss, ssss;

	plik_ini(image_paths);
		/* WERSJA DRUGA WCZYTANIA INI ZOSTAWCIE POKI CO
		TCHAR inipath[32];
		GetPrivateProfileString("Image", "PATH1", ".\\default.jpg", inipath, 32, ".\\Paths.ini"); //generalnie to tez pobiera co chcemy
		*/

	przetworzobraz(image_paths[0], obraz_do_testow);
	przetworzobraz(image_paths[0], sss);
	zmienrozmiar(obraz_do_testow, 150, 150);
	zmienrozmiar(sss, 150, 150);
	hconcat(obraz_do_testow, sss, ssss);
	
	namedWindow("test", WINDOW_AUTOSIZE);
	imshow("test", ssss);
	//save_modified_picture(image2);

	waitKey(0);

	return 0;
}