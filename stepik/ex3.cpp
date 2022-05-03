#include <iostream>
#include <cstring>
// #include <algorythm>

struct String
{
	String(const char * _str = "") {
		std::cout << "default constructor" << std::endl;
		size = strlen(_str);
		str = new char[size + 1];
		str = strcpy(str, _str);
		str[size + 1] = '\0';
	}

	String(String &a)
	{
		std::cout << "copying constructor" << std::endl;
		size = a.size;
		str = new char[size + 1];
		for (int i = 0; i < size; i++)
			str[i] = a.str[i];
		str[size + 1] = '\0';
	}

	~String()
	{
		std::cout << "distructor" << std::endl;
		delete [] str;
	}

// private:
	size_t	size;
	char	*str;
};

int main()
{
	String s1("hello");
	String s2(s1);
	std::cout << "[" << s2.str << " " << s2.size << "]" << std::endl;

}