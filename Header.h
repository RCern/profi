#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <cmath>

int generate_rand();

std::vector<int> return_rand_table(int size);

void affichage(std::vector<double> a);

double RMSE(std::vector<double> diff);

std::vector<int> return_table_from_file(std::string path_name);


void holts_model(std::vector<int> vec, double alpha, double beta);
