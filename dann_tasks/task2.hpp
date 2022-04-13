#ifndef TASK2_HPP
#define TASK2_HPP

#include <iostream>

struct Money
{
	int amount;
	int remainder;

	Money() : amount(0), remainder(0) {};
	Money(int amount, int remainder) : amount(amount), remainder(remainder) {};

	int get_amount();
	int get_remainder();
	void set_amount(int num);
	void set_remainder(int num);
};

struct Rubles : Money
{
	Rubles& operator+(Rubles &a) {};
	
}

#endif