#include "headerKamila.h"
#include <sys/stat.h>
#include "headerIdzika.h"
#include "hederJanka.h"


int main() {
	
	string ini_path = "";

	vector <string> image_paths;

	plik_ini(image_paths);
	przetworzobraz(image_paths[0]);


	return 0;
}