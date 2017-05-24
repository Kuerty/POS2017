#include <opencv2\opencv.hpp>
#include <opencv/highgui.h>

using namespace cv;

int main() {

	Mat image;

	VideoCapture cap;
	cap.open(0);

	namedWindow("window", 1);

	while (10) {

		cap >> image;
		
		imshow("window", image);
		waitKey(33);

	}

}