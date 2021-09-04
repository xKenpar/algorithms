#include "bits/stdc++.h"
using namespace std;

void swap(int* e1, int* e2)
{
    int temp = *e1;
    *e1 = *e2;
    *e2 = temp;
}

void bubbleSort(int* array ,int size)
{
    for(int i = 0; i < size-1; i++)
        for(int j = 0; j < size-i-1; j++)
            if(array[j] > array[j+1])
                swap(&array[j+1], &array[j]);
}

int main()
{
    int arr[] = {3, 7, 2, 9, 1, -6, 8, 0, 15, 12};
    int size = sizeof(arr)/sizeof(arr[0]);

    bubbleSort(arr, size);
    
    for(int i = 0; i < size; i++)
        cout<<arr[i]<<" ";
}
