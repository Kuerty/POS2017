#include "HeaderIdzika.h"


using namespace std;

void kopiowanie_plikow()
{
	const string file_to_copy = "C:\\...\\filename.ext"; // tutaj czekamy na stringi od Jana z pliku INI
	const string file_copied = "C:\\...\\filename.ext";

	BOOL c = CopyFile(file_to_copy.c_str(), file_copied.c_str(), true);

	if (c == 0)
		cout << "File" << file_to_copy.c_str() << " could not be copied successfully " << " Last error " << GetLastError() << endl;

	
	
}
