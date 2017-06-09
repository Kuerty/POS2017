#ifndef headerKamila_h
#define headerKamila_h

#include <opencv2\opencv.hpp>
#include <opencv/highgui.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <Windows.h>

using namespace std;

void przetworzobraz(const string nazwa_obrazu, cv::Mat& image1); //przetwarza obraz metod¹ uœredniania jasnoœci
void zmienrozmiar(cv::Mat& im1, int width, int height);
void find_file_names(vector <string> &image_paths);

#endif // !headerKamila_h
