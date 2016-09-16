#include <iostream>
using namespace std;
void swap(int * a, int * b)
{
	int temp = *a;
	*a=*b;
	*b=temp;
}
void topdownheap(int arr[],int i,int n)
{
	int largest = i; 
    int l = 2*i + 1;  
    int r = 2*i + 2;  
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i)
    {
        int temp = arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;
 
        // Recursively heapify the affected sub-tree
        topdownheap(arr,  largest,n);
    }
}
void buildheap(int arr[] ,int n )
{
	for (int i = (n / 2)-1; i >= 0; i--)
        topdownheap(arr, i, n);
}
int main()
{
	int heap[7]={5,7,6,10,15,17,12};
	int heap2[7]={1,2,3,6,9,5,10};
	int final[14]={65535};
	for (int i = 0; i < 7; ++i)
	{
		final[i]=heap[i];
	}
	for (int i = 0; i < 7; ++i)
	{
		final[7+i] = heap2[i];
		swap(&final[0],&final[7+i]);
		topdownheap(final,0,7+i);
		buildheap(final,7+i);
	}
	for (int i = 0; i < 14; ++i)
	{
		cout<<final[i]<<"   ,   ";
	}
}