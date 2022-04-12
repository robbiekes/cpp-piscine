#include <iostream>
#include <ostream>
#include <string>

class Fraction
{
private:
	int numerator;
	int denominator;

public:
	Fraction() : numerator(1), denominator(1) {};

	Fraction(int numerator, int denominator)
	{
		this->numerator = numerator;
		this->denominator = denominator;
	}

	Fraction(int num)
	{
		this->numerator = num;
		this->denominator = 1;
	}
	
	void operator = (const Fraction &other)
	{
		this->numerator = other.numerator;
		this->denominator = other.denominator;
	};

	void operator + (const Fraction &other)
	{
		this->numerator += other.numerator;
	}

	friend std::ostream &operator << (std::ostream &os, const Fraction &result)
	{
		os << "current fraction: [ " << result.numerator << " / " << result.denominator << " ]" << std::endl;
		return os;
	} 

	~Fraction() {};
};

// int main()
// {
// 	Fraction a(1, 3);
// 	Fraction b(4);
// 	b = a;
// 	// a + b;
// 	std::cout << b;
// }