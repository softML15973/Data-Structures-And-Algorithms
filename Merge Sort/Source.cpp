#include <iostream>
using namespace std;
void merge(int left_arr[],int left_arr_size, int right_arr[], int right_arr_size, int original_arr[])
{
	//i for left array
	//j for right array
	//k for original array
	int i = 0, j = 0, k = 0;
	while (i != left_arr_size && j != right_arr_size)
	{
		if (left_arr[i] < right_arr[j])
		{
			original_arr[k] = left_arr[i];
			i++;
			k++;
		}
		else if (left_arr[i] > right_arr[j])
		{
			original_arr[k] = right_arr[j];
			j++;
			k++;
		}
		else if (left_arr[i] == right_arr[j])
		{
			original_arr[k] = left_arr[i];
			k++;
			original_arr[k] = right_arr[j];
			i++;
			j++;
			k++;
		}
	}
	if (i < left_arr_size && j == right_arr_size)
	{
		while (i != left_arr_size)
		{
			original_arr[k] = left_arr[i];
			i++;
			k++;
		}
	}
	else if (j < right_arr_size && i == left_arr_size)
	{
		while (j != right_arr_size)
		{
			original_arr[k] = right_arr[j];
			j++;
			k++;
		}
	}
}
void merge_sort(int arr[], int size_arr)
{
	if (size_arr < 2)
	{
		return;
	}
	else
	{
		int mid = size_arr / 2;
		int left_arr_size = mid;
		int* left_arr = new int[left_arr_size];
		int right_arr_size = size_arr - mid;
		int* right_arr = new int[right_arr_size];
		for (int i = 0; i < mid; i++)
		{
			left_arr[i] = arr[i];
		}
		for (int i = mid; i < size_arr; i++)
		{
			right_arr[i - mid] = arr[i];
		}
		merge_sort(left_arr, left_arr_size);
		merge_sort(right_arr, right_arr_size);
		merge(left_arr, left_arr_size, right_arr, right_arr_size, arr);
		delete[] left_arr;
		delete[] right_arr;
	}
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
	merge_sort(arr, size);
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}