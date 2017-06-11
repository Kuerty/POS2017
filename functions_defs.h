#ifndef functions_defs_h
#define functions_defs_h

#include <opencv2\opencv.hpp>
#include <opencv/highgui.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <Windows.h>
#include <math.h>
#include <sys/stat.h>
#include <iostream>
#include<conio.h>
#include<stdio.h>


using namespace std;
using namespace cv;

void przetworzobraz(const string nazwa_obrazu, const string sciezka_katalogu_obrazu, cv::Mat & image1); //przetwarza obraz metod¹ uœredniania jasnoœci
void zmienrozmiar(cv::Mat& input_mat, cv::Mat& output_mat, int width, int height);
void find_file_names(vector <string> &image_paths, string input_dir);
void make_black_square(cv::Mat& matrix, int size);
void calculate_collage_dims(int & horizontal, int & vertical, double number_of_elements);
void save_modified_picture(cv::Mat picture, const string filename, const string output_dir_path);
void start_algorithm(int &bok_v, int &bok_h, int &miniature_size, int &number_of_pictures, vector <string> &image_name, string &input_dir_path, string &output_dir_path, cv::Mat &image1, cv::Mat &image2, cv::Mat &im_line_x, cv::Mat &black_square);
#endif // !functions_defs_h
