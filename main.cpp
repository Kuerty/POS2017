#include "functions_defs.h"


int main() {

	clock_t start, stop;

	int miniature_square_size = 200;
	string input_dir_path = ""; //from ini file
	string output_dir_path = ""; //from ini file
	load_ini(input_dir_path, output_dir_path);
	int number_of_threads = 8;
	vector <string> image_name;

	Mat black_square;
	make_black_square(black_square, miniature_square_size);

	Mat collage;
	vector <Mat> input_im_conatainer, output_im_container;
	int miniatures_in_row, miniatures_in_column;
	find_file_names(image_name, input_dir_path);
	int number_of_pictures = image_name.size()-2;
	calculate_collage_dims(miniatures_in_row, miniatures_in_column, number_of_pictures);
	start = clock();
	
	load_then_process_mt(image_name, input_dir_path, input_im_conatainer, output_im_container, number_of_threads);

	for (int i = 0; i < number_of_pictures; i++)
	{
		save_modified_picture(output_im_container[i], image_name[i + 2], output_dir_path);
	}
	for (int i = 0; i < number_of_pictures; i++)
	{
		zmienrozmiar(output_im_container[i], output_im_container[i], miniature_square_size, miniature_square_size);
	}
	make_collage(collage, black_square, output_im_container, miniatures_in_row, miniatures_in_column, number_of_pictures);
	stop = clock();

	namedWindow("collage", CV_WINDOW_AUTOSIZE);
	imshow("collage", collage);
	
	//save_modified_picture(output_im_container[0], image_name[2], output_dir_path);

	
	//namedWindow("miniatures after process", CV_WINDOW_AUTOSIZE);
	//imshow("miniatures after process", input_im_conatainer[3]);

	cout << "petla trwala " << (double)(stop - start) << " cykli zegara proceora" << endl;
	waitKey(0);

	return 0;
}