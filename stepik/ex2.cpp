#include <iostream>
#include <cstddef>
#include <cstring>
#include <string>
#include <fstream>

struct String {

	String(const char *str_new = "")
	{
	    size = strlen(str_new);
	    str = new char[size + 1];
		str = strcpy(str, str_new);
		str[size + 1] = '\0';
	}

	String(size_t n, char c)
	{
		str = new char[n + 1];
		for (int i = 0; i < n; i++)
			str[i] = c;
		str[n + 1] = '\0';
		size = strlen(str);
	}

	void append(String &other)
	{
		char *new_str = new char[size + other.size + 1];
		new_str = strcpy(new_str, str);
		new_str = strcat(new_str, other.str);
		delete [] str;
		str = new_str;
		size = strlen(str);
	}

	~String()
	{
		delete [] str;
	}


	size_t size;
	char *str;
};

int main()
{
    // String s1(5, 'a');
	String s1("Help");
	s1.append(s1);
	// String s2("Me");
	// s1.append(s2);
    std::cout << s1.size << " " << s1.str << std::endl;
    return 0;
}
