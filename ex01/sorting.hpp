#ifndef SORTING_HPP
#define SORTING_HPP

#include <vector>
#include <iostream>

#define DEBUG(x) {\
	std::cout << __FILE__ << " " << __FUNCTION__ << " (line " << __LINE__ << "):\t" << #x << " = " << x << std::endl;\
}

void selection_sort(std::vector<int> *array);
void selection_sort(std::vector<int> *array, int start, int end);
void swap(int *a, int *b);
void shell_sort(std::vector<int> *array);
void insertion_sort(std::vector<int> *array);

#endif // SORTING_HPP
