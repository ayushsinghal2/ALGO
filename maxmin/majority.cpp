/*majority*/
#include <iostream>
using namespace std;
int main()
{
		int a[15] = {30,2,10,5,100,4,5,5,123,5,5,151,5,3,121};
		int A=0 , B=0 , c1=0 , c2=0; 
		for (int i = 0; i<15 ; ++i) ///change generic
		{
			if(c1>0 && A==a[i])
				c1++;
			else if(c2>0 && B==a[i])
				c2++;
			else if(c1==0)
			{
				c1++;
				A=a[i];
			}

			else if(c2==0)
			{
				c2++;
				B=a[i];
			}
			else if(a[i]!=A && a[i]!=B)
			{
				if(c1<c2)
				{
					c1=1;
					A=a[i];
				}
				else
				{
					c2=1;
					B=a[i];
				}
			}
		}
		int count=0;
		int count1=0;
		cout<<A<<endl<<B<<endl;
		for (int i = 0; i < 15; ++i)
		{
			if(a[i]==A)
			 count++;
			else
				if(a[i]==B)
					count1++;
		}
		if(count>5)
			cout<<"Majority element is "<<A<<endl;
		if(count1>5)
			cout<<"Majority element is "<<B<<endl;
}