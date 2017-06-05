#include "headerIdzika.h"

using namespace std;
using namespace cv;

/**********************************************************************************************//**
 * @fn	void kopiowanie_plikow()
 *
 * @brief	Kopiowanie plikow.
 *
 * @author	Micha�
 * @date	05.06.2017
 **************************************************************************************************/

void kopiowanie_plikow()
{
	const string file_to_copy = "C:\\...\\filename.ext"; // tutaj czekamy na stringi od Jana z pliku INI
	const string file_copied = "C:\\...\\filename.ext";

	BOOL c = CopyFileA(file_to_copy.c_str(), file_copied.c_str(), true);

	if (c == 0)
		cout << "File" << file_to_copy.c_str() << " could not be copied successfully " << " Last error " << GetLastError() << endl;
}

/**********************************************************************************************//**
 * @fn	void kopiowanie_plikow_v2()
 *
 * @brief	Kopiowanie plikow v 2.
 *
 * @author	Micha�
 * @date	05.06.2017
 **************************************************************************************************/

void kopiowanie_plikow_v2() {
	BOOL b = CopyFileA("C:\\kod_visio.jpg", "C:\\Users\\Micha�\\Documents\\Visual Studio 2017\\Projects\\ConsoleApplication2\\kod_visio.jpg", TRUE);
	if (!b) {
		cout << "Error: " << GetLastError() << endl;
	}
	else {
		cout << "Okay " << endl;
	}
}

/**********************************************************************************************//**
 * @fn	void save_modified_picture(Mat picture)
 *
 * @brief	Saves a modified picture.
 *
 * @author	Micha�
 * @date	05.06.2017
 *
 * @param	picture	The picture.
 **************************************************************************************************/

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
