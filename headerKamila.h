#ifndef headerKamila_h
#define headerKamila_h

#include <opencv2\opencv.hpp>
#include <opencv/highgui.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;

void przetworzobraz(const string nazwa_obrazu, cv::Mat& image1); //przetwarza obraz metod� u�redniania jasno�ci
void zmienrozmiar(cv::Mat& im1, int width, int height);

#endif // !headerKamila_h
