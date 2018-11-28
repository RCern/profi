#include "Header.h"

double holts_model(std::vector<int> vec, double alpha, double beta) {

	// for original data 
	std::vector<double> F;
	F.push_back(vec[0]);
	std::vector<double> S;
	S.push_back(vec[1] - vec[0]);
	std::vector<double> Ypred;
	for (int i = 1; i < vec.size(); i++)
	{
		F.push_back(alpha*vec[i] + (1 - alpha) *(F[i - 1] + S[i - 1]));
		S.push_back(beta*(F[i] - F[i - 1]) + (1 - beta)* S[i - 1]);
		Ypred.push_back(S[i - 1] + F[i - 1]);
	}

	std::cout << "\nRMSE for Holt's model with alpha: "<< alpha << " beta : "<< beta << " RMSE => " <<RMSE(vec, Ypred) << "\n\n";

	return RMSE(vec, Ypred);
}

double holts_model_diff(std::vector<int> vec, double alpha, double beta) {

	// for difference data 
	std::vector<double> F;
	F.push_back(vec[0]);
	std::vector<double> S;
	S.push_back(vec[1] - vec[0]);
	std::vector<double> Ypred;
	for (int i = 1; i < vec.size(); i++)
	{
		F.push_back(alpha*vec[i] + (1 - alpha) *(F[i - 1] + S[i - 1]));
		S.push_back(beta*(F[i] - F[i - 1]) + (1 - beta)* S[i - 1]);
		Ypred.push_back(S[i - 1] + F[i - 1]);
	}

	std::vector<int> diff;
	for (int i = 0; i < Ypred.size(); i++)
	{
		diff.push_back(Ypred[i] - vec[i]);
	}
	std::cout << "\nFor differnces\n";
	return holts_model(diff, alpha, beta);
}