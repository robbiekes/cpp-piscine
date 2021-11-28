#include "List.hpp"

#include <iostream>

int main()
{
	List *list = new List();
	list->push_back(100);
	list->pop_back();
	list->print();

	// list->push_front(5);
	// list->push_front(4);
	// list->push_front(3);
	// list->push_front(2);
	// list->push_back(6);
	// list->print();
	// list->pop_front();
	// list->print();
	// list->pop_back();
	// list->print();
	// list->remove(0);
	// list->print();
	// list->clear();
	// list->print();

}
