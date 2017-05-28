#include "HeaderIdzika.h"


using namespace std;

void kopiowanie_plikow()
{
	BOOL c = CopyFile((LPCTSTR) "sss.txt", (LPCTSTR)"ccc.txt", true);
	if (c == 0)
		cout << "File could not be copied successfully " << c << "Last error " << GetLastError() << endl;
		
	else
		cout << "file copied succesful" << endl;

	
	
	//CopyFile((LPCWSTR)"C:\\kod_visio.jpg", (LPCWSTR)"C:\\Users\\Michał\\Documents\\Visual Studio 2017\\Projects\\ConsoleApplication2",false);
	//CopyFileA("C:\\kod_visio.jpg", "C:\\Users\\Michał\\Documents\\Visual Studio 2017\\Projects\\ConsoleApplication2", true);
	//cin.get();
}
