#include "Header.h"

double zero_hold(std::vector<int> vec)
{
	std::vector<double> Zh(vec.size());
	int i;
	for (i = 1; i < vec.size(); i++)
		Zh[i] = vec[i - 1];
	return RMSE(vec, Zh);	
}