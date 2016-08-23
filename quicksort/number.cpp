// find the number of the given rank........
#include <iostream>
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
int rank (int a[] , int i , int j ,int r )
{
	int fo = i + (rand()%(j-i+1));
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
	int a[6] = {5,1,8,2,4,6};
	int number=0;
	while(number!=1000)
	{cout<<"Enter the rank of the number (1-5)";
	
	cin>>number;
	int ff = rank(a,0,5,number);
	cout<<ff<<endl;
	}
}