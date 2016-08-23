/* a[i]+a[j]=x*/
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
int sumprob(int a[],int size,int x)
{
	int l=0;
	int r=size-1;
	while(l<=r)
	{
		if(a[l]+a[r]==x)
			{	
				return 1;
			}
		else if (a[l]+a[r]<x)
			l++;
		else
			r--;
	}
	return 0;

}
int main()
{
	int start = clock();
	int a[5] = {5,4,3,2,1};
	quicksort(a,0,4);
	cout<<"Enter the sum ";
	int x;
	cin>>x;
	if(sumprob(a,5,x))
		cout<<"Yes there exist i and j with sum = "<<x<<endl;
	else
		cout<<"Sorry there exist no i and j with sum = "<<x<<endl;
	int stop = clock();
	cout << "time: " << (stop-start)/double(CLOCKS_PER_SEC)*1000 << endl;	
} 	