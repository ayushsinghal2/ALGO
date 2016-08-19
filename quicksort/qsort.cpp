#include <iostream>
#include <ctime>
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
void quicksort(int a[],int low,int high)
{
	if(low<high)
	{
	int k = partition(a,low,high);
	quicksort(a,low,k);
	quicksort(a,k+1,high);
	}
}
int main()
{
	int start = clock();
	int a[5] = {5,4,3,2,1};
	quicksort(a,0,4);
	for (int i = 0; i < 5; ++i)
	{
		cout<<a[i]<<endl;
	}
	int stop = clock();
	cout << "time: " << (stop-start)/double(CLOCKS_PER_SEC)*1000 << endl;	
} 	