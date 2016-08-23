/* a[i]+a[j]=a[k]*/
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
int sumprob(int a[],int size)
{
	
	for (int k = 0; k < size; ++k)
	{
		int l=0;
		int r=size-1;
		while(l<=r)
		{
			if(a[l]+a[r]==a[k])
				{	
					return 1;
				}
			else if (a[l]+a[r]<a[k])
				l++;
			else
				r--;
		}
	}
	
	return 0;

}
int main()
{
	int start = clock();
	int a[5] = {5555,400,80,55,1111};
	quicksort(a,0,4);
	if(sumprob(a,5))
		cout<<"Yes there exist i,j and k pair"<<endl;
	else
		cout<<"Sorry there exist no i,j and k pair "<<endl;
	int stop = clock();
	cout << "time: " << (stop-start)/double(CLOCKS_PER_SEC)*1000 << endl;	
} 	