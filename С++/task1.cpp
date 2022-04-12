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
	size_t size;
	char *str;
};

int main()
{
    String s1("hello!");
    std::cout << s1.size << " " << s1.str << std::endl;
    return 0;
}