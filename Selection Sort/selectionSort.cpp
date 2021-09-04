#include "bits/stdc++.h"
using namespace std;

void swap(int* e1, int* e2)
{
    int temp = *e1;
    *e1 = *e2;
    *e2 = temp;
}

void selectionSort(int* array, int size)
{
    for(int i = 0; i < size; i++)
    {
        int* min = array + i;

        for(int j = i+1; j < size; j++)
            if(array[j] < *min)
                min = array + j;
        
        swap(array+i, min);
    }
}

int main()
{
    int arr[] = {3, 7, 2, 9, 1, -6, 8, 0, 15, 12};
    int size = sizeof(arr)/sizeof(arr[0]);

    selectionSort(arr, size);
    
    for(int i = 0; i<size; i++)
        cout<<arr[i]<<" ";
}
