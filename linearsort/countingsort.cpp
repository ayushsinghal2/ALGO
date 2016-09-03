// counting sort 0's and 1's only...
#include <iostream>
using namespace std;
int main()
{
	int a[10] = {0,1,0,1,1,1,0,1,0,1};
	int b[10]={-1};
	for (int i = 0 ,j=9,k=0 ; i < 10; ++i)//change generic
	{
		if(a[i]==0)
			b[k++]=0;
		else
			b[j--]=1;
	}
	for (int i = 0; i < 10; ++i)
	{
		cout<<b[i]<<endl;
	}
}