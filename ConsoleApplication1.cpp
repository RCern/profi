
#include "Header.h"

int main()
{
	std::vector<double> rmse_a;
	std::vector<double> rmse_b;
	std::vector<double> rmse_c;

	std::vector<int> a = return_table_from_file("a.csv");
	std::vector<int> b = return_table_from_file("b.csv");
	std::vector<int> c = return_rand_table(15);

	rmse_a.push_back(zero_hold(a));
	rmse_b.push_back(zero_hold(b));
	rmse_c.push_back(zero_hold(c));

	rmse_a.push_back(MovingAverage(a));
	rmse_b.push_back(MovingAverage(b));
	rmse_c.push_back(MovingAverage(c));

	/*rmse.push_back(MovingAveragek(a,3));
	rmse.push_back(MovingAveragek(b,3));
	rmse.push_back(MovingAveragek(c,3));
	*/
	rmse_a.push_back(holts_model(a, 0.1, 0.9));
	rmse_b.push_back(holts_model(b, 0.1, 0.9));
	rmse_c.push_back(holts_model(c, 0.1, 0.9));

	rmse_a.push_back(holts_model_diff(a, 0.1, 0.9));
	rmse_b.push_back(holts_model_diff(b, 0.1, 0.9));
	rmse_c.push_back(holts_model_diff(c, 0.1, 0.9));

	rmse_a.push_back(holts_model(a, 0.9, 0.1));
	rmse_b.push_back(holts_model(b, 0.9, 0.1));
	rmse_c.push_back(holts_model(c, 0.9, 0.1));

	rmse_a.push_back(holts_model_diff(a, 0.9, 0.1));
	rmse_b.push_back(holts_model_diff(b, 0.9, 0.1));
	rmse_c.push_back(holts_model_diff(c, 0.9, 0.1));

	rmse_a.push_back(holts_model(a, 0.4, 0.6));
	rmse_b.push_back(holts_model(b, 0.4, 0.6));
	rmse_c.push_back(holts_model(c, 0.9, 0.1));

	rmse_a.push_back(holts_model_diff(a, 0.4, 0.6));
	rmse_b.push_back(holts_model_diff(b, 0.4, 0.6));
	rmse_c.push_back(holts_model_diff(c, 0.4, 0.6));

	rmse_a.push_back(holts_model_t(a, 0.1, 0.9,1));
	rmse_b.push_back(holts_model_t(b, 0.1, 0.9,1));
	rmse_c.push_back(holts_model_t(c, 0.1, 0.9,1));

	rmse_a.push_back(holts_model_t_diff(a, 0.1, 0.9,1));
	rmse_b.push_back(holts_model_t_diff(b, 0.1, 0.9,1));
	rmse_c.push_back(holts_model_t_diff(c, 0.1, 0.9,1));

	rmse_a.push_back(holts_model_t(a, 0.9, 0.1,1));
	rmse_b.push_back(holts_model_t(b, 0.9, 0.1,1));
	rmse_c.push_back(holts_model_t(c, 0.9, 0.1,1));

	rmse_a.push_back(holts_model_t_diff(a, 0.9, 0.1,1));
	rmse_b.push_back(holts_model_t_diff(b, 0.9, 0.1,1));
	rmse_c.push_back(holts_model_t_diff(c, 0.9, 0.1,1));

	rmse_a.push_back(holts_model_t(a, 0.4, 0.6,1));
	rmse_b.push_back(holts_model_t(b, 0.4, 0.6,1));
	rmse_c.push_back(holts_model_t(c, 0.9, 0.1,1));

	rmse_a.push_back(holts_model_t_diff(a, 0.4, 0.6,1));
	rmse_b.push_back(holts_model_t_diff(b, 0.4, 0.6,1));
	rmse_c.push_back(holts_model_t_diff(c, 0.4, 0.6,1));


	rmse_a.push_back(holts_model_t(a, 0.1, 0.9, 2));
	rmse_b.push_back(holts_model_t(b, 0.1, 0.9, 2));
	rmse_c.push_back(holts_model_t(c, 0.1, 0.9, 2));

	rmse_a.push_back(holts_model_t_diff(a, 0.1, 0.9, 2));
	rmse_b.push_back(holts_model_t_diff(b, 0.1, 0.9, 2));
	rmse_c.push_back(holts_model_t_diff(c, 0.1, 0.9, 2));

	rmse_a.push_back(holts_model_t(a, 0.9, 0.1, 2));
	rmse_b.push_back(holts_model_t(b, 0.9, 0.1, 2));
	rmse_c.push_back(holts_model_t(c, 0.9, 0.1, 2));

	rmse_a.push_back(holts_model_t_diff(a, 0.9, 0.1, 2));
	rmse_b.push_back(holts_model_t_diff(b, 0.9, 0.1, 2));
	rmse_c.push_back(holts_model_t_diff(c, 0.9, 0.1, 2));

	rmse_a.push_back(holts_model_t(a, 0.4, 0.6, 2));
	rmse_b.push_back(holts_model_t(b, 0.4, 0.6, 2));
	rmse_c.push_back(holts_model_t(c, 0.9, 0.1, 2));

	rmse_a.push_back(holts_model_t_diff(a, 0.4, 0.6, 2));
	rmse_b.push_back(holts_model_t_diff(b, 0.4, 0.6, 2));
	rmse_c.push_back(holts_model_t_diff(c, 0.4, 0.6, 2));

	rmse_a.push_back(holts_model_t(a, 0.1, 0.9, 3));
	rmse_b.push_back(holts_model_t(b, 0.1, 0.9, 3));
	rmse_c.push_back(holts_model_t(c, 0.1, 0.9, 3));

	rmse_a.push_back(holts_model_t_diff(a, 0.1, 0.9, 3));
	rmse_b.push_back(holts_model_t_diff(b, 0.1, 0.9, 3));
	rmse_c.push_back(holts_model_t_diff(c, 0.1, 0.9, 3));

	rmse_a.push_back(holts_model_t(a, 0.9, 0.1, 3));
	rmse_b.push_back(holts_model_t(b, 0.9, 0.1, 3));
	rmse_c.push_back(holts_model_t(c, 0.9, 0.1, 3));

	rmse_a.push_back(holts_model_t_diff(a, 0.9, 0.1, 3));
	rmse_b.push_back(holts_model_t_diff(b, 0.9, 0.1, 3));
	rmse_c.push_back(holts_model_t_diff(c, 0.9, 0.1, 3));

	rmse_a.push_back(holts_model_t(a, 0.4, 0.6, 3));
	rmse_b.push_back(holts_model_t(b, 0.4, 0.6, 3));
	rmse_c.push_back(holts_model_t(c, 0.9, 0.1, 3));

	rmse_a.push_back(holts_model_t_diff(a, 0.4, 0.6, 3));
	rmse_b.push_back(holts_model_t_diff(b, 0.4, 0.6, 3));
	rmse_c.push_back(holts_model_t_diff(c, 0.4, 0.6, 3));


	std::cout << "\n\nThe analysis best for Total Costs is " << SmallestRMSE(rmse_a);
	std::cout << " which method is :";
	std::cout << holts_model_diff(a, 0.9, 0.1);
	std::cout << "\nThe analysis best for Labour Hours is " << SmallestRMSE(rmse_b);
	std::cout << " which method is :";
	std::cout << holts_model_diff(b, 0.9, 0.1);
	std::cout << "\nThe analysis best for Random Values is " << SmallestRMSE(rmse_c);
	std::cout << " which method is :";
	std::cout << holts_model_diff(c, 0.9, 0.1) << "\n";

	high_low(b,a);



	
}

