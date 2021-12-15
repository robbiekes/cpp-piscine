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

void insertion_sort(std::vector<int> *array)
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
	for (unsigned long gap = array->size() / 2; gap >= 1; gap /= 2)
	{
		for (unsigned long j = gap; j < array->size(); j++)
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


void	merge(std::vector<int> *arr, int left, int mid, int right)
{
	int it1 = 0;
	int it2 = 0;

	std::vector<int> new_arr(right - left, 0);

	while (left + it1 < mid && mid + it2 < right)
	{
		if ((*arr)[left + it1] < (*arr)[mid + it2])
		{
			new_arr[it1 + it2] = (*arr)[left + it1];
			it1++;
		}
		else
		{
			new_arr[it1 + it2] = (*arr)[mid + it2];
			it2++;
		}
	}
	while (left + it1 < mid)
	{
		new_arr[it1 + it2] = (*arr)[left + it1];
		it1++;
	}
	while (mid + it2 < right)
	{
		new_arr[it1 + it2] = (*arr)[mid + it2];
		it2++;
	}
	//std::cout << '[' << it2 << ']' << '\n';
	for (int k = 0; k < it1 + it2; k++)
		(*arr)[left + k] = new_arr[k];
}

void	mergeSort(std::vector<int> *arr, int left, int right) // left, right - индексы
{
	if (left + 1 >= right)
		return ;
	
	int mid = (left + right) / 2;

	mergeSort(arr, left, mid);
	mergeSort(arr, mid, right);
	merge(arr, left, mid, right);
}

int main()
{
	std::vector<int> arr = {1, 3, 5, 7, 0, 2, 8, 10};
	mergeSort(&arr, 0, arr.size() - 1);
	for (unsigned long i = 0; i < arr.size(); i++)
		std::cout << arr[i] << ' ';
	std::cout << '\n';
	return (0);
}

