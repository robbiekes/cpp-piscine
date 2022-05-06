#include <cstddef>
#include <iostream>

template <typename T, typename U>

T* copy_n(T* dst, U* src, int size)
{
	for (int i = 0; i < size; i++)
		dst[i] = (T) src[i];
	return dst;
}

#include <iomanip>

int main()
{
	int ints[] = {1, 2, 3, 4};
	double doubles[4] = {};
	copy_n(doubles, ints, 4);
	// int a = 5;
	// double b = 0;
	// b = (double) a;
	printf("%.1f %.1f %.1f %.1f\n", doubles[0], doubles[1], doubles[2], doubles[3]);
	// std::cout << std::fixed << std::setprecision(1) << doubles[0] << "\n";
	// std::cout << doubles[0] << " " << doubles[1] << " " << doubles[2] << " " << doubles[3];
}