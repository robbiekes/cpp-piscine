#include "List.hpp"

#include <iostream>

int main()
{
	List *list = new List();
	list->push_front(5);
	list->push_front(4);
	list->push_front(3);
	list->push_front(2);
	list->push_back(6);
	list->print();
	list->insert(5, 15);
	list->print();
	std::cout << list->size();
}
