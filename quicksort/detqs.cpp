/* random qs*/
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
void bubbleSort(int arr[], int start, int end)
{
   int i, j;
   for (i = start; i < end-1; i++)         
       for (j = start; j < end-1; j++) 
           if (arr[j] > arr[j+1])
              {
              	int temp = arr[j];
              	arr[j]=arr[j+1];
              	arr[j+1] = temp; 
              }
}
void goodpivot(int a[],  int low, int high)
{
	int j=0;
	for (int i = low; i < high ; i+=5)    //////change generic......
	{
		bubbleSort(a,i,i+5);
	}
}
int  partition(int a[], int low, int high )
{//partition
	int pivot = a[low];
	int left =low;
	int right = high;
	while(left<=right)
	{
		while(a[left]<=pivot)
			{left++;}
		while(a[right]>pivot)
			{right--;}
		if(left<right)
		{
			/////swapping
			int temp = a[left];
			a[left]=a[right];
			a[right]=temp;
		}
	}
	a[low]=a[right];
	a[right]=pivot;
	return right;
	
}
int detpar(int a[] , int low , int high)
{
	int i = (low+high)/2;
	int temp = a[low];
	a[low] = a[i];
	a[i] = temp;
	return partition(a,low,high);
}
void quicksort(int a[],int low,int high)
{
	if(low<high)
	{
	int k = detpar(a,low,high);
	quicksort(a,low,k);
	quicksort(a,k+1,high);
	}
}
int main()
{
	int start = clock();
	int a[15] = {5,3,2,1,6,11,55,12,41,14,0,24,31,17,23};
	goodpivot(a,0,15);
	quicksort(a,0,14);
	for (int i = 0; i < 15; ++i)
	{
		cout<<a[i]<<endl;
	}
	int stop = clock();
	cout << "time: " << (stop-start)/double(CLOCKS_PER_SEC)*1000 << endl;	
} 	