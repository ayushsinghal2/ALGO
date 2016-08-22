// finding the number for inputted rank
#include <iostream>
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
void goodpivot(int a[], int low, int high)
{
	int j=0;
	for (int i = low; i < high; i+=5)    //////change generic......
	{
		bubbleSort(a,i,i+5);
	}
	for (int i = low+2; i < high; i+=5)
	{
		j+=i;
	}
}
int rank (int a[] , int i , int j ,int r )
{
	int fo = (i+j)/2;
	int temp = a[i];
	a[i]=a[fo];
	a[fo]=temp;
	int k = partition(a,i,j);
	if (r==j-k+1)
		return a[k];
	else if (r<j-k+1)
		return rank(a,k+1,j,r);
	else
		return rank(a,i,k,r-j+k);
}
int main()
{
	int a[15] = {5,3,2,1,6,11,55,12,41,14,0,24,31,17,23};
	cout<<"Enter the rank of the number (1-15)";
	int number;
	cin>>number;
	goodpivot(a,0,15);
	int ff = rank(a,0,14,number);
	cout<<ff<<endl;
}