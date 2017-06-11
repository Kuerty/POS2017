#include "functions_defs.h"


int main() {

	string input_dir_path = "C:\\data\\input"; //from ini file
	string output_dir_path = "C:\\data\\output"; //from ini file

	vector <string> image_name;
	Mat black_square;
	Mat image1, image2, im_line_x, im_lin_x_1;
	vector <Mat> im;
	int bok_h, bok_v;
	int miniature_size = 200;
	make_black_square(black_square, miniature_size);
	find_file_names(image_name, input_dir_path);
	int number_of_pictures = image_name.size();
	calculate_collage_dims(bok_h, bok_v, number_of_pictures);

	start_algorithm(bok_v, bok_h, miniature_size, number_of_pictures, image_name, input_dir_path, output_dir_path, image1, image2, im_line_x, black_square);
	
	//namedWindow("sss", CV_WINDOW_AUTOSIZE);
	imshow("namedwindow", image1);
	

	waitKey(0);

	return 0;
}