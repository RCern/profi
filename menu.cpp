#include "Header.h"
int secondmenu(std::vector<int> a, std::vector<int> b, std::vector<int> c)
{
	std::cout << "Choose input data:\n1)Random data\n2)Labour Hours\n3)Total costs\n";
	int y;
	std::cin >> y;
	switch (y)
	{
	case 1:
		affichageInt(c);
		break;
	case 2:
		affichageInt(b);
		break;
	case 3:
		affichageInt(a);
		break;
	default:
		break;
	};
	return y;
}
void menu() {
	int choice = 0;
	int x;
	double SmRMSE;
	std::vector<double> rmse;
	std::vector<int> a = return_table_from_file("a.csv");
	std::vector<int> b = return_table_from_file("b.csv");
	std::vector<int> c = return_rand_table(15);
	do {
		rmse.clear();
		std::cout <<"\nChoose one of the following:\n1)ZOH\n2)Moving average\n3)Holt's Model\n4)Holt's model with horizon\n5)Perform analysis of RMSE\n6)High-low method\n7)EXIT\n";
		std::cin >> choice;
		if(choice!=6 && choice!=7)
		x = secondmenu(a, b, c);
		switch (choice)
		{
		case 1:
		{
			if(x==1)
				rmse.push_back(zero_hold(c));
			if(x==2)
				rmse.push_back(zero_hold(b));
			if(x==3)
				rmse.push_back(zero_hold(a));
			std::cout << "RMSE = " << rmse[rmse.size() - 1] << "\n";
			break;
		}
		case 2:
		{
			if(x==1)
				rmse.push_back(MovingAverage(c));
			if (x == 2)
			{
				int value;
				do
				{
					std::cout << "Please enter a value for moving average k:\n";
					std::cin >> value;
				} while (value<0 || value>b.size());
				rmse.push_back(RMSE(b, MovingAveragek(b, value)));
			}
			if (x == 3)
			{
				int value;
				do
				{
					std::cout << "Please enter a value for k:\n";
					std::cin >> value;
				} while (value<0 || value>b.size());
				rmse.push_back(RMSE(a, MovingAveragek(a, value)));
			}
			std::cout << "RMSE = " << rmse[rmse.size() - 1] <<"\n";
			break;
		}
		case 3:
		{
			if(x==1)
			{
				rmse.push_back(holts_model(c, 0.1, 0.9));
				rmse.push_back(holts_model(c, 0.9, 0.1));
				rmse.push_back(holts_model(c, 0.4, 0.6));

				std::cout << "\nFor differences\n";

				rmse.push_back(holts_model_diff(c, 0.1, 0.9));
				rmse.push_back(holts_model_diff(c, 0.9, 0.1));
				rmse.push_back(holts_model_diff(c, 0.4, 0.6));
			}
			if(x==2)
			{
				rmse.push_back(holts_model(b, 0.1, 0.9));
				rmse.push_back(holts_model(b, 0.9, 0.1));
				rmse.push_back(holts_model(b, 0.4, 0.6));

				std::cout << "\nFor differences\n";

				rmse.push_back(holts_model_diff(b, 0.1, 0.9));
				rmse.push_back(holts_model_diff(b, 0.9, 0.1));
				rmse.push_back(holts_model_diff(b, 0.4, 0.6));
			}
			if (x == 3)
			{
				rmse.push_back(holts_model(a, 0.1, 0.9));
				rmse.push_back(holts_model(a, 0.9, 0.1));
				rmse.push_back(holts_model(a, 0.4, 0.6));
				
				std::cout << "\nFor differences\n";

				rmse.push_back(holts_model_diff(a, 0.1, 0.9));
				rmse.push_back(holts_model_diff(a, 0.9, 0.1));
				rmse.push_back(holts_model_diff(a, 0.4, 0.6));
			}
			break;

		}
		case 4:
		{
			if (x == 1)
			{
				std::cout <<"For Original Data\ntau=1\n";
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
				std::cout <<"\nFor Differences\ntau=1";
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
			if (x == 2)
			{
				std::cout << "For Original Data\ntau=1\n";
				rmse.push_back(holts_model_t(b, 0.1, 0.9, 1));
				rmse.push_back(holts_model_t(b, 0.9, 0.1, 1));
				rmse.push_back(holts_model_t(b, 0.4, 0.6, 1));
				std::cout << "\ntau=2";
				rmse.push_back(holts_model_t(b, 0.1, 0.9, 2));
				rmse.push_back(holts_model_t(b, 0.9, 0.1, 2));
				rmse.push_back(holts_model_t(b, 0.4, 0.6, 2));
				std::cout << "\ntau=3";
				rmse.push_back(holts_model_t(b, 0.1, 0.9, 3));
				rmse.push_back(holts_model_t(b, 0.9, 0.1, 3));
				rmse.push_back(holts_model_t(b, 0.4, 0.6, 3));
				std::cout << "\nFor Differences\ntau=1";
				rmse.push_back(holts_model_t_diff(b, 0.1, 0.9, 1));
				rmse.push_back(holts_model_t_diff(b, 0.9, 0.1, 1));
				rmse.push_back(holts_model_t_diff(b, 0.4, 0.6, 1));
				std::cout << "\ntau=2";
				rmse.push_back(holts_model_t_diff(b, 0.1, 0.9, 2));
				rmse.push_back(holts_model_t_diff(b, 0.9, 0.1, 2));
				rmse.push_back(holts_model_t_diff(b, 0.4, 0.6, 2));
				std::cout << "\ntau=3";
				rmse.push_back(holts_model_t_diff(b, 0.1, 0.9, 3));
				rmse.push_back(holts_model_t_diff(b, 0.9, 0.1, 3));
				rmse.push_back(holts_model_t_diff(b, 0.4, 0.6, 3));

			}
			if (x == 3)
			{
				std::cout << "For Original Data\ntau=1\n";
				rmse.push_back(holts_model_t(a, 0.1, 0.9, 1));
				rmse.push_back(holts_model_t(a, 0.9, 0.1, 1));
				rmse.push_back(holts_model_t(a, 0.4, 0.6, 1));
				std::cout << "\ntau=2";
				rmse.push_back(holts_model_t(a, 0.1, 0.9, 2));
				rmse.push_back(holts_model_t(a, 0.9, 0.1, 2));
				rmse.push_back(holts_model_t(a, 0.4, 0.6, 2));
				std::cout << "\ntau=3";
				rmse.push_back(holts_model_t(a, 0.1, 0.9, 3));
				rmse.push_back(holts_model_t(a, 0.9, 0.1, 3));
				rmse.push_back(holts_model_t(a, 0.4, 0.6, 3));
				std::cout << "\nFor Differences\ntau=1";
				rmse.push_back(holts_model_t_diff(a, 0.1, 0.9, 1));
				rmse.push_back(holts_model_t_diff(a, 0.9, 0.1, 1));
				rmse.push_back(holts_model_t_diff(a, 0.4, 0.6, 1));
				std::cout << "\ntau=2";
				rmse.push_back(holts_model_t_diff(a, 0.1, 0.9, 2));
				rmse.push_back(holts_model_t_diff(a, 0.9, 0.1, 2));
				rmse.push_back(holts_model_t_diff(a, 0.4, 0.6, 2));
				std::cout << "\ntau=3";
				rmse.push_back(holts_model_t_diff(a, 0.1, 0.9, 3));
				rmse.push_back(holts_model_t_diff(a, 0.9, 0.1, 3));
				rmse.push_back(holts_model_t_diff(a, 0.4, 0.6, 3));

			}
			break;
		}
		case 5:
		{
			if (x == 1)
			{
				rmse.push_back(zero_hold(c));
				std::cout << "\nRMSE for Zero-order-hold method RMSE => " << rmse[rmse.size() - 1]<< "\n";
				rmse.push_back(MovingAverage(c));
				std::cout << "RMSE for Moving average method RMSE => " << rmse[rmse.size() - 1] << "\n";
				std::cout << "For Original Data\n";
				rmse.push_back(holts_model(c, 0.1, 0.9));
				rmse.push_back(holts_model(c, 0.9, 0.1));
				rmse.push_back(holts_model(c, 0.4, 0.6));
				rmse.push_back(holts_model_t(c, 0.1, 0.9, 2));
				rmse.push_back(holts_model_t(c, 0.9, 0.1, 2));
				rmse.push_back(holts_model_t(c, 0.4, 0.6, 2));
				rmse.push_back(holts_model_t(c, 0.1, 0.9, 3));
				rmse.push_back(holts_model_t(c, 0.9, 0.1, 3));
				rmse.push_back(holts_model_t(c, 0.4, 0.6, 3));

				std::cout << "\nFor differences\n";

				rmse.push_back(holts_model_diff(c, 0.1, 0.9));
				rmse.push_back(holts_model_diff(c, 0.9, 0.1));
				rmse.push_back(holts_model_diff(c, 0.4, 0.6));
				rmse.push_back(holts_model_t_diff(c, 0.1, 0.9, 2));
				rmse.push_back(holts_model_t_diff(c, 0.9, 0.1, 2));
				rmse.push_back(holts_model_t_diff(c, 0.4, 0.6, 2));
				rmse.push_back(holts_model_t_diff(c, 0.1, 0.9, 3));
				rmse.push_back(holts_model_t_diff(c, 0.9, 0.1, 3));
				rmse.push_back(holts_model_t_diff(c, 0.4, 0.6, 3));
				SmRMSE = SmallestRMSE(rmse);
				DeclareSmallestRMSE(rmse, SmRMSE);
			}
			if (x == 2)
			{
				int value;
				do
				{
					std::cout << "Please enter a value for moving average k:\n";
					std::cin >> value;
				} while (value<0 || value>b.size());
				rmse.push_back(zero_hold(c));
				std::cout << "\nRMSE for Zero-order-hold method RMSE => " << rmse[rmse.size() - 1] << "\n";
				rmse.push_back(RMSE(b, MovingAveragek(b, value)));
				std::cout << "RMSE for Moving average method RMSE => " << rmse[rmse.size() - 1] << "\n";
				std::cout << "For Original Data\n";
				rmse.push_back(holts_model(b, 0.1, 0.9));
				rmse.push_back(holts_model(b, 0.9, 0.1));
				rmse.push_back(holts_model(b, 0.4, 0.6));
				rmse.push_back(holts_model_t(b, 0.1, 0.9, 2));
				rmse.push_back(holts_model_t(b, 0.9, 0.1, 2));
				rmse.push_back(holts_model_t(b, 0.4, 0.6, 2));
				rmse.push_back(holts_model_t(b, 0.1, 0.9, 3));
				rmse.push_back(holts_model_t(b, 0.9, 0.1, 3));
				rmse.push_back(holts_model_t(b, 0.4, 0.6, 3));
				std::cout << "\nFor differences\n";

				rmse.push_back(holts_model_diff(b, 0.1, 0.9));
				rmse.push_back(holts_model_diff(b, 0.9, 0.1));
				rmse.push_back(holts_model_diff(b, 0.4, 0.6));
				rmse.push_back(holts_model_t_diff(b, 0.1, 0.9, 2));
				rmse.push_back(holts_model_t_diff(b, 0.9, 0.1, 2));
				rmse.push_back(holts_model_t_diff(b, 0.4, 0.6, 2));
				rmse.push_back(holts_model_t_diff(b, 0.1, 0.9, 3));
				rmse.push_back(holts_model_t_diff(b, 0.9, 0.1, 3));
				rmse.push_back(holts_model_t_diff(b, 0.4, 0.6, 3));
				SmRMSE=SmallestRMSE(rmse);
				DeclareSmallestRMSE(rmse, SmRMSE);
			}
			if (x == 3)
			{
				int value;
				do
				{
					std::cout << "Please enter a value for k:\n";
					std::cin >> value;
				} while (value<0 || value>a.size());

				rmse.push_back(zero_hold(a));
				std::cout << "\nRMSE for Zero-order-hold method RMSE => " << rmse[rmse.size() - 1] << "\n";
				rmse.push_back(RMSE(a, MovingAveragek(a, value)));
				std::cout << "RMSE for Moving average method RMSE => " << rmse[rmse.size() - 1] << "\n";
				std::cout << "For Original Data\n";
				rmse.push_back(holts_model(a, 0.1, 0.9));
				rmse.push_back(holts_model(a, 0.9, 0.1));
				rmse.push_back(holts_model(a, 0.4, 0.6));
				rmse.push_back(holts_model_t(a, 0.1, 0.9, 2));
				rmse.push_back(holts_model_t(a, 0.9, 0.1, 2));
				rmse.push_back(holts_model_t(a, 0.4, 0.6, 2));
				rmse.push_back(holts_model_t(a, 0.1, 0.9, 3));
				rmse.push_back(holts_model_t(a, 0.9, 0.1, 3));
				rmse.push_back(holts_model_t(a, 0.4, 0.6, 3));

				std::cout << "\nFor differences\n";

				rmse.push_back(holts_model_diff(a, 0.1, 0.9));
				rmse.push_back(holts_model_diff(a, 0.9, 0.1));
				rmse.push_back(holts_model_diff(a, 0.4, 0.6));
				rmse.push_back(holts_model_t_diff(a, 0.1, 0.9, 2));
				rmse.push_back(holts_model_t_diff(a, 0.9, 0.1, 2));
				rmse.push_back(holts_model_t_diff(a, 0.4, 0.6, 2));
				rmse.push_back(holts_model_t_diff(a, 0.1, 0.9, 3));
				rmse.push_back(holts_model_t_diff(a, 0.9, 0.1, 3));
				rmse.push_back(holts_model_t_diff(a, 0.4, 0.6, 3));
				SmRMSE = SmallestRMSE(rmse);
				DeclareSmallestRMSE(rmse, SmRMSE);
			}
			break;		
		}
		case 6:
		{
			std::cout << "\n";
			high_low(b, a);
		}

		default:
			break;
		}
		} while (choice != 7);
		
	}


