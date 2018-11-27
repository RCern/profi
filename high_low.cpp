#include "Header.h"


void high_low(std::vector<int> labour, std::vector<int> t_costs) {
	int min_pos = std::distance(t_costs.begin(), std::min_element(t_costs.begin(), t_costs.end()));
	std::cout << "For Lowest: " << "\n";
	std::cout << "Month: " <<min_pos + 1 << "\n";
	int min_cost = t_costs[min_pos];
	std::cout << "Total costs: " << min_cost << "\n";
	int min_lab = labour[min_pos];
	std::cout << "Labour Hours: " <<  min_lab << "\n";

	int max_pos = std::distance(t_costs.begin(), std::max_element(t_costs.begin(), t_costs.end()));
	std::cout << "For Highest: " << "\n";
	std::cout << "Month: " << max_pos + 1 << "\n";
	int max_cost = t_costs[max_pos];
	std::cout << "Total costs: " << max_cost << "\n";
	int max_lab = labour[max_pos];
	std::cout << "Labour Hours: " << max_lab << "\n";

	int diff_lab = max_lab - min_lab;
	int diff_costs = max_cost - min_cost;

	std::cout << "Difference Labour Hours: " << diff_lab << "\n";
	std::cout << "Differnce Total Costs: " << diff_costs << "\n";

	int var_cost = diff_costs / diff_lab;
	int tot_fix_cost = max_cost - (var_cost*max_lab);
	std::cout << "Varialbe cost: " << var_cost << "\n";
	std::cout << "Total fixed cost: " << tot_fix_cost << "\n";
	std::cout << "y= " << tot_fix_cost << " + " << var_cost << "x" << "\n";
}