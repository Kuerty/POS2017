#include "headerKamila.h"
#include "headerIdzika.h"

using namespace std;
using namespace cv;

void przetworzobraz(const string nazwa_obrazu, Mat & image1) {
	struct stat buf;

	if (stat(nazwa_obrazu.c_str(), &buf) != -1) {

		image1 = imread(nazwa_obrazu, 1); //œcie¿ka obrazu

		vector<Mat> channels;
		cvtColor(image1, image1, COLOR_BGR2YCrCb);

		split(image1, channels);
		equalizeHist(channels[0], channels[0]); //wyrównuje histogram sk³adowej Y (sk³adowa luminacji)
		merge(channels, image1);

		cvtColor(image1, image1, CV_YCrCb2BGR);


		//namedWindow("window2", CV_WINDOW_AUTOSIZE);


		//imshow("window2", image1);

		//save_modified_picture(image2); //funkcja Idzika zapisuj¹ca obraz - dziala!
		//save_modified_picture(makeCanvas(image2, 1000, 3));
		
	}
	else
	{
		cout << nazwa_obrazu << " nie istnieje w katologu programu" << endl;
	}
}

void zmienrozmiar(cv::Mat& im1, int width, int height) {

	Size image1_size(width, height);
	resize(im1, im1, image1_size);

	//namedWindow("resized", CV_WINDOW_AUTOSIZE);
	//imshow("resized", im1);
}

void find_file_names(vector <string> &image_paths) {
	string input_dir, output_dir;
	input_dir = "C:\\data\\input\\*.*";
	output_dir = "C:\\data\\output";
	HANDLE hfind;
	WIN32_FIND_DATA data;
	hfind = FindFirstFile(LPCSTR(input_dir.c_str()), &data);
	if (hfind != INVALID_HANDLE_VALUE) {
		
		do
		{
			image_paths.push_back(data.cFileName);
		} while (FindNextFile( hfind,&data) != 0);
	}
	else
	{
		cout << endl << GetLastError();
	}
	FindClose(hfind);
}


