#include "headerKamila.h"

using namespace std;
using namespace cv;


void przetworzobraz(const string nazwa_obrazu) {

	Mat image, image2;

	image = imread(nazwa_obrazu, 1); //�cie�ka obrazu

	vector<Mat> channels;
	cvtColor(image, image, COLOR_BGR2YCrCb);

	split(image, channels);
	equalizeHist(channels[0], channels[0]); //wyr�wnuje histogram sk�adowej Y (sk�adowa luminacji)
	merge(channels, image2);

	cvtColor(image2, image2, CV_YCrCb2BGR);


	namedWindow("window2", CV_WINDOW_AUTOSIZE);


	imshow("window2", image2);
	waitKey(0);

}