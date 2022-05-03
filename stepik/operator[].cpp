#include <iostream>

struct String2;

struct String
{
	String(const char * _str = "") {
		// std::cout << "default constructor" << std::endl;
		size = strlen(_str);
		str = new char[size + 1];
		str = strcpy(str, _str);
		str[size + 1] = '\0';
	}

	String(String &a)
	{
		// std::cout << "copying constructor" << std::endl;
		size = a.size;
		str = new char[size + 1];
		for (int i = 0; i < size; i++)
			str[i] = a.str[i];
		str[size + 1] = '\0';
	}
	String2& operator[](int i)
	{
		static int start = -1;
		if (start == -1)
			start = i;
		String2 *sub = new String2;
		sub->start = start;
		sub->operator[](i);
		return *sub;
	}

	friend std::ostream &operator << (std::ostream &os, const String &result)
	{
		os << "current string: " << result.str << std::endl;
		return os;
	} 
	~String()
	{
		// std::cout << "distructor" << std::endl;
		delete [] str;
	}

// private
	size_t	size;
	char	*str;
};

struct String2 : public String
{
	String2() : start(-1) {}
	~String2() {}

	String2& operator[](int i)
	{
		if (i == start)
		{
			this->str = strdup("");
			start = -1;
		}
		if (i > start && i < size)
		{
			memmove(this->str, this->str + start, i - start);
			this->str[i - start] = '\0';
			start = -1;
		}
	}
	friend std::ostream &operator << (std::ostream &os, const String2 &result)
	{
		os << "current string: " << result.str << std::endl;
		return os;
	} 
	int start;
};

int main()
{
	String s1("hello");
	String s2 = s1;

	std::cout << s1[0][4] << "\n";
	// std::cout << "[" << s2.str << " " << s2.size << "]" << std::endl;

}