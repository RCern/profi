#include "Header.h"

void menu() {
	int choice = 0;
	std::vector<double> rmse;
	std::vector<int> a = return_table_from_file("a.csv");
	std::vector<int> b = return_table_from_file("b.csv");
	std::vector<int> c = return_rand_table(15);
	do {
		std::cout << "Choose one of the following:\n1)ZOH\n2)Moving average\n3)Holt's Model\n4)Holt's model with horizon\n5)Perform analysis of RMSE\n6)High-low method\n7)EXIT\n";
		std::cin >> choice;
		switch (choice)
		{
		case 1:
		{

			std::cout << "Choose input data:\n1)Random data\n2)Labour Hours\n3)Total costs\n";
			int y;
			std::cin >> y;
			switch (y)
			{
			case 1:
			{
				rmse.push_back(zero_hold(c));
				break;
			}
			case 2:
			{
				rmse.push_back(zero_hold(b));
				break;
			}
			case 3:
			{
				rmse.push_back(zero_hold(a));
				break;
			}
			default:
				break;
			}
		}
		case 2:
		{

			std::cout << "Choose input data:\n1)Random data\n2)Labour Hours\n3)Total costs\n";
			int z;
			std::cin >> z;
			switch (z)
			{
			case 1:
			{
				rmse.push_back(MovingAverage(c));
				break;
			}
			case 2:
			{
				rmse.push_back(MovingAverage(c));
				break;
			}
			case 3:
			{
				rmse.push_back(MovingAverage(c));
				break;
			}
			default:
				break;
			}
		}
		case 3:
		{

			std::cout << "Choose input data:\n1)Random data\n2)Labour Hours\n3)Total costs\n";
			int x;
			std::cin >> x;
			switch (x)
			{
			case 1:
			{
				rmse.push_back(holts_model(c, 0.1, 0.9));
				rmse.push_back(holts_model(c, 0.9, 0.1));
				rmse.push_back(holts_model(c, 0.4, 0.6));

				rmse.push_back(holts_model_diff(c, 0.1, 0.9));
				rmse.push_back(holts_model_diff(c, 0.9, 0.1));
				rmse.push_back(holts_model_diff(c, 0.4, 0.6));
				break;

			}
			case 2:
			{
				rmse.push_back(holts_model(b, 0.1, 0.9));
				rmse.push_back(holts_model(b, 0.9, 0.1));
				rmse.push_back(holts_model(b, 0.4, 0.6));

				rmse.push_back(holts_model_diff(b, 0.1, 0.9));
				rmse.push_back(holts_model_diff(b, 0.9, 0.1));
				rmse.push_back(holts_model_diff(b, 0.4, 0.6));
				break;

			}
			case 3:
			{
				rmse.push_back(holts_model(a, 0.1, 0.9));
				rmse.push_back(holts_model(a, 0.9, 0.1));
				rmse.push_back(holts_model(a, 0.4, 0.6));

				rmse.push_back(holts_model_diff(a, 0.1, 0.9));
				rmse.push_back(holts_model_diff(a, 0.9, 0.1));
				rmse.push_back(holts_model_diff(a, 0.4, 0.6));
				break;
			}
			default:
				break;
			}


		}

		default:
			break;
		}
		} while (choice != 7);
		
	}


