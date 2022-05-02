#include "task2.hpp"

Money::Money() : amount(0), remainder(0) {};

Money::Money(int amount, int remainder) : amount(amount), remainder(remainder) {};

int Money::get_amount() {
	return this->amount;
}

int Money::get_remainder() {
	return this->remainder;
}

void Money::set_amount(int num) {
	this->amount = num;
}

void Money::set_remainder(int num) {
	this->remainder = num;
}

Money::~Money() {};


Rubles::Rubles() {};

Rubles& Rubles::operator+(Rubles &a)
{
	this->amount += a.amount;
	this->remainder += a.remainder;
	if (this->remainder >= 100)
	{
		this->amount += 1;
		this->remainder = this->remainder - 100;
	}
	return *this;
}

Rubles& Rubles::operator-(Rubles &a)
{
	if (this->amount - a.amount > 0)
	{
		this->amount -= a.amount;
		this->remainder = a.remainder - this->remainder;
		if (this->remainder < 0)
			this->remainder = (100 - this->remainder) + a.remainder;
		if (a.remainder - this->remainder)
			this->amount -= 1;
	}
	return *this;
}

Rubles& Rubles::operator*(int num)
{
	this->amount *= num;
	if ((this->remainder *= num) >= 100)
	{
		this->amount += this->remainder / 100;
		this->remainder += this->remainder % 100;
	}
	return *this;
}

Dollars& Rubles::to_dollars(Rubles &rubles)
{
	Dollars *dollars = new Dollars();
	int tmp = rubles.get_amount() * 100 + rubles.get_remainder();
	dollars->set_amount((int)(tmp / dollars->cost_dollar) / 100);
	dollars->set_remainder((int)(tmp / dollars->cost_dollar) % 100);
	return *dollars;
}

Rubles::~Rubles() {};

Dollars::Dollars() {};

const float Dollars::cost_dollar = 71.52;

Dollars& Dollars::operator+(Rubles &rubles)
{
	Dollars tmp;
	tmp = rubles.to_dollars(rubles);
	this->amount += tmp.get_amount();
	this->remainder += tmp.get_remainder();
	return *this;
}

Dollars& Dollars::operator-(Rubles &rubles)
{
	Dollars tmp;
	tmp = rubles.to_dollars(rubles);
	this->amount -= tmp.get_amount();
	this->remainder -= tmp.get_remainder();
	return *this;
}

Dollars& Dollars::operator*(int num)
{
	this->amount *= num;
	if ((this->remainder *= num) >= 100)
	{
		this->amount += this->remainder / 100;
		this->remainder += this->remainder % 100;
	}
	return *this;
}

Dollars::~Dollars() {};

int main()
{
	Rubles rub;
	Rubles rub2;
	rub.set_amount(150);
	rub.set_remainder(5);
	rub2.set_amount(55);
	rub2.set_remainder(10);
	rub + rub2;
	std::cout << "sum of rubles: " << rub.get_amount() << " " << rub.get_remainder() << "\n";

	Dollars doll, doll2;
	doll.set_amount(3);
	// doll + rub;
	// std::cout << "sum of dollars and rubles: " << doll.get_amount() << " " << doll.get_remainder() << std::endl;
	// doll - rub2;
	// std::cout << "diff between dollars and rubles: " << doll.get_amount() << " " << doll.get_remainder() << std::endl;
	doll * 4;
	std::cout << "product of dollars to a number: " << doll.get_amount() << " " << doll.get_remainder() << std::endl;
}

