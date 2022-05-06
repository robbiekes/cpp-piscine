template <typename T>

struct ValueHolder : ICloneable
{
	ValueHolder(const T& value)
	{
		data_ = new char[sizeof(T)];
	}
	ICloneable* clone() const
	{
		ValueHolder *clone = new ValueHolder(*this);
		return &clone;
	}

public:
	T *data_;
};

struct ICloneable
{
	virtual ICloneable* clone() const = 0;
	virtual ~ICloneable() { }
};