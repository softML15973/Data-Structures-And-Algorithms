#include <iostream>
using namespace std;
int Bubble_Sort(int arr[], int size)
{
	int pass = 0;
	bool flag;
	for (int i = size-1; i > 0; i--)//Loop will run (n-1) times
	{
		flag = true;
		//Loop will run (n-1) times for each outer loop iteration
		for (int j = 0; j < size - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				flag = false;
			}
		}
		if (flag)
		{
			pass++;
			return pass;
		}
		else
		{
			pass++;
			size--;
		}
	}
	return pass;
}
int main()
{
	int arr[5];
	int size = sizeof(arr) / 4;
	for (int j = 0; j < size; j++)
	{
		cout << "Enter elements: ";
		cin >> arr[j];
	}
	int passes = Bubble_Sort(arr, size);
	cout << "Number of passes: " << passes << endl;
	for (int j = 0; j < size; j++)
	{
		cout << arr[j] << " ";
	}
	return 0;
}