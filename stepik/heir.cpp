#include <iostream>
#include <string>


struct Foo
{
	void say() const { std::cout << "Foo says: " << msg << std::endl; }
	protected:
		Foo(const char *msg) : msg(msg) {};
	private:
		const char *msg;
};

Foo get_foo(const char *msg)
{
	struct Heir : Foo {
		Heir(const char *msg) : Foo(msg) {};
	};

	return Heir(msg);
}

void foo_says(const Foo &foo)
{
	foo.say();
}

int main()
{
	foo_says(get_foo("Hello!"));
}