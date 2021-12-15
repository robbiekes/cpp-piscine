#include <iostream>
#include <vector>

void	display_num(int *numbers)
{
	int	count;
	int i = 0;
	int index = 0;
	int output = 0;

	while (numbers[i])
	{
		count = 0;
		index = 0;
		while (index < numbers[i])
		{
			if ((count % 10) != 3 && (count % 3 != 0))
			{
				output = count;
				index++;
			}
			count++;
		}
		std::cout << output << '\n';
		i++;
	}
}

int main(void)
{
	int i = 0;
	int data_amount = 0;
	int numbers[101] = {0};
	std::cin >> data_amount;
	while (i < data_amount)
	{
		std::cin >> numbers[i];
		i++;
	}
	display_num(numbers);
}