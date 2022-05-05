//#include "ex4.cpp"

struct Number;
struct BinaryOperation;

struct Visitor {
	virtual void visitNumber(Number const * number) = 0;
	virtual void visitBinaryOperation(BinaryOperation const * operation) = 0;
	virtual ~Visitor() { }
};

struct Expression
{
	virtual double evaluate() const = 0;
	virtual void visit(Visitor * vistitor) const = 0;
	virtual ~Expression() { }
};

struct Number : Expression
{
	Number(double value) : value(value) {}

	double evaluate() const { return value; }

	double get_value() const { return value; }

	void visit(Visitor * visitor) const { visitor->visitNumber(this); }

private:
	double value;
};

struct BinaryOperation : Expression
{
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

	Expression const * get_left() const { return left; }
	Expression const * get_right() const { return right; }
	char get_op() const { return op; }

	void visit(Visitor * visitor) const { visitor->visitBinaryOperation(this); }

private:
	Expression const * left;
	Expression const * right;
	char op;
};

#include <iostream>

struct PrintVisitor : Visitor {
	void visitNumber(Number const * number)
	{
		std::cout << number->get_value();
	}

	void visitBinaryOperation(BinaryOperation const * bop)
	{
		std::cout << '(';
		bop->get_left()->visit(this);
		std::cout << " " << bop->get_op() << " ";
		bop->get_right()->visit(this);
		std::cout << ')';
	}
};

struct ScopedPtr
{
    explicit ScopedPtr(Expression *ptr = 0) :  this->ptr_(ptr); {}
    ~ScopedPtr() { delete ptr_; }
    Expression* get() const { return ptr_; }
    Expression* release() {
		Expression *new_ptr = this->ptr_;
		this->ptr_ = 0;
		return new_ptr;
	}
    void reset(Expression *new_ptr = 0)
	{
		delete ptr_;
		ptr_ = new_ptr;
	}
    Expression& operator*() const { return *ptr_; }
    Expression* operator->() const { return ptr_; }

private:
    ScopedPtr(const ScopedPtr&);
    ScopedPtr& operator=(const ScopedPtr&);

    Expression *ptr_;
};

int main()
{
	//Expression *a = new BinaryOperation(new Number(4.5), '+', new Number(1.2));
	//Expression *b = new BinaryOperation(new Number(4), '*', new BinaryOperation(new Number(2.5), '/', new Number(3)));
	//PrintVisitor v;

	//b->visit(&v);
	std::string a = "aaa";
	std::string b = "bbb";
	std::cout << a + b << "\n";
}