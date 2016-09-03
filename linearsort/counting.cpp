//counting sort on array with {1,2,3,...,k}
#include <iostream>
using namespace std;
int main()
{
	int a[20]={1,5,4,2,6,3,2,1,6,5,4,2,3,6,5,4,2,1,4,3};
	int count[7]={0};//change generic
	int b[20]={-1};
	for (int i = 0; i < 20; ++i)
	{
		count[a[i]]++;
	}
	for (int i = 1; i < 7; ++i)
	{
		count[i]=count[i-1]+count[i];
	}
	for (int i = 19; i >= 0; --i)
	{
		count[a[i]]--;
		b[count[a[i]]]=a[i];
		
	}
	for (int i = 0; i < 20; ++i)
	{
		cout<<b[i]<<endl;
	}

}