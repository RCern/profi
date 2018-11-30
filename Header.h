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

void menu();

std::vector<int> return_rand_table(int size);

void affichage(std::vector<double> a);

double RMSE(std::vector<int> org, std::vector<double> pred);

std::vector<int> return_table_from_file(std::string path_name);

double holts_model(std::vector<int> vec, double alpha, double beta);

double holts_model_diff(std::vector<int> vec, double alpha, double beta);

double holts_model_t(std::vector<int> vec, double alpha, double beta, int t);	

double holts_model_t_diff(std::vector<int> vec, double alpha, double beta, int t);

void high_low(std::vector<int> labour, std::vector<int> t_costs);

double zero_hold(std::vector<int> vec);

int display_smallest_rmse(std::vector<double> rmse);

std::vector<double> MovingAveragek(std::vector<int> vec, int k);

double MovingAverage(std::vector<int>vec);

double SmallestRMSE(std::vector<double>rmse);

void affichageInt(std::vector<int> a);

void DeclareSmallestRMSE(std::vector<double>rmse, double smallest);

void PrintSmallestRMSE(std::vector<double>rmse, int i);

void PrintAllRMSE(std::vector<int>c, int serie);

void PrintAllHolt(std::vector<int>);

void PrintHolt(std::vector<int> c);