#include <iostream>
#include <cstddef>
#include <new>

template <typename T>
class Array
{
public:
    Array() : size_(0), data_(new T[0]) {}
    
    explicit Array(size_t size, const T& value = T()) : size_(size), data_((T*)(new char[size * sizeof(T)]))
	{
		for (int i = 0; i < size_; i++)
			new (data_ + i) T(value);
	}

    Array(const Array &a) : size_(a.size_), data_((T*)(new char[a.size_ * sizeof(T)]))
	{
		for (int i = 0; i < size_; i++)
			new (data_ + i) T(a.data_[i]);
	}

    ~Array() 
	{ 
		for (int i = 0; i < size_; i++)
			data_[i].~T();
		delete [] (char *)data_;
	}
    
    Array& operator=(const Array &a)
    {
        if (this != &a) {
            delete [] (char *)data_;
            size_ = a.size_;
            data_ = (T*)(new char[a.size_ * sizeof(T)]);
            for (size_t i = 0; i < size_; i++)
                new (data_ + i) T(a.data_[i]);
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

int main() {
	char * a = new char[0];

	int b  = 4;
	int *bptr = &b;

	printf("%p\n", a);

	return (0);
}
