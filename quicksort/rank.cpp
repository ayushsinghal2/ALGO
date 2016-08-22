// find the rank of the given number
#include <iostream>
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
int rank (int a[] , int low , int high ,int p )
{
	int temp = a[low];
	a[low] = a[p];
	a[p]=temp;
	int ans = partition(a,low,high);
	return ans;
}
int main()
{
	int a[5] = {5,3,2,1,6};
	cout<<"Enter the number you want to find the rank  (5,3,2,1,6)";
	int number;
	cin>>number;
	int i;
	for (i = 0; i < 5; ++i)
	{
		if(a[i]==number)
			break;
	}
	int ff = rank(a,0,4,i);
	cout<<5-ff<<endl;
}