#include "functions_defs.h"


void save_modified_picture(Mat &picture, const string &filename, const string &output_dir_path) 
{
	vector<int> param;
	param.push_back(CV_IMWRITE_JPEG_QUALITY);
	param.push_back(95);
	string filepath;
	filepath = output_dir_path + "\\" + filename;
	imwrite(filepath, picture, param);
	//cout << "File saved to" << filepath << endl;

}

void wczytaj_obraz(const string nazwa_obrazu, const string sciezka_katalogu_obrazu, vector <Mat> & input_im_conatainer)
{
	struct stat buf;
	Mat im_handler;
	string sciezka_obrazu;
	sciezka_obrazu = sciezka_katalogu_obrazu + "\\" + nazwa_obrazu;

	if (stat(sciezka_obrazu.c_str(), &buf) != -1) {
		im_handler = imread(sciezka_obrazu, 1);
		input_im_conatainer.push_back(im_handler);
	}
	else
	{
		cout << sciezka_obrazu << " nie istnieje w katologu programu" << endl;
	}
}

void przetworzobraz(Mat & input_image, vector <Mat> & output_im_container) 
{
	Mat im_handler;
	vector<Mat> channels;
	im_handler = input_image;
	cvtColor(im_handler, im_handler, COLOR_BGR2YCrCb);
	split(im_handler, channels);
	equalizeHist(channels[0], channels[0]); //wyrównuje histogram sk³adowej Y (sk³adowa luminacji)
	merge(channels, im_handler);
	cvtColor(im_handler, im_handler, CV_YCrCb2BGR);
	output_im_container.push_back(im_handler);		
}

void zmienrozmiar(cv::Mat& input_mat, cv::Mat& output_mat, int width, int height) 
{
	Size image1_size(width, height);
	resize(input_mat, output_mat, image1_size);
}

void find_file_names(vector <string> &image_paths, string input_dir) 
{
	input_dir;
	input_dir += "\\*.*";
	HANDLE hfind;
	WIN32_FIND_DATA data;
	hfind = FindFirstFile(LPCSTR(input_dir.c_str()), &data);
	if (hfind != INVALID_HANDLE_VALUE) 
	{		
		do
		{
			image_paths.push_back(data.cFileName);
		} while (FindNextFile( hfind,&data) != 0);
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
	double kw = sqrt(number_of_elements);
	if (kw > (int)kw)
	{
		horizontal = (int)kw + 1;
	}
	else
	{
		horizontal = (int)kw;
	}

	if (horizontal*(int)kw >= (number_of_elements))
	{
		vertical = (int)kw;
	}
	else
	{
		vertical = horizontal;
	}
}

void load_ini(string &input_dir_path, string &output_dir_path)
{
	string inipath = "";
	cout << endl << "type path to ini fileand press enter. For default pass d and press enter ( \"C:\\data\\POS.ini\")" << endl;
	cin >> inipath;
	if ("d" == inipath)
	{
		inipath = "C:\\data\\POS.ini";
	}
	TCHAR key_value_from_ini[32];
	GetPrivateProfileString("source", "PATH", "C:\\data\\input", key_value_from_ini, 32, inipath.c_str());
	input_dir_path = key_value_from_ini;
	cout << "input directory path: " << input_dir_path << endl;
	GetPrivateProfileString("destination", "PATH", "C:\\data\\output", key_value_from_ini, 32, inipath.c_str());
	output_dir_path = key_value_from_ini;
	cout << "output directory path: " << output_dir_path << endl;
}

void load_then_process_mt(vector <string> &image_name, string &input_dir_path, vector <Mat> &input_im_conatainer, vector <Mat> &output_im_container, int number_of_threads)
{
	for (int j = 0; (j)* number_of_threads < image_name.size(); j++)
	{
		thread *tt = new thread[number_of_threads];
		for (int i = number_of_threads * j; i < number_of_threads + (number_of_threads * j); i++)
		{
			if (i >= image_name.size() - 2)
				break;
			wczytaj_obraz(image_name[i + 2], input_dir_path, input_im_conatainer);
			tt[i - (number_of_threads * j)] = thread(przetworzobraz, ref(input_im_conatainer[i]), ref(output_im_container));
		}
		for (int i = number_of_threads * j; i < number_of_threads + (number_of_threads * j); i++)
		{
			if (i >= image_name.size() - 2)
				break;
			tt[i - (number_of_threads * j)].join();
		}
		delete[] tt;
	}
}


void make_collage( Mat & collage, Mat & black_square, vector <Mat> & output_im_container, int horizontal, int vertical, int number_of_pictures)
{
	Mat collage_line;
	for (int j = 0; j < vertical; j++)
	{
		collage_line = output_im_container[j*horizontal];
		for (int i = j*horizontal; i < (j + 1)*horizontal - 1; i++)
		{
			if (i >= number_of_pictures - 1)
			{
				hconcat(collage_line, black_square, collage_line);
			}
			else
			{
				hconcat(collage_line, output_im_container[i + 1], collage_line);
			}
		}
		if (j == 0)
		{
			collage = collage_line;
		}
		else
		{
			vconcat(collage, collage_line, collage);
		}
	}
}

void save_mt(vector <Mat> & output_im_container, vector <string> & image_name, string &output_dir_path, int number_of_threads, int number_of_pictures)
{
	thread *tt = new thread[number_of_threads];
	for (int j = 0; j * 8 < number_of_pictures; j++)
	{
		for (int i = 0; i < number_of_threads; i++)
		{
			if (i + (j * 8) < number_of_pictures)
				tt[i] = thread(save_modified_picture, ref(output_im_container[i]), ref(image_name[(i + 2) + j * 8]), ref(output_dir_path));
			else
				break;
		}
		for (int i = 0; i < number_of_threads; i++)
		{
			if (i + (j * 8) < number_of_pictures)
				tt[i].join();
			else
				break;
		}
	}

}
