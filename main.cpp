#include "headerKamila.h"
#include <sys/stat.h>
#include "headerIdzika.h"
#include "hederJanka.h"

int main() {
	
	string ini_path = "";

	vector <string> images_paths;

	string nazwa_obrazu = "C:\\Users\\Public\\Pictures\\Sample\ Pictures\\Jellyfish.jpg";

	przetworzobraz(nazwa_obrazu);
	plik_ini(ini_path);

	//kopiowanie_plikow();


	return 0;
}