#include "Header.h"

void affichage(std::vector<double> a) {
		for (int i = 0; i < a.size(); i++)
	{
		std::cout << a[i] << " " ;
	}
		std::cout << "\n";
}

void affichageInt(std::vector<int> a)
{
	std::cout << "Original data :   \t\n";
	for (int i = 0; i < a.size(); i++)
	{
		std::cout << a[i] << " ";
	}
	std::cout << "\n\n";
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

double RMSE(std::vector<int> org, std::vector<double> pred) {
	std::vector<double> diff;
	for (int i = 0; i < pred.size(); i++)
	{
		diff.push_back(pred[i] - org[i]);
	}
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

void PrintAllRMSE(std::vector<int>c, int serie)
{
	int value;
	double SmRMSE;
	std::vector<double>rmse;
	if (serie == 1)
	{
		rmse.push_back(zero_hold(c));
		std::cout << "\nRMSE for Zero-order-hold method RMSE => " << rmse[rmse.size() - 1] << "\n";
		rmse.push_back(MovingAverage(c));
		std::cout << "RMSE for Moving average method RMSE => " << rmse[rmse.size() - 1] << "\n";
	}
	else
	{
		do
		{
			std::cout << "Please enter a value for moving average k:\n";
			std::cin >> value;
		} while (value<0 || value>c.size());
		rmse.push_back(zero_hold(c));
		std::cout << "\nRMSE for Zero-order-hold method RMSE => " << rmse[rmse.size() - 1] << "\n";
		rmse.push_back(RMSE(c, MovingAveragek(c, value)));
		std::cout << "RMSE for Moving average method RMSE => " << rmse[rmse.size() - 1] << "\n";
	}
	rmse.push_back(holts_model(c, 0.1, 0.9));
	rmse.push_back(holts_model(c, 0.9, 0.1));
	rmse.push_back(holts_model(c, 0.4, 0.6));
	rmse.push_back(holts_model_t(c, 0.1, 0.9, 2));
	rmse.push_back(holts_model_t(c, 0.9, 0.1, 2));
	rmse.push_back(holts_model_t(c, 0.4, 0.6, 2));
	rmse.push_back(holts_model_t(c, 0.1, 0.9, 3));
	rmse.push_back(holts_model_t(c, 0.9, 0.1, 3));
	rmse.push_back(holts_model_t(c, 0.4, 0.6, 3));

	std::cout << "\nFor differences\n";

	rmse.push_back(holts_model_diff(c, 0.1, 0.9));
	rmse.push_back(holts_model_diff(c, 0.9, 0.1));
	rmse.push_back(holts_model_diff(c, 0.4, 0.6));
	rmse.push_back(holts_model_t_diff(c, 0.1, 0.9, 2));
	rmse.push_back(holts_model_t_diff(c, 0.9, 0.1, 2));
	rmse.push_back(holts_model_t_diff(c, 0.4, 0.6, 2));
	rmse.push_back(holts_model_t_diff(c, 0.1, 0.9, 3));
	rmse.push_back(holts_model_t_diff(c, 0.9, 0.1, 3));
	rmse.push_back(holts_model_t_diff(c, 0.4, 0.6, 3));
	SmRMSE = SmallestRMSE(rmse);
	DeclareSmallestRMSE(rmse, SmRMSE);
}

void PrintSmallestRMSE(std::vector<double>rmse,int i)
{
	std::cout << "\n\nThe best method giving the smallest RMSE is ";
	switch (i)
	{
	case 1:
	{
		std::cout << "The Zero-Order Hold";
		std::cout << "\nRMSE for Zero-order-hold method RMSE => " << rmse[i];
		break;
	}
	case 2:
	{
		std::cout << "The Moving average";
		std::cout << "\nRMSE for Moving average method RMSE => " << rmse[i];
		break;
	}
	case 3:
	{
		std::cout << "The Holt's method for horizon=1,alpha=0.1,beta=0.9";
		std::cout << "\nRMSE for Holt's model: RMSE => " << rmse[i];
		break;
	}
	case 4:
	{
		std::cout << "The Holt's method for horizon=1,alpha=0.9,beta=0.1";
		std::cout << "\nRMSE for Holt's model: RMSE => " << rmse[i];
		break;
	}
	case 5:
	{
		std::cout << "The Holt's method for horizon=1,alpha=0.4,beta=0.6";
		std::cout << "\nRMSE for Holt's model: RMSE => " << rmse[i];
		break;
	}
	case 6:
	{
		std::cout << "The Holt's method for horizon=2,alpha=0.1,beta=0.9";
		std::cout << "\nRMSE for Holt's model: RMSE => " << rmse[i];
		break;
	}
	case 7:
	{
		std::cout << "The Holt's method for horizon=2,alpha=0.9,beta=0.1";
		std::cout << "\nRMSE for Holt's model: RMSE => " << rmse[i];
		break;
	}
	case 8:
	{
		std::cout << "The Holt's method for horizon=2,alpha=0.4,beta=0.6";
		std::cout << "\nRMSE for Holt's model: RMSE => " << rmse[i];
		break;
	}
	case 9:
	{
		std::cout << "The Holt's method for horizon=3,alpha=0.1,beta=0.9";
		std::cout << "\nRMSE for Holt's model: RMSE => " << rmse[i];
		break;
	}
	case 10:
	{
		std::cout << "The Holt's method for horizon=3,alpha=0.9,beta=0.1";
		std::cout << "\nRMSE for Holt's model: RMSE => " << rmse[i];
		break;
	}
	case 11:
	{
		std::cout << "The Holt's method for horizon=3,alpha=0.4,beta=0.6";
		std::cout << "\nRMSE for Holt's model: RMSE => " << rmse[i];
		break;
	}
	case 12:
	{
		std::cout << "The Holt's method applied for differences for horizon=1,alpha=0.1,beta=0.9";
		std::cout << "\nRMSE for Differences for Holt's model: RMSE => " << rmse[i];
		break;
	}
	case 13:
	{
		std::cout << "The Holt's method applied for differences for horizon=1,alpha=0.9,beta=0.1";
		std::cout << "\nRMSE for Differences for Holt's model: RMSE => " << rmse[i];
		break;
	}
	case 14:
	{
		std::cout << "The Holt's method applied for differences for horizon=1,alpha=0.4,beta=0.6";
		std::cout << "\nRMSE for Differences for Holt's model: RMSE => " << rmse[i];
		break;
	}
	case 15:
	{
		std::cout << "The Holt's method applied for differences for horizon=2,alpha=0.1,beta=0.9";
		std::cout << "\nRMSE for Differences for Holt's model: RMSE => " << rmse[i];
		break;
	}
	case 16:
	{
		std::cout << "The Holt's method applied for differences for horizon=2,alpha=0.9,beta=0.4";
		std::cout << "\nRMSE for Differences for Holt's model: RMSE => " << rmse[i];
		break;
	}
	case 17:
	{
		std::cout << "The Holt's method applied for differences for horizon=2,alpha=0.4,beta=0.6";
		std::cout << "\nRMSE for Differences for Holt's model: RMSE => " << rmse[i];
		break;
	}
	case 18:
	{
		std::cout << "The Holt's method applied for differences for horizon=3,alpha=0.1,beta=0.9";
		std::cout << "\nRMSE for Differences for Holt's model: RMSE => " << rmse[i];
		break;
	}
	case 19:
	{
		std::cout << "The Holt's method applied for differences for horizon=3,alpha=0.9,beta=0.4";
			std::cout << "\nRMSE for Differences for Holt's model: RMSE => " << rmse[i];
		break;
	}
	case 20:
	{
		std::cout << "The Holt's method applied for differences for horizon=3,alpha=0.4,beta=0.6";
		std::cout << "\nRMSE for Differences for Holt's model: RMSE => " << rmse[i];
		break;
	}
	default:
	{
		break;
	}
	}
	std::cout << "\n";
}

void DeclareSmallestRMSE(std::vector<double>rmse, double smallest)
{
	int i=0;
	while (i < rmse.size() && rmse[i] != smallest)
	{
		i++;
	}
	PrintSmallestRMSE(rmse,i);
}

double SmallestRMSE(std::vector<double>rmse)
{
	double small = rmse[0];
	int i;
	for (i = 0; i < rmse.size(); i++)
		if (!rmse[i] == 0 && rmse[i] < small)
			small = rmse[i];
	return small;
}

int display_smallest_rmse(std::vector<double> rmse) {
	double temp = SmallestRMSE(rmse);
	int pos = std::distance(rmse.begin(), std::find(rmse.begin(),rmse.end(),temp));
	std::cout << "\npos = \n" << pos;
	return pos;
}