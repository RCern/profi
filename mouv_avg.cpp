#include "Header.h"

std::vector<double> MovingAveragek(std::vector<int> vec, int k)
{
	std::vector<double> Id(vec.size());
	int i, j;
	int test;
	for (i = 0; i < vec.size() - k; i++)//Moving average with k adjusted
	{
		test = 0;
		for (j = i; j < k + i; j++)
			test += vec[j];
		Id[i + k] = test / k;
	}
	return Id;
}

double MovingAverage(std::vector<int>vec)//Test every moving average
{
	int i;
	std::vector<double> RMSE_MA(vec.size());
	for (i = 2; i < vec.size() - 1; i++)
		RMSE_MA[i - 2] = RMSE(vec, MovingAveragek(vec, i));
	return SmallestRMSE(RMSE_MA);//Only returns the one with the smallest RMSE in terms of k
}