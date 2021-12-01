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

void inclusion_sort(std::vector<int> *array)
{
	for (unsigned long i = 1; i < array->size() - 1; i++)
	{
		int j = i - 1;
		while (j >= 0 && (*array)[j] > (*array)[j + 1])
		{
			swap(&(*array)[j], &(*array)[j + 1]);
			j--;
		}
	}
}

void shell_sort(std::vector<int> *array)
{
	for (int gap = array->size() / 2; gap >= 1; gap /= 2)
	{
		for (int j = gap; j <= array->size(); j++)
		{
			for (int i = j - gap; i >= 0; i -= gap)
			{
				if ((*array)[i + gap] < (*array)[i])
					swap(&(*array)[i + gap], &(*array)[i]);
				else
					break;
			}
		}
	}
}
	