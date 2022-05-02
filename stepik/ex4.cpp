#include <string>
#include <iostream>

struct Expression
{
	virtual double evaluate() const = 0;
	virtual ~Expression() {}
};

struct Number : Expression
{
	Number(double value) : value(value) {}
	double evaluate() const { return value; }
private:
	double value;
};

struct BinaryOperation : Expression
{
	//BinaryOperation() : left(0), right(0), op(0) {}
	BinaryOperation(Expression const *left, char op, Expression const *right) : left(left), op(op), right(right) {}

	double evaluate() const
	{
		switch (op)
		{
			case '+':
				return (left->evaluate() + right->evaluate());
			case '-':
				return (left->evaluate() - right->evaluate());
			case '*':
				return (left->evaluate() * right->evaluate());
			case '/':
				return (left->evaluate() / right->evaluate());
		}
		return 0;
	}
private:
	Expression const *left;
	Expression const *right;
	char op;
	
	~BinaryOperation() {}
};

int main()
{
	Expression *a = new BinaryOperation(new Number(4.5), '+', new Number(1.2));
	Expression *b = new BinaryOperation(new Number(4), '*', new BinaryOperation(new Number(2.5), '+', new Number(3)));
	std::cout << b->evaluate() << "\n";
	std::cout << *(int*)a << " " << *(int*)b << "\n";
}
