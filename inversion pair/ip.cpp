//inversion pair
#include <iostream>
#include <cstdlib>
using namespace std;
int mergesort(int a[],int left,int right);
int merge(int a[],int left,int mid,int right);
int main()
{
	int a[5] = {1, 20, 6, 4, 5};
  	cout<<mergesort(a,0,4)<<endl;
}
int merge(int a[],int left,int mid,int right)
{
	int temp[7];//temporary storage
	int i =left;//first subarray
	int j= mid;//second subarray
	int k=left;//whole count.....
	int count=0;
	while ((i <= mid - 1) && (j <= right))
	{
		if (a[i] <= a[j])
		{
			temp[k++] = a[i++];
		}
		else
		{
			temp[k++] = a[j++];
			count = count + (mid - i);
		}
	}
	while(i<=mid-i)
		temp[k++]=a[i++];
	while(j<=right)
		temp[k++]=a[j++];
	for (i = 0; i <= right ; ++i)
	{
		a[i]=temp[i];
	}
	return count;
}
int mergesort(int a[],int left,int right)
{
	int mid , count=0;
	if(right>left)
	{
		mid = (left+right)/2;
		count=mergesort(a,left,mid);
		count+=mergesort(a,mid+1,right);
		count+=merge(a,left,mid+1,right);
	}
	return count;
}
