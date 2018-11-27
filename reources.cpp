#include "Header.h"

void affichage(std::vector<double> a) {
	for (int i = 0; i < a.size(); i++)
	{
		std::cout << a[i] << "\n";
	}
}

std::vector<int> return_table_from_file(std::string path_name) {
	std::ifstream file;
	file.open(path_name);
	std::vector<std::string> vect;
	std::string line;
	while (std::getline(file, line)) {
		vect.push_back(line);
	}
	file.close();
	std::vector<int> vec_int;
	for (int i = 0; i < vect.size(); i++)
	{
		int num = atoi(vect.at(i).c_str());
		vec_int.push_back(num);
	}
	return vec_int;
}

double RMSE(std::vector<double> diff) {
	double sumsquared = 0;
	for (int i = 0; i < diff.size(); i++)
	{
		sumsquared += diff[i] * diff[i];
	}
	return sqrt(sumsquared / diff.size());

}

std::vector<int> return_rand_table(int size) {
	std::vector<int> ret;
	for (int i = 0; i < size; i++)
	{
		ret.push_back(generate_rand());
	}
	return ret;
}

int generate_rand() {

	return rand() % (120 - 80 + 1) + 80;
}