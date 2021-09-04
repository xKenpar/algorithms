#include "bits/stdc++.h"
using namespace std;

void swap(int* e1, int* e2)
{
    int temp = *e1;
    *e1 = *e2;
    *e2 = temp;
}

void merge(int *array, int l, int mid, int r) 
{
    int li = 0, ri = 0;

    int lSize = mid-l+1;
    int rSize = r-mid;
    int current = l;

    int lArray[lSize], rArray[rSize];

    for(int i = 0;i < lSize; i++)
        lArray[i] = array[l+i];

    for(int i = 0;i < rSize; i++)
        rArray[i] = array[mid+i+1];
    
    while(li < lSize && ri < rSize)
    {
        if(lArray[li] <= rArray[ri])
        {
            array[current++] = lArray[li++];
        }
        else
        {
            array[current++] = rArray[ri++];
        }
    }

    while(li < lSize){
        array[current++] = lArray[li++];
    }

    while(ri < rSize){
        array[current++] = rArray[ri++];
    }

}

void mergeSort(int* array, int l, int r)
{
    if(l >= r)
        return;
    
    int mid = l + (r-l)/2;
    mergeSort(array, l, mid);
    mergeSort(array, mid+1, r);
    merge(array, l, mid, r);
}

int main()
{
    int arr[] = {3, 7, 2, 9, 1, -6, 8, 0, 15, 12};
    int size = sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr, 0, size-1);
    
    for(int i = 0; i<size; i++)
        cout<<arr[i]<<" ";
}