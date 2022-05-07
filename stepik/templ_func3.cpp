#include <cstddef>
#include <iostream>
// #include <fstream>
#include <iomanip>

template <typename T>
class Array
{
public:
    explicit Array(size_t size = 0, const T& value = T()) : size_(size), data_(new T[size])
	{
		for(int i = 0; i < size; i++)
			data_[i] = value;
	}
    Array(const Array &a) : size_(a.size_), data_(new T[a.size_])
	{
		for (int i = 0; i < size_; i++)
			data_[i] = a.data_[i];
	}
    ~Array() { delete [] data_; }
    	
    Array& operator=(const Array & a){
        if (this != &a) {
            delete [] data_;
            size_ = a.size_;
            data_ = new T[size_];
            for (size_t i = 0; i != size_; ++i) {
                data_[i] = a.data_[i];
            }
        }
        return *this;
    }

    size_t size() const
	{
		return size_;
	}

    T& operator[](int t)
	{
		return data_[t];
	}
    const T& operator[](int t) const
	{
		return data_[t];
	}

private:
    size_t	size_;
    T 		*data_;
};

template <class I>
void flatten(I a, std::ostream &out)
{
	out << std::fixed << std::setprecision(1) << a;
}

template <class T>
void flatten(Array<T> &a, std::ostream& out)
{
	for (int i = 0; i < a.size(); i++)
	{
		out << a[i] << " ";
	}
}

template <class T>
void flatten(Array< Array<T> > &a, std::ostream& out)
{
	for (int i = 0; i < a.size(); i++)
		flatten(a[i], out);
}

int main()
{
	// Array<int> ints(2, 0);
	// ints[0] = 10;
	// ints[1] = 20;
	// Array< Array<int> > array_of_ints(2, ints);
	// flatten(array_of_ints, std::cout);

	Array<double> doubles(10, 2.5);
	flatten(doubles, std::cout);
	// int a = 5;
	// flatten(a, std::cout);
	// flatten(ints, std::cout); 
}