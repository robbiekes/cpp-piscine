#include <cstddef>

template <typename T>
class Array
{
public:
    explicit Array(size_t size = 0, const T& value = T()) : size_(size), data_(new T(size))
	{
		for(int i = 0; i < size; i++)
			data_[i] = value;
	}
    //
    Array(const Array &a) : size_(a.size), data_(new T(size))
	{
		for (int i = 0; i < size; i++)
			data_[i] = a.data_[i];
	}
    ~Array() { delete [] data_; }
	
	void swap(Array &a)
	{
		size_t tmp = size_;
		size_ = a.size;
		a.size = tmp;

		T *tmp = data_;
		data_ = a.data;
		a.data = tmp;
	}

    Array& operator=(Array other)
	{
		Array(other)->swap(*this);
		return *this;
	}
    size_t size() const
	{
		return size_;
	}

    T& operator[](size_t t)
	{
		return *data_[t];
	}
    const T& operator[](size_t) const
	{
		return *data_[t];
	}
};