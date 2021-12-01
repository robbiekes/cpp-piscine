#ifndef SORTING_HPP
#define SORTING_HPP

#include <vector>
#include <iostream>

void selection_sort(std::vector<int> *array);
void selection_sort(std::vector<int> *array, int start, int end);
void swap(int *a, int *b);
void shell_sort(std::vector<int> *array);

#endif // SORTING_HPP
