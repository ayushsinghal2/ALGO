//minimum sub array containing elements {1,2,3,....k}
#include <iostream>
using namespace std;
int main()
{
	int a[15]={1,2,10,6,3,1,2,5,6,4,2,8,6,1,7};
	int c[7]={0}; ///change generic {1,2,3,4,5,6}
	int count=0;
	int i=0,j=0;
	int mini=0 , minj=15;
	for (int k = 0; k < 15; ++k)
	{
		if(count<6&&a[k]<=6)
		{
			c[a[k]]++;
			j++;
			if(c[a[k]]==1)
			{count++;}	
		}
		else if(count==6&&a[k]<=6)
		{
			if((j-i)<(minj-mini))
			{
				mini=i;
				minj=j;
			}
			c[a[k]]--;
			i++;
			if(c[a[k]]==0)
			count--;
		}
	}
	cout<<mini<<"     "<<minj<<endl;
}