#ifndef TASK2_HPP
#define TASK2_HPP

#include <iostream>

struct Rubles;

struct Money
{
protected:
	int amount;
	int remainder;

public:
	Money();
	Money(int amount, int remainder);

	int get_amount();
	int get_remainder();
	void set_amount(int num);
	void set_remainder(int num);
	~Money();
};

struct Dollars : Money
{
public:
	static const float cost_dollar;

	Dollars();
	Dollars& operator+(Rubles &rubles);
	Dollars& operator-(Rubles &rubles);
	Dollars& operator*(int num);
	~Dollars();
};

struct Rubles : Money
{
public:
	Rubles();
	Rubles& operator+(Rubles &a);
	Rubles& operator-(Rubles &a);
	Rubles& operator*(int num);
	static Dollars &to_dollars(Rubles &rubles);
	~Rubles();
};

#endif