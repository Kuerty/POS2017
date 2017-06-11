#include "functions_defs.h"


void save_modified_picture(Mat picture, const string filename, const string output_dir_path)
{
	//if(picture != NULL) {
	vector<int> param;
	param.push_back(CV_IMWRITE_JPEG_QUALITY);
	param.push_back(95);
	string filepath;
	filepath = output_dir_path + "\\" + filename;
	imwrite(filepath, picture, param);
	cout << "File saved to" << filepath << endl;
	/*}
	else {
	cout << "File:" << "nazwa z pliku ini" << "not saved" << endl;
	}*/

}//wszystko ladnie smiga

void przetworzobraz(const string nazwa_obrazu, const string sciezka_katalogu_obrazu, Mat & image1) {
	struct stat buf;

	string sciezka_obrazu;
	sciezka_obrazu = sciezka_katalogu_obrazu + "\\" + nazwa_obrazu;
	if (stat(sciezka_katalogu_obrazu.c_str(), &buf) != -1) {

		image1 = imread(sciezka_obrazu, 1); //œcie¿ka obrazu

		vector<Mat> channels;
		cvtColor(image1, image1, COLOR_BGR2YCrCb);

		split(image1, channels);
		equalizeHist(channels[0], channels[0]); //wyrównuje histogram sk³adowej Y (sk³adowa luminacji)
		merge(channels, image1);

		cvtColor(image1, image1, CV_YCrCb2BGR);


		//namedWindow("window2", CV_WINDOW_AUTOSIZE);


		//imshow("window2", image1);

		//save_modified_picture(image2); //funkcja Idzika zapisuj¹ca obraz - dziala!
		//save_modified_picture(makeCanvas(image2, 1000, 3));

	}
	else
	{
		cout << sciezka_obrazu << " nie istnieje w katologu programu" << endl;
	}
}

void zmienrozmiar(cv::Mat& input_mat, cv::Mat& output_mat, int width, int height) {

	Size image1_size(width, height);
	resize(input_mat, output_mat, image1_size);

	//namedWindow("resized", CV_WINDOW_AUTOSIZE);
	//imshow("resized", input_mat);
}

void find_file_names(vector <string> &image_paths, string input_dir)
{
	input_dir;
	input_dir += "\\*.*";
	HANDLE hfind;
	WIN32_FIND_DATA data;
	hfind = FindFirstFile(LPCSTR(input_dir.c_str()), &data);
	if (hfind != INVALID_HANDLE_VALUE) {

		do
		{
			image_paths.push_back(data.cFileName);
		} while (FindNextFile(hfind, &data) != 0);
	}
	else
	{
		cout << endl << GetLastError();
	}
	FindClose(hfind);
}

void make_black_square(cv::Mat& matrix, int size)
{
	matrix = Mat::zeros(size, size, CV_8UC3);
}

void calculate_collage_dims(int & horizontal, int & vertical, double number_of_elements)
{

	double kw = sqrt(number_of_elements - 2);

	if (kw > (int)kw)
	{
		horizontal = (int)kw + 1;
	}
	else
	{
		horizontal = (int)kw;
	}

	if (horizontal*(int)kw >= (number_of_elements - 2))
	{
		vertical = (int)kw;
	}
	else
	{
		vertical = horizontal;
	}
}

void start_algorithm(int &bok_v, int &bok_h, int &miniature_size, int &number_of_pictures, vector <string> &image_name, string &input_dir_path, string &output_dir_path, cv::Mat &image1, cv::Mat &image2, cv::Mat &im_line_x, cv::Mat &black_square)
{
	for (int j = 0; j <= bok_v - 1; j++)
	{
		if (0 == j) {
			przetworzobraz(image_name[2 + (j*bok_h)], input_dir_path, image1);
			save_modified_picture(image1, image_name[2 + (j*bok_h)], output_dir_path);
			zmienrozmiar(image1, image1, miniature_size, miniature_size);

			for (int i = 3 + (bok_h*j); ((bok_h*(j + 1)) + 2) > i; i++)
			{
				przetworzobraz(image_name[i], input_dir_path, image2);
				save_modified_picture(image2, image_name[i], output_dir_path);
				zmienrozmiar(image2, image2, miniature_size, miniature_size);
				hconcat(image1, image2, image1);
			}
		}
		else if (j == bok_v - 1)
		{
			przetworzobraz(image_name[2 + (j*bok_h)], input_dir_path, im_line_x);
			save_modified_picture(im_line_x, image_name[2 + (j*bok_h)], output_dir_path);
			zmienrozmiar(im_line_x, im_line_x, miniature_size, miniature_size);

			for (int i = 3 + (bok_h*j); ((bok_h*(j + 1)) + 2) - (((bok_h*bok_v) - number_of_pictures)) - 2 > i; i++)
			{
				przetworzobraz(image_name[i], input_dir_path, image2);
				save_modified_picture(image2, image_name[i], output_dir_path);
				zmienrozmiar(image2, image2, miniature_size, miniature_size);
				hconcat(im_line_x, image2, im_line_x);
			}
			for (int i = 0; ((bok_h*bok_v) - (number_of_pictures - 2)) > i; i++)
			{
				hconcat(im_line_x, black_square, im_line_x);
			}
			vconcat(image1, im_line_x, image1);
		}
		else
		{
			przetworzobraz(image_name[2 + (j*bok_h)], input_dir_path, im_line_x);
			save_modified_picture(im_line_x, image_name[2 + (j*bok_h)], output_dir_path);
			zmienrozmiar(im_line_x, im_line_x, miniature_size, miniature_size);
			for (int i = 3 + (bok_h*j); ((bok_h*(j + 1)) + 2) > i; i++)
			{
				przetworzobraz(image_name[i], input_dir_path, image2);
				save_modified_picture(image2, image_name[i], output_dir_path);
				zmienrozmiar(image2, image2, miniature_size, miniature_size);
				hconcat(im_line_x, image2, im_line_x);
			}
			vconcat(image1, im_line_x, image1);
		}
	}
}

