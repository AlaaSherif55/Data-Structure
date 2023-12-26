#include<iostream>
using namespace std;
int binarySearch(int arr[], int l, int h, int key)
{
	while (l <= h) {
		
		int m = (l + h) / 2;

		
		if (arr[m] == key)
			return m;
        
		if (arr[m] > key)
			
		h = m - 1;

		else

		l = m + 1;

	}

	return -1;
}


int main()
{
	int arr[] = { 2, 3, 4, 10, 40 };
	int n =5;
	
	int num;
	cout << "Enter an Integer :";
	cin >> num;

	int result = binarySearch(arr, 0, n - 1, num);
	cout<<result;
	return 0;
}