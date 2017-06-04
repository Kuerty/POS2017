#include "headerKamila.h"
#include "headerIdzika.h"

using namespace std;
using namespace cv;

void przetworzobraz(const string nazwa_obrazu) {
	struct stat buf;

	if (stat(nazwa_obrazu.c_str(), &buf) != -1) {

		Mat image, image2;

		image = imread(nazwa_obrazu, 1); //œcie¿ka obrazu

		vector<Mat> channels;
		cvtColor(image, image, COLOR_BGR2YCrCb);

		split(image, channels);
		equalizeHist(channels[0], channels[0]); //wyrównuje histogram sk³adowej Y (sk³adowa luminacji)
		merge(channels, image2);

		cvtColor(image2, image2, CV_YCrCb2BGR);


		namedWindow("window2", CV_WINDOW_AUTOSIZE);


		imshow("window2", image2);

		//save_modified_picture(image2); //funkcja Idzika zapisuj¹ca obraz - dziala!
	}
	else
	{
		cout << nazwa_obrazu << " nie istnieje w katologu programu" << endl;
	}
	waitKey(0);
}


