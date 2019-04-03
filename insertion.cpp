//program to implement insertin sort
#include <iostream>

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
	int i, j;
	for (i = 1; i < size; ++i) {
		int a = arr[i];
		++count;
		for (j = i - 1; j >= 0 && arr[j] > a; --j) {
			++count;
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = a;
	}
	cout << "\nThe sorted array is: ";
	for (int i = 0; i < size; ++i)
		cout << arr[i] << " ";
	cout << "\nNumber of comparisons made: " << count; 
	return 0;
}
