//#include <opencv2\opencv.hpp>
//#include <opencv/highgui.h>
//#include <opencv2/imgproc/imgproc.hpp>
//#include <opencv2/highgui/highgui.hpp>
#include "headerKamila.h"

//using namespace cv;
using namespace std; //to jest namespae

int main() {
	
	przetworzobraz("Hydrangeas.jpg");
	/*
	Mat image,image2;

	image = imread("Hydrangeas.jpg", 1); //œcie¿ka obrazu

	vector<Mat> channels;
	cvtColor(image, image, COLOR_BGR2YCrCb); 
	
	split(image, channels);
	equalizeHist(channels[0], channels[0]); //wyrównuje histogram sk³adowej Y (sk³adowa luminacji)
	merge(channels, image2);

	cvtColor(image2, image2, CV_YCrCb2BGR);


	namedWindow("window2", CV_WINDOW_AUTOSIZE);


	imshow("window2", image2);
	waitKey(0);
	*/
	return 0;
}