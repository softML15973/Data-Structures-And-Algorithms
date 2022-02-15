#include <iostream>
using namespace std;
void insertion_sort(int arr[], int size)
{
	for (int i = 1; i < size; i++)
	{
		if (arr[i] < arr[i - 1])
		{
			swap(arr[i], arr[i - 1]);
			for (int j = i - 1; j > 0; j--)
			{
				if (arr[j] < arr[j - 1])
				{
					swap(arr[j], arr[j - 1]);
				}
				else
				{
					break;
				}
			}
		}
	}
}
int main()
{
	int arr[5];
	int size = sizeof(arr) / 4;
	cout << "Enter elements: ";
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
	insertion_sort(arr, size);
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}