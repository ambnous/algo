// Program to implement selection sort
#include <iostream>

using namespace std;
int main() {
	cout << "Enter the number of elements in the array: ";
	int size;
	cin >> size;
	int arr[size];
	int count = 0;
	int min_index;
	cout << "\nEnter the elements in the array: ";
	for (int i = 0; i < size; ++i)
		cin >> arr[i];
	cout << "\nThe entered array is: ";
	for (int i = 0; i < size; ++i)
		cout << arr[i] << " ";	
    for(int i = 0; i < size - 1; ++i) {
        min_index = i;
        for (int j = i + 1; j < size; ++j) {
			++count;
            if(arr[j] < arr[min_index])
                min_index = j;
        }
		swap(arr[min_index],arr[i]);
	}
	cout << "\nThe sorted array is: ";
	for (int i = 0; i < size; ++i)
		cout << arr[i] << " ";
	cout << "\nNumber of comparisons made: " << count; 
	return 0;
}

