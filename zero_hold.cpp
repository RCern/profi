#include "Header.h"

double zero_hold(std::vector<int> vec)
{
	std::vector<double> Zh(vec.size());
	int i;
	for (i = 0; i < vec.size(); i++)
		printf("%d ", vec[i]);

	printf("\n");
	for (i = 1; i < vec.size(); i++)
		Zh[i] = vec[i - 1];
	for (i = 0; i < vec.size(); i++)
		printf("%lf ", Zh[i]);

	printf("\n");
	printf("%lf", RMSE(vec, Zh));
	return RMSE(vec, Zh);
}