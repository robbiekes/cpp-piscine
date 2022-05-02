#include <iostream>
struct Rational
{
    Rational(int numerator = 0, int denominator = 1) : numerator_(numerator), denominator_(denominator) {};
 
    void add(Rational rational);
    void sub(Rational rational);
    void mul(Rational rational);
    void div(Rational rational);
 
    void neg();
    void inv();
    double to_double() const;
 
    Rational& operator+=(Rational rational);
    Rational& operator-=(Rational rational);
    Rational& operator*=(Rational rational);
    Rational& operator/=(Rational rational);
 
    Rational operator-() const;
    Rational operator+() const;
    
   Rational operator+(const Rational & rational) const {
        Rational r(this->numerator_, this->denominator_);
        r.add(rational);
        return r;
    }
    Rational operator+(int d) const {
        Rational r(this->numerator_, this->denominator_);
        r.add(Rational(d));
        return r;
    }
    friend Rational operator+(int d, const Rational & rational) {
        return rational + d;
    }
    Rational operator-(const Rational & rational) const {
        Rational r(this->numerator_, this->denominator_);
        r.sub(rational);
        return r;
    }
    Rational operator-(double d) const {
        Rational r(this->numerator_, this->denominator_);
        r.sub(Rational(d));
        return r;
    }
    friend Rational operator-(int d, const Rational & rational) {
        return -(rational - d);
    }
    Rational operator*(const Rational & rational) const {
        Rational r(this->numerator_, this->denominator_);
        r.mul(rational);
        return r;
    }
    Rational operator*(int d) const {
        Rational r(this->numerator_, this->denominator_);
        r.mul(Rational(d));
        return r;
    }
    friend Rational operator*(int d, const Rational & rational) {
        return rational * d;
    }
    Rational operator/(const Rational & rational) const {
        Rational r(this->numerator_, this->denominator_);
        r.div(rational);
        return r;
    }
    Rational operator/(int d) const {
        Rational r(this->numerator_, this->denominator_);
        r.div(Rational(d));
        return r;
    }
    friend Rational operator/(int d, const Rational & rational) {
        return Rational(d)/rational;
    }
	friend bool operator==(const Rational &left, const Rational &right)
	{
		return ((left.numerator_ == right.numerator_) && (left.denominator_ == right.denominator_));
	}
	friend bool operator==(int left, const Rational &right)
	{
        Rational left_(left);
		return ((left_.numerator_ == right.numerator_) && (left_.denominator_ == right.denominator_));
	}
    friend bool operator==(const Rational &left, int right)
	{
        Rational right_(right);
		return ((left.numerator_ == right_.numerator_) && (left.denominator_ == right_.denominator_));
	}
	friend bool operator!=(const Rational &left, const Rational &right)
	{
		return !(left == right);
	}
	friend bool operator<(const Rational &left, const Rational &right)
	{
		int Y = left.numerator_ * right.denominator_ - left.denominator_ * right.numerator_; 
        return Y < 0; 
		//return ((left.numerator_ < right.numerator_));
	}
	friend bool operator<(int left, const Rational &right)
	{
		Rational left_(left);
		int Y = left_.numerator_ * right.denominator_ - left_.denominator_ * right.numerator_; 
        return Y < 0; 
	}
	friend bool operator<(const Rational &left, int right)
	{
		Rational right_(right);
		int Y = left.numerator_ * right_.denominator_ - left.denominator_ * right_.numerator_; 
        return Y < 0; 
		//return ((left.numerator_ < right_.numerator_));
	}
	friend bool operator>(const Rational &left, const Rational &right)
	{
		return (right < left);
	}
	friend bool operator>(const Rational &left, int right)
	{
		Rational right_(right);
		return (right_ < left);
	}
	friend bool operator>(int left, const Rational &right)
	{
		Rational left_(left);
		//std::cout << left_.numerator_ << left_.denominator_ << "\n";
		//std::cout << right.numerator_ << right.denominator_ << "\n";
		return (right < left_);
	}
	friend bool operator>=(const Rational &left, const Rational &right)
	{
		return !(left < right);
	}
	friend bool operator>=(int left, const Rational &right)
	{
		Rational left_(left);
		return !(left_ < right);
	}
	friend bool operator>=(const Rational &left, int right)
	{
		Rational right_(right);
		return !(left < right_);
	}
	friend bool operator<=(const Rational &left, const Rational &right)
	{
		return !(right < left);
	}
	friend bool operator<=(int left, const Rational &right)
	{
		Rational left_(left);
		return !(right < left_);
	}
	friend bool operator<=(const Rational &left, int right)
	{
		Rational right_(right);
		return !(right_ < left);
	}
private:
    int numerator_;
    unsigned denominator_;
};

int main()
{
	Rational t(2, 3);
	Rational t2(3, 5);

	if (t <= t2)
	{
		std::cout << "YES";
	}
	else
		std::cout << "NO";
}