class Node
{
public:
	int data;
	Node *next;

	Node(int data);
};

class List
{
public:
	// DONE:
	Node *head;
	void push_front(int data);
	void push_back(int data);
	void print();
	Node *at(int index);
	void insert(int index, int data);
	int size();

	// TODO:
	void pop_front();
	void pop_back();
	void remove(int index);
	void clear();


	List();
};
