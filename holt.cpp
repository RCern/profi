#include "Header.h"

void holts_model(std::vector<int> vec, double alpha, double beta) {

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

	std::cout << "F:" << "\n";
	affichage(F);
	std::cout << "S:" << "\n";
	affichage(S);
	std::cout << "Ypred:" << "\n";
	affichage(Ypred);

	// for differences
	std::vector<double> diff;
	for (int i = 0; i < Ypred.size(); i++)
	{
		diff.push_back(vec[i] - Ypred[i]);
	}
	std::cout << "RMSE " << RMSE(diff) << "\n";
	std::vector<double> F_diff;
	F_diff.push_back(diff[0]);
	std::vector<double> S_diff;
	S_diff.push_back(diff[1] - diff[0]);
	std::vector<double> Ypred_diff;

	for (int i = 1; i < diff.size(); i++)
	{
		F_diff.push_back(alpha*diff[i] + (1 - alpha) *(F_diff[i - 1] + S_diff[i - 1]));
		S_diff.push_back(beta*(F_diff[i] - F_diff[i - 1]) + (1 - beta)* S_diff[i - 1]);
		Ypred_diff.push_back(S_diff[i - 1] + F_diff[i - 1]);
	}
	
	std::cout << "F_diff:" << "\n";
	affichage(F_diff);
	std::cout << "S_diff:" << "\n";
	affichage(S_diff);
	std::cout << "Ypred_diff:" << "\n";
	affichage(Ypred_diff);


}