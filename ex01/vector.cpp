#include <vector> // for std::vector
#include <iostream> // for cin & cout

int main(void)
{
	std::vector<std::string> array = {"i", "know", "you", "i walked", "with", "you"};
	// array.push_back(1);
	// array.push_back(2);
	// array.push_back(3);
	// array.push_back(4);
	// array.push_back(5);
	for (int i = 0; i < array.size(); i++)
		std::cout << array[i] << ' ';
	array[4] = "once";
	std::cout << '\n';
	for (int i = 0; i < array.size(); i++)
		std::cout << array[i] << ' ';
	// std::cout << "enter a number: ";
	// int a = 0;
	// std::cin >> a;
	// std::cout << "you entered " << a;
	return (0);
}
