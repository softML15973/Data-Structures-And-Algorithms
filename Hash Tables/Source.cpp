#include <iostream>
using namespace std;
struct Node
{
	int value;
	Node* next;
};
int hash_function(int key,int size)
{
	int index = key % size;
	return index;
}
class Separate_Chaining
{
private:
	Node* hash_table[7]{};
	int size = 7;
public:
	void insert(int value)
	{
		int hash_code = hash_function(value, size);
		if (hash_table[hash_code] == NULL)
		{
			hash_table[hash_code] = new Node;
			hash_table[hash_code]->value = value;
			hash_table[hash_code]->next = NULL;
		}
		else
		{
			Node* temp = hash_table[hash_code];
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = new Node;
			temp->next->value = value;
			temp->next->next = NULL;
		}
	}
	void search(int value)
	{
		int hash_code = hash_function(value, size);
		if (hash_table[hash_code] == NULL)
		{
			cout << "No such element\n";
		}
		else if (hash_table[hash_code]->next == NULL)
		{
			if (hash_table[hash_code]->value == value)
			{
				cout << "Element exists in the table\n";
			}
			else
			{
				cout << "Element does exist in the table\n";
			}
		}
		else
		{
			Node* temp = hash_table[hash_code];
			while (temp != NULL)
			{
				if (temp->value == value)
				{
					cout << "Element exists in the table\n";
					return;
				}
				else
				{
					temp = temp->next;
				}
			}
			cout << "No such element found\n";
		}
	}
	~Separate_Chaining()
	{
		int i = 0;
		while (i < size)
		{
			if(hash_table[i]==NULL){}
			else if (hash_table[i]->next == NULL)
			{
				delete hash_table[i];
			}
			else
			{
				Node* temp = hash_table[i];
				Node* temp1 = NULL;
				while (temp != NULL)
				{
					temp1 = temp;
					temp = temp->next;
					delete temp1;
				}
			}
			i++;
		}
	}
};
int main()
{
	Separate_Chaining h_table;
	int arr[7] = { 50,700,76,85,92,73,101 };
	for (int i = 0; i < 7; i++)
	{
		h_table.insert(arr[i]);
	}
	h_table.search(1);
	return 0;
}