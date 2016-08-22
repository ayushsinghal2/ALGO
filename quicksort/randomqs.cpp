#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
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
int randompar(int a[] , int low , int high)
{
	int i = low + (rand()%(high-low));
	int temp = a[low];
	a[low] = a[i];
	a[i] = temp;
	return partition(a,low,high);
}
void quicksort(int a[],int low,int high)
{
	if(low<high)
	{
	int k = randompar(a,low,high);
	quicksort(a,low,k);
	quicksort(a,k+1,high);
	}
}
int main()
{
	int start = clock();
	int a[5] = {5,3,2,1,6};
	quicksort(a,0,4);
	for (int i = 0; i < 5; ++i)
	{
		cout<<a[i]<<endl;
	}
	int stop = clock();
	cout << "time: " << (stop-start)/double(CLOCKS_PER_SEC)*1000 << endl;	
} 	