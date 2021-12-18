#include <iostream>
#include <vector>

void	bad_string(char *string)
{
	int	length = 0, i = 0, parenthesis = 0;
	while (string[i])
		i++;
	length = i;
	while (string[--i] == ')')
		parenthesis++;
	if ((length - parenthesis) >= parenthesis)
		std::cout << "No" << '\n';
	else
		std::cout << "Yes" << '\n';
}

int main()
{
	int tries = 0, amounts = 0;
	char string[101];
	std::cin >> tries;
	if (tries <= 100)
	{
		while(tries-- > 0)
		{
			std::cin >> amounts;
			std::cin >> string;
			if (amounts >= 1 && amounts <= 100)
				bad_string(string);
			else
				return (0);
		}
	}
}