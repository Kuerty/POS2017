#ifndef headerIdzika_h
#define headerIdzika_h

#include <iostream>
#include <windows.h>
#include<conio.h>
#include<stdio.h>

#include <opencv2\opencv.hpp>
#include <opencv/highgui.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

void kopiowanie_plikow();
void kopiowanie_plikow_v2();
void save_modified_picture(Mat picture, const string filename, const string output_dir_path);
Mat makeCanvas(vector<Mat>& vecMat, int windowHeight, int nRows);

#endif 
