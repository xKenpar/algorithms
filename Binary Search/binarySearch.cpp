#include "bits/stdc++.h"
using namespace std;

int binarySearch(int* array, int l, int r, int x)
{
	if(r>=l)
	{
		int mid =  l + (r-l)/2;
		
		if(array[mid] == x)
			return mid;
		
		if(array[mid] > x)
			return binarySearch(array, l, mid-1, x);
		
		return binarySearch(array, mid+1, r, x);
	}
	else
	{
		return -1;
	}
}

int main()
{
	int array[] = {1, 4, 7, 11, 21, 24, 26, 32, 37};
	
	int size = sizeof(array)/sizeof(array[0]);
	
	cout<<binarySearch(array, 0, size-1, 4);
}
