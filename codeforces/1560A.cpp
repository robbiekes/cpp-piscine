#include <iostream>
#include <vector>

void	display_num(int num)
{
	int output = 0;
	int i = 0;
	while (i < num + 1)
	{
	//	std::cout << output << '\n';
		if ((output % 10) != 3 && (output % 3 != 0))
		{
			std::cout << '[' << output << ']' << '\n';
			i++;
		}
		output++;
	}
	std::cout << i - 1 << " - " << output - 1 << '\n';
}

int main(void)
{
	int input = 0;
	std::cin >> input;
	display_num(input);
}