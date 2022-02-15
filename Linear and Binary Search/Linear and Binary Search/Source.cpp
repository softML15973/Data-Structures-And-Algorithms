#include <iostream>
using namespace std;
void selection_sort(int arr[], int size)
{
	int temp = 0, index = 0;
	bool check;
	for (int i = 0; i < size - 1; i++)
	{
		temp = arr[i];
		check = false;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < temp)
			{
				temp = arr[j];
				index = j;
				check = true;
			}
		}
		if (check == true)
		{
			swap(arr[i], arr[index]);
		}
	}
}
bool binarySearch(int arr[],int key, int start, int end)
{
	if (start > end)
	{
		return false;
	}
	int mid = (start + end) / 2;
    if (arr[mid] == key)
	{
		return true;
	}
	else if (key > arr[mid])
	{
		start = mid + 1;
	}
	else if (key < arr[mid])
	{
		end = mid - 1;
	}
	return binarySearch(arr, key, start, end);
}
int main()
{
	int arr[5];
	int size = sizeof(arr) / 4;
	for (int i = 0; i < size; i++)
	{
		cout << "Enter Element: ";
		cin >> arr[i];
	}
	selection_sort(arr, size); /*Array should be sorted before
							   doing binary search*/
	int start = 0;
	int end = size - 1; 
	int key;
	cout << "Enter key value: ";
	cin >> key;
	if (binarySearch(arr, key, start, end))
	{
		cout << "Element is present in the array\n";
	}
	else
	{
		cout << "Element is not present in the array\n";
	}
	return 0;
}