#include "headerIdzika.h"

using namespace std;
using namespace cv;

/**********************************************************************************************//**
 * @fn	void kopiowanie_plikow()
 *
 * @brief	Kopiowanie plikow.
 *
 * @author	Micha³
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
 * @author	Micha³
 * @date	05.06.2017
 **************************************************************************************************/

void kopiowanie_plikow_v2() {
	BOOL b = CopyFileA("C:\\kod_visio.jpg", "C:\\Users\\Micha³\\Documents\\Visual Studio 2017\\Projects\\ConsoleApplication2\\kod_visio.jpg", TRUE);
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
 * @author	Micha³
 * @date	05.06.2017
 *
 * @param	picture	The picture.
 **************************************************************************************************/

void save_modified_picture(Mat picture) {

	//if(picture != NULL) {
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

 /*************************************************************************************************
 * @brief makeCanvas Makes composite image from the given images
 * @param vecMat Vector of Images.
 * @param windowHeight The height of the new composite image to be formed.
 * @param nRows Number of rows of images. (Number of columns will be calculated
 *              depending on the value of total number of images).
 * @return new composite image.
 *************************************************************************************************/
Mat makeCanvas(vector<Mat>& vecMat, int windowHeight, int nRows) {
	int N = vecMat.size();
	nRows = nRows > N ? N : nRows;
	int edgeThickness = 10;
	int imagesPerRow = ceil(double(N) / nRows);
	int resizeHeight = floor(2.0 * ((floor(double(windowHeight - edgeThickness) / nRows)) / 2.0)) - edgeThickness;
	int maxRowLength = 0;

	vector<int> resizeWidth;
	for (int i = 0; i < N;) {
		int thisRowLen = 0;
		for (int k = 0; k < imagesPerRow; k++) {
			double aspectRatio = double(vecMat[i].cols) / vecMat[i].rows;
			int temp = int(ceil(resizeHeight * aspectRatio));
			resizeWidth.push_back(temp);
			thisRowLen += temp;
			if (++i == N) break;
		}
		if ((thisRowLen + edgeThickness * (imagesPerRow + 1)) > maxRowLength) {
			maxRowLength = thisRowLen + edgeThickness * (imagesPerRow + 1);
		}
	}
	int windowWidth = maxRowLength;
	Mat canvasImage(windowHeight, windowWidth, CV_8UC3, Scalar(0, 0, 0));

	for (int k = 0, i = 0; i < nRows; i++) {
		int y = i * resizeHeight + (i + 1) * edgeThickness;
		int x_end = edgeThickness;
		for (int j = 0; j < imagesPerRow && k < N; k++, j++) {
			int x = x_end;
			Rect roi(x, y, resizeWidth[k], resizeHeight);
			Size s = canvasImage(roi).size();
			// change the number of channels to three
			Mat target_ROI(s, CV_8UC3);
			if (vecMat[k].channels() != canvasImage.channels()) {
				if (vecMat[k].channels() == 1) {
					cvtColor(vecMat[k], target_ROI, CV_GRAY2BGR);
				}
			}
			else {
				vecMat[k].copyTo(target_ROI);
			}
			resize(target_ROI, target_ROI, s);
			if (target_ROI.type() != canvasImage.type()) {
				target_ROI.convertTo(target_ROI, canvasImage.type());
			}
			target_ROI.copyTo(canvasImage(roi));
			x_end += resizeWidth[k] + edgeThickness;
		}
	}
	return canvasImage;
}