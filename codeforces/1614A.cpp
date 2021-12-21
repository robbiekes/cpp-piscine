#include <iostream>
#include <vector>

int max_num(std::vector<int> &arr, int limit)
{
	int max = -9999, i = 0;
	for (i = 0; i < arr.size(); i++)
	{
		if (arr[i] >= max && arr[i] <= limit)
			max = arr[i];
	}
	return max;
}

int min_num(std::vector<int> arr, int limit)
{
	int min = 9999;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] < min && arr[i] > limit)
			min = arr[i];
	} 
	return min;
}

void	min_sweets(int amount, int low, int high, int budget, std::vector<int> &pricelist)
{
	//std::cout << amount << " " << min << " " << max << " " << budget;
	int final_price = 0, count = 0;
	for (int i = 0; i < pricelist.size(); i++)
	{
		int max = max_num(pricelist, high);
		if (final_price < budget)
		{
			final_price += max;
			count++;
		}
		std::cout << pricelist[i] << "\n";
		pricelist[i] = 0;
		i++;
	}
	// for (int c = 0; c < pricelist.size(); c++)
	// 	std::cout << pricelist[c];
	//std::cout << count << " " << final_price;
}

int main(int argc, char **argv)
{
	std::vector<int> pricelist;
	int amount = 0, min = 0, max = 0, budget = 0, c = 0;
	std::cin >> amount >> min >> max >> budget;
	pricelist.resize(amount);
	for (c = 0; c < amount; c++)
		std::cin >> pricelist[c];
	min_sweets(amount, min, max, budget, pricelist);
}