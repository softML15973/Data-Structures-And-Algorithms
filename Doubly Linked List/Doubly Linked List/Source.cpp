#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
	Node* prev;
};
class Linkedlist
{
private:
	Node* front = NULL;
	Node* rear = NULL;
public:
	bool isEmpty()
	{
		if (front == NULL && rear == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void print_elements()
	{
		Node* temp = front;
		cout << "Elements in linked list\n";
		while (temp != front)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
	void initial_node(int data)
	{
		front = new Node();
		front->data = data;
		front->next = front;
		front->prev = front;
		rear = front;
		cout << "Elements in Linked List: " << front->data << endl;
	}
	int get_data()
	{
		int data;
		cout << "Enter data: ";
		cin >> data;
		return data;
	}
	void create_node_at_start()
	{
		int data = get_data();
		cout << "Enter data: ";
		cin >> data;
		if (isEmpty())
		{
			initial_node(data);
		}
		else
		{
			Node* temp = new Node();
			temp->data = data;
			temp->next = front;
			temp->prev = rear;
			front->prev = temp;
			rear->next = temp;
			print_elements();
		}
	}
	void create_node_at_middle()
	{
		int data = get_data();
		if (isEmpty())
		{
			initial_node(data);
		}
		else
		{

		}
	}
	void create_node_at_end()
	{
		int data = get_data();
		if (isEmpty())
		{
			initial_node(data);
		}
		else
		{
			Node* temp = new Node();
			temp->data = data;
			temp->prev = rear;
			temp->next = front;
			rear->next = temp;
			front->prev = temp;
			rear = front;
			print_elements();
		}
	}
	void delete_end_node()
	{
		if (isEmpty())
		{
			cout << "Linked list is empty\n";
		}
		else if (front == rear)
		{
			delete front;
			front = rear = NULL;
		}
		else
		{
			Node* temp = rear->prev;
			delete rear;
			rear = temp;
			rear->next = front;
			print_elements();
		}
	}
	void delete_middle_node()
	{
		int element;
		cout << "Enter element to delete it's node: ";
		cin >> element;
		Node* temp = front;
		while (element != temp->data && temp->next != front)
		{
			temp = temp->next;
		}
		if (temp->data == element)
		{
			Node* temp_next = temp->next;
			Node* temp_prev = temp->prev;
			delete temp;
			temp_prev->next = temp_next;
			temp_next->prev = temp_prev;
			print_elements();
		}
		else
		{
			cout << "Element does not exist in the linke list\n";
		}
	}
};
int main()
{

	return 0;
}