//program to implement bubble sort and count the number of comparisons.
#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	cout << "Enter the number of elements in the array: ";
	int size;
	cin >> size;
	int arr[size];
	int count = 0;
	cout << "\nEnter the elements in the array: ";
	for (int i = 0; i < size; ++i)
		cin >> arr[i];
	cout << "\nThe entered array is: ";
	for (int i = 0; i < size; ++i)
		cout << arr[i] << " ";
	int m;
	for (int i = 0; i < size; ++i) {
		m = 0;
		for (int j = 1; j < size - i; ++j) {
			++count;
			if (arr[m] > arr[j]) {
				swap(arr[m],arr[j]);
			}
			++m;
		}
	}
	cout << "\nThe sorted array is: ";
	for (int i = 0; i < size; ++i)
		cout << arr[i] << " ";
	cout << "\nNumber of comparisons made: " << count; 
	return 0;
}
