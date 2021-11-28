#include "List.hpp"
#include <iostream>

Node::Node(int data)
{
	this->data = data;
	this->next = nullptr;
}

List::List()
{
	this->head = nullptr;
}

void List::push_front(int data)
{
	Node *first = new Node(data);

	first->next = this->head;
	this->head = first;

}

void List::push_back(int data)
{
	Node *last = new Node(data);
	if (this->head == nullptr)
	{
		this->head = last;
		return ;
	}
	Node *res = this->head;
	while (res->next != nullptr)
		res = res->next;
	res->next = last;

}

void List::insert(int index, int data)
{
	if (index == 0)
	{
		this->push_front(data);
		return ;
	}
	Node *middle = new Node(data);
	Node *res = this->head;
	for (int i = 0; i < index - 1; i++)
		res = res->next;
	middle->next = res->next;
	res->next = middle;
}

void List::print()
{
	Node *res = this->head;
	while (res != nullptr)
	{
		std::cout << res->data << " ";
		res = res->next;
	}
	std::cout << "\n";
}

Node *List::at(int index)
{
	Node *res = this->head;
	for (int i = 0; i < index; i++)
		res = res->next;
	return (res);
}

int List::size()
{
	Node *res = this->head;
	int i;

	i = 0;
	while (res != nullptr)
	{
		res = res->next;
		i++;
	}
	return (i);
}

void List::pop_front()
{

	Node *res = this->head;
	this->head = res->next;
	delete res;
}

void List::pop_back()
{
	Node *res = this->head;
	if (this->head->next == nullptr)
	{
		delete res;
		this->head = nullptr;
		return ;
	}
	while (res->next->next != nullptr)
		res = res->next;
	delete res->next;
	res->next = nullptr;
}

void List::remove(int index)
{
	if (index == 0)
	{
		this->pop_front();
		return ;
	}
	Node *res = this->head;
	Node *tmp;
	for (int i = 0; i < index - 1; i++)
		res = res->next;
	tmp = res->next->next;
	delete res->next;
	res->next = tmp;
}

void List::clear()
{
	while (this->head != nullptr)
		this->pop_front();
}