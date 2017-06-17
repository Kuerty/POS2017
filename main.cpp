#include "functions_defs.h"


int main() {

	clock_t start, stop;

	int miniature_square_size = 200;
	string input_dir_path = ""; //from ini file
	string output_dir_path = ""; //from ini file
	load_ini(input_dir_path, output_dir_path);
	int number_of_threads = 8;
	vector <string> image_name;
	vector <string> name_to_save;

	Mat black_square;
	make_black_square(black_square, miniature_square_size);

	Mat collage;
	vector <Mat> input_im_conatainer, output_im_container;
	int miniatures_in_row, miniatures_in_column;
	find_file_names(image_name, input_dir_path);
	int number_of_pictures = image_name.size()-2;
	calculate_collage_dims(miniatures_in_row, miniatures_in_column, number_of_pictures);
	//cout << "podaj wielkosc miniaturek" << endl; 
	//cin << miniature_square_size;
	
	start = clock();
	
	load_then_process_mt(image_name, input_dir_path, input_im_conatainer, output_im_container, number_of_threads,name_to_save);
	
	for (int i = 0; i < number_of_pictures; i++)
	//{
	//	save_modified_picture(output_im_container[i], name_to_save[i], output_dir_path);
	//}
	
	save_mt(output_im_container, name_to_save, output_dir_path, number_of_threads, number_of_pictures);

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
	//assert(_CrtCheckMemory());
	waitKey(0);

	return 0;

}