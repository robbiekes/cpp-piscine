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
	Node *head;
	void push_front(int data);
	void push_back(int data);
	void print();
	Node *at(int index);
	void insert(int index, int data);
	int size();

	List();
};
