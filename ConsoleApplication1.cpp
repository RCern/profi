
#include "Header.h"

int main()
{
	std::vector<int> a = return_table_from_file("a.csv");
	std::vector<int> b = return_table_from_file("b.csv");
	high_low(b, a);

	std::cout << "Lowest RMSE for moving average: " << MovingAverage(a) << "\n";
	
	std::vector<double> rmse;
	std::vector<int> d = return_rand_table(12);
	rmse.push_back(holts_model(d,0.1,0.9));
	rmse.push_back(holts_model(d, 0.9, 0.1));
	rmse.push_back(holts_model(d, 0.4, 0.6));
	std::cout << "Lowest RMSE for Holt's Model: " << SmallestRMSE(rmse);

	std::vector<double> rmse_t;
	rmse_t.push_back(holts_model_t(d, 0.1, 0.9,1));
	rmse_t.push_back(holts_model_t(d, 0.9, 0.1,2));
	rmse_t.push_back(holts_model_t(d, 0.4, 0.6,3));
	std::cout << "Lowest RMSE for Holt's Model with t: " << SmallestRMSE(rmse);
	
}

