#include <iostream>
using namespace std;
struct Node
{
	char character;
	Node* next;
	Node* prev;
};
class Stack
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
	int precedence(char op)
	{
		if (op == '^')
		{
			return 3;
		}
		else if (op == '/' || op == '*' || op == '%')
		{
			return 2;
		}
		else if (op == '+' || op == '-')
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}
	void create_new_node(char ch)
	{
		front = new Node();
		front->character = ch;
		front->prev = NULL;
		front->next = NULL;
		rear = front;
	}
	void create_next_node(char ch)
	{
		Node* temp = new Node();
		temp->character = ch;
		temp->next = NULL;
		temp->prev = rear;
		rear->next = temp;
		rear = temp;
	}
	string remaning_elements()
	{
		string expression = "";
		while (!isEmpty())
		{
			Node* temp = rear->prev;
			expression = expression + rear->character;
			delete rear;
			rear = temp;
			if (rear == NULL)
			{
				front = NULL;
			}
		}
		return expression;
	}
	string pop(char ch);
	string push(char ch);
};
string Stack::push(char ch)
{
		string expression = "";
		if (isEmpty())
		{
			create_new_node(ch);
		}
		else if (ch == '(')
		{
			create_next_node(ch);
		}
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^')
		{
			bool check = true;
			while (check)
			{
				if (isEmpty())
				{
					check = false;
				}
				else if (precedence(ch) <= precedence(rear->character) && rear->character != '(')
				{
					expression = expression + pop(rear->character);
				}
				else
				{
					check = false;
				}
			}
			if (isEmpty())
			{
				create_new_node(ch);
			}
			else
			{
				create_next_node(ch);
			}
		}
		return expression;
}
string Stack::pop(char ch)
{
	string expression;
	bool check = true;
	if (ch == ')')
	{
		while (check)
		{
			if (isEmpty())
			{
				check = false;
			}
			else if (rear->prev == NULL)
			{
				if (rear->character == '(')
				{
					delete rear;
					front = rear = NULL;
					check = false;
				}
				else
				{
					expression = expression + rear->character;
					delete rear;
					front = rear = NULL;
					check = false;
				}
			}
			else if (rear->prev != NULL)
			{
				if (rear->character == '(')
				{
					Node* temp = rear->prev;
					delete rear;
					rear = temp;
					check = false;
				}
				else
				{
					expression = expression + rear->character;
					Node* temp = rear->prev;
					delete rear;
					rear = temp;
				}
			}
		}
	}
	else
	{
		expression = expression + ch;
		Node* temp = rear->prev;
		delete rear;
		rear = temp;
		if (rear == NULL)
		{
			front = NULL;
		}
	}
	return expression;
}
int main()
{
	string infix, postfix = "";
	Stack stack;
	cout << "Enter infix expression without spaces: ";
	cin >> infix;
	for (int i = 0; i < infix.size(); ++i)
	{
		if (!isdigit(infix[i]))
		{
			if (!isalpha(infix[i]))
			{
				if (infix[i] != '+' && infix[i] != '-' && infix[i] != '*' && infix[i] != '/' && infix[i] != '%' && infix[i] != '^')
				{
					if (infix[i] != '(' && infix[i] != ')')
					{
						cout << "Invalid characters in the expression";
						exit(0);
					}
				}
			}
		}
	}
	int i = 0;
	while (i < infix.size())
	{
		if (infix[i] == '(')
		{
			postfix = postfix + stack.push(infix[i]);
		}
		else if (infix[i] == ')')
		{
			postfix = postfix + stack.pop(')');
		}
		else if (isalpha(infix[i]) || isdigit(infix[i]))
		{
			postfix = postfix + infix[i];
		}
		else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '%' || infix[i] == '^')
		{
			postfix = postfix + stack.push(infix[i]);
		}
		++i;
	}
	if (!stack.isEmpty())
	{
		postfix = postfix + stack.remaning_elements();
	}
	cout << "Postfix Expression: " << postfix;
	return 0;
}