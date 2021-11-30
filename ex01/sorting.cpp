#include "sorting.hpp"
#include <iostream> // for cin & cout

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void selection_sort(std::vector<int> *array)
{
	for (unsigned long i = 0; i < array->size() - 1; i++)
	{
		for (unsigned long j = i + 1; j < array->size(); j++)
		{
			if ((*array)[j] < (*array)[i])
				swap(&(*array)[i], &(*array)[j]);
		}
	}
}

void shell_sort(std::vector<int> *array)
{

}