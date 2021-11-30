#include <vector> // for std::vector
#include "sorting.hpp"
#include <iostream> // for cin & cout

void print_array(std::vector<int> array)
{
	for (int i = 0; i < array.size(); i++)
		std::cout << array[i] << ' ';
	std::cout << '\n';
}

int main(void)
{
	std::vector<int> array = {3, 6, 2, 8, 2, 7, 3, 7};

	print_array(array);

	selection_sort(&array);

	print_array(array);

	return (0);
}
