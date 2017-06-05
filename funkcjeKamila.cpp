#include "headerKamila.h"
#include "headerIdzika.h"

using namespace std;
using namespace cv;

void przetworzobraz(const string nazwa_obrazu, Mat & image1) {
	struct stat buf;

	if (stat(nazwa_obrazu.c_str(), &buf) != -1) {

		image1 = imread(nazwa_obrazu, 1); //�cie�ka obrazu

		vector<Mat> channels;
		cvtColor(image1, image1, COLOR_BGR2YCrCb);

		split(image1, channels);
		equalizeHist(channels[0], channels[0]); //wyr�wnuje histogram sk�adowej Y (sk�adowa luminacji)
		merge(channels, image1);

		cvtColor(image1, image1, CV_YCrCb2BGR);


		namedWindow("window2", CV_WINDOW_AUTOSIZE);


		imshow("window2", image1);

		//save_modified_picture(image2); //funkcja Idzika zapisuj�ca obraz - dziala!
		//save_modified_picture(makeCanvas(image2, 1000, 3));
		
	}
	else
	{
		cout << nazwa_obrazu << " nie istnieje w katologu programu" << endl;
	}
}

void zmienrozmiar(cv::Mat im1, int width, int height) {

	Size image1_size(width, height);
	resize(im1, im1, image1_size);

	namedWindow("resized", CV_WINDOW_AUTOSIZE);
	imshow("resized", im1);

}


