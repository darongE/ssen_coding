#include <iostream>
#include <cstddef>
using namespace std;


/**

INPUT
4
2
3
4
1

OUTPUT 2 3 4 1


INPUT 
8 11 2 3 4
**/
class Node
{
public:
	int data;
	Node *next;
	Node(int d) {
		data = d;
		next = NULL;
	}
};

class Solution {
public:

	Node* insert(Node *head, int data)
	{  
		// if list has no elements, return a new node

		if (head == NULL)
			return new Node(data);
		

		Node *tmp = head;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
			
		}

		tmp->next = new Node(data);
		

		return head;
	}



	void display(Node *head)
	{
		Node *start = head;
		while (start)
		{
			cout << start->data << " ";
			start = start->next;
		}
	}
};

int main()
{
	Node* head = NULL;

	Solution mylist;

	int T, data;
	cin >> T;
	while (T-->0) {
		cin >> data;
		head = mylist.insert(head, data);
	}
	mylist.display(head);

}