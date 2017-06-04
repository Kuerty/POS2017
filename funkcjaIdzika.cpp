#include "headerIdzika.h"

using namespace std;
using namespace cv;

void kopiowanie_plikow()
{
	const string file_to_copy = "C:\\...\\filename.ext"; // tutaj czekamy na stringi od Jana z pliku INI
	const string file_copied = "C:\\...\\filename.ext";

	BOOL c = CopyFileA(file_to_copy.c_str(), file_copied.c_str(), true);

	if (c == 0)
		cout << "File" << file_to_copy.c_str() << " could not be copied successfully " << " Last error " << GetLastError() << endl;
}

void kopiowanie_plikow_v2() {
	BOOL b = CopyFileA("C:\\kod_visio.jpg", "C:\\Users\\Micha³\\Documents\\Visual Studio 2017\\Projects\\ConsoleApplication2\\kod_visio.jpg", TRUE);
	if (!b) {
		cout << "Error: " << GetLastError() << endl;
	}
	else {
		cout << "Okay " << endl;
	}
}

void save_modified_picture(Mat picture) {

	//if() {
	vector<int> param;
	param.push_back(CV_IMWRITE_JPEG_QUALITY);
	param.push_back(95);
	imwrite("sciezka z pliku ini", picture, param);
	cout << "File saved to" << "nazwa z pliku ini" << endl;
	/*}
	else {
		cout << "File:" << "nazwa z pliku ini" << "not saved" << endl;
	}*/

}//wszystko ladnie smiga
