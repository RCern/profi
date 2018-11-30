#include"Header.h"

double holts_model_t(std::vector<int> vec, double alpha, double beta, int t) {

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
		Ypred.push_back(t*S[i - 1] + F[i - 1]);
	}

	std::cout << "\nRMSE for Holt's model with horizon : "<< t <<" alpha: " << alpha << " beta : " << beta << " RMSE => " << RMSE(vec, Ypred);
	return RMSE(vec, Ypred);
}

double holts_model_t_diff(std::vector<int> vec, double alpha, double beta, int t) {

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
		Ypred.push_back(t*S[i - 1] + F[i - 1]);
	}

	std::vector<int> diff;
	for (int i = 0; i < Ypred.size(); i++)
	{
		diff.push_back(Ypred[i] - vec[i]);
	}
	return holts_model_t(diff,alpha,beta,t);
}

void PrintAllHolt(std::vector<int>c)
{
	std::vector<double>rmse;
	std::cout << "For Original Data\ntau=1\n";
	rmse.push_back(holts_model_t(c, 0.1, 0.9, 1));
	rmse.push_back(holts_model_t(c, 0.9, 0.1, 1));
	rmse.push_back(holts_model_t(c, 0.4, 0.6, 1));
	std::cout << "\ntau=2";
	rmse.push_back(holts_model_t(c, 0.1, 0.9, 2));
	rmse.push_back(holts_model_t(c, 0.9, 0.1, 2));
	rmse.push_back(holts_model_t(c, 0.4, 0.6, 2));
	std::cout << "\ntau=3";
	rmse.push_back(holts_model_t(c, 0.1, 0.9, 3));
	rmse.push_back(holts_model_t(c, 0.9, 0.1, 3));
	rmse.push_back(holts_model_t(c, 0.4, 0.6, 3));
	std::cout << "\nFor Differences\ntau=1";
	rmse.push_back(holts_model_t_diff(c, 0.1, 0.9, 1));
	rmse.push_back(holts_model_t_diff(c, 0.9, 0.1, 1));
	rmse.push_back(holts_model_t_diff(c, 0.4, 0.6, 1));
	std::cout << "\ntau=2";
	rmse.push_back(holts_model_t_diff(c, 0.1, 0.9, 2));
	rmse.push_back(holts_model_t_diff(c, 0.9, 0.1, 2));
	rmse.push_back(holts_model_t_diff(c, 0.4, 0.6, 2));
	std::cout << "\ntau=3";
	rmse.push_back(holts_model_t_diff(c, 0.1, 0.9, 3));
	rmse.push_back(holts_model_t_diff(c, 0.9, 0.1, 3));
	rmse.push_back(holts_model_t_diff(c, 0.4, 0.6, 3));
}