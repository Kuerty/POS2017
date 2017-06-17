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
#include <time.h>
#include <thread>


using namespace std;
using namespace cv;

void wczytaj_obraz(const string nazwa_obrazu, const string sciezka_katalogu_obrazu, vector <Mat> & input_im_conatainer);
void przetworzobraz(Mat & input_image, vector <Mat> & output_im_container); //przetwarza obraz metod¹ uœredniania jasnoœci
void zmienrozmiar(Mat& input_mat, Mat& output_mat, int width, int height);
void find_file_names(vector <string> &image_paths, string input_dir);
void make_black_square(Mat& matrix, int size);
void calculate_collage_dims(int & horizontal, int & vertical, double number_of_elements);
void save_modified_picture(Mat &picture, const string &filename, const string &output_dir_path);
void load_ini(string &input_dir_path, string &output_dir_path);
void load_then_process_mt(vector <string> &image_name, string &input_dir_path, vector <Mat> &input_im_conatainer, vector <Mat> &output_im_container, int number_of_threads);
void make_collage(Mat & collage, Mat & black_square, vector <Mat> & output_im_container, int horizontal, int vertical, int number_of_pictures);
#endif // !functions_defs_h
