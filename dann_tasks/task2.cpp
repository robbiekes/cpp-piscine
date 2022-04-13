#include <iostream>
#include <string>

struct Money
{
protected:
	int amount;
	int remainder;
public:
	Money() : amount(0), remainder(0) {};
	Money(int amount, int remainder) : amount(amount), remainder(remainder) {};

	int get_amount() { return this->amount; }
	int get_remainder() { return this->remainder; }
	void set_amount(int num) { this->amount = num; }
	void set_remainder(int num) { this->remainder = num; }
};

struct Dollars;

struct Rubles : Money
{
	Rubles& operator+(Rubles &a)
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

	Rubles& operator-(Rubles &a)
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

	Rubles& operator*(int num)
	{
		this->amount *= num;
		if ((this->remainder *= num) >= 100)
		{
			this->amount += this->remainder / 100;
			this->remainder += this->remainder % 100;
		}
		return *this;
	}
	static Dollars &to_dollars(Rubles &rubles)
	{
		Dollars dollars;
		int tmp = rubles.get_amount() * 100 + rubles.get_remainder();
		dollars.set_amount((int)(tmp / dollars.cost_dollar) / 100);
		dollars.set_remainder((int)(tmp / dollars.cost_dollar) % 100);
		return dollars;
	}
};

struct Dollars : Money
{
	//Dollars& operator+(Rubles &rubles)
	//{
	//	this->amount += rubles.get_amount() / cost_dollar;
	//	this->remainder += rubles.get_amount() % cost_dollar;
	//}
	static const float cost_dollar = 79.16;
};

int main()
{

}

