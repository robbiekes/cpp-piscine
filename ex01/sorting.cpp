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


void merge(std::vector<int> arr, int left, int right, int middle)
{
	int i = left; // starting index for left subarray
	int j = middle+1; // starting index for right subarray
	int k = left; // starting index for temporary array;

	std::vector<int> temp_arr;

	while (i <= middle && j <= right)
	{
		if (arr[i] < arr[j])
		{
			temp_arr[k] = arr[i];
			i++;
			k++;
		}
		else
		{
			temp_arr[k] = arr[j];
			j++;
			k++;
		}
	}
	for (unsigned long t = 0; t < temp_arr.size(); t++)
			std::cout << temp_arr[t] << ' ';
	while (i <= middle)
	{
		temp_arr[k] = arr[i]; // copying all elements from left subarray to temp_arr
		k++;
		i++;
	}
	while (j <= right)
	{
		temp_arr[k] = arr[j]; // copying all elements from right subarray to temp_arr
		j++;
		k++;
	}
	for (int s = left; s <= right; s++)
		arr[s] = temp_arr[s];
}

void mergeSort(std::vector<int> arr, int left, int right)
{
    // exit from recursion
    if(arr.size() < 2) return;

    int middle = (left + right)/ 2;

    mergeSort(arr, left, middle);
    mergeSort(arr, middle + 1, right);
    merge(arr, left, right, middle);
	return ;
}

int main()
{
	std::vector<int> arr = {34, 1, -4, 0, 400, 10};
	mergeSort(arr, 0, arr.size()-1);
	for (unsigned long i = 0; i < arr.size(); i++)
		std::cout << arr[i] << ' ';
	std::cout << '\n';
	return (0);
}

