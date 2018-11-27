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

	std::cout << "Ypred:" << "\n" << "\n";
	affichage(Ypred);

	
	std::cout << "RMSE " << RMSE(vec,Ypred) << "\n" << "\n";
	return RMSE(vec, Ypred);
}