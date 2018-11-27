#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iterator>

int generate_rand();

std::vector<int> return_rand_table(int size);

void affichage(std::vector<double> a);

double RMSE(std::vector<int> org, std::vector<double> pred);

std::vector<int> return_table_from_file(std::string path_name);

double holts_model(std::vector<int> vec, double alpha, double beta);

double holts_model_t(std::vector<int> vec, double alpha, double beta, int t);	

void high_low(std::vector<int> labour, std::vector<int> t_costs);

std::vector<double> MovingAveragek(std::vector<int> vec, int k);

double MovingAverage(std::vector<int>vec);

double SmallestRMSE(std::vector<double>rmse);