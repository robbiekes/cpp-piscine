#include "sorting.hpp"
#include <iostream> // for cin & cout

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// void selection_sort(std::vector<int> *array)
// {
// 	for (unsigned long i = 0; i < array->size() - 1; i++)
// 	{
// 		for (unsigned long j = i + 1; j < array->size(); j++)
// 		{
// 			if ((*array)[j] < (*array)[i])
// 				swap(&(*array)[i], &(*array)[j]);
// 		}
// 	}
// }

// void insertion_sort(std::vector<int> *array)
// {
// 	for (unsigned long i = 1; i < array->size() - 1; i++)
// 	{
// 		int j = i - 1;
// 		while (j >= 0 && (*array)[j] > (*array)[j + 1])
// 		{
// 			swap(&(*array)[j], &(*array)[j + 1]);
// 			j--;
// 		}
// 	}
// }

// void shell_sort(std::vector<int> *array)
// {
// 	for (unsigned long gap = array->size() / 2; gap >= 1; gap /= 2)
// 	{
// 		for (unsigned long j = gap; j < array->size(); j++)
// 		{
// 			for (int i = j - gap; i >= 0; i -= gap)
// 			{
// 				if ((*array)[i + gap] < (*array)[i])
// 					swap(&(*array)[i + gap], &(*array)[i]);
// 				else
// 					break;
// 			}
// 		}
// 	}
// }


void merge(std::vector<int> *arr, int left, int right, int middle)
{
	int i = left; // starting index for left subarray
	int j = middle + 1; // starting index for right subarray
	int k = 0; // starting index for temporary array;
	
	DEBUG(i);
	DEBUG(j);

	std::vector<int> temp_arr(arr->size(), 0);

	while (i <= middle || j <= right)
	{
		if (j == right + 1 || ( i != middle + 1 && (*arr)[i] < (*arr)[j]))
		{
			temp_arr[k] = (*arr)[i];
			i++;
			k++;
		}
		else
		{
			temp_arr[k] = (*arr)[j];
			j++;
			k++;
		}
	}

	i = left;
	j = middle + 1;
	while (i <= middle)
	{
		temp_arr[k] = (*arr)[i]; // copying all elements from left subarray to temp_arr
		k++;
		i++;
	}
	while (j <= right)
	{
		temp_arr[k] = (*arr)[j]; // copying all elements from right subarray to temp_arr
		j++;
		k++;
	}
	for (int s = left; s <= right; s++)
		(*arr)[s] = temp_arr[s];
}

void mergeSort(std::vector<int> *arr, int left, int right)
{
	// exit from recursion
	if (right - left < 3 && (*arr)[left] > (*arr)[right])
		swap(&(*arr)[left], &(*arr)[right]);
	if (right - left == 2)
	{
		if ((*arr)[left + 1] > (*arr)[right])
			swap(&(*arr)[left + 1], &(*arr)[right]);
		if ((*arr)[left] > (*arr)[right - 1])
			swap(&(*arr)[left], &(*arr)[right - 1]);
	}
	if (right)
	if (right - left < 3)
		return;

	int middle = (left + right) / 2;

	DEBUG(middle);

	mergeSort(arr, left, middle);
	mergeSort(arr, middle + 1, right);
	merge(arr, left, right, middle);
}

int main()
{
	std::vector<int> arr = {1, 5, 3, 7, 2, 3, 8, 10};
	// merge(&arr, 0, 8, 3);
	mergeSort(&arr, 0, arr.size() - 1);
	for (unsigned long i = 0; i < arr.size(); i++)
		std::cout << arr[i] << ' ';
	std::cout << '\n';
	return (0);
}

