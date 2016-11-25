//subset sum dp ......
#include <iostream>
using namespace std;
int main()
{
	int a[10] = {5,7,9,12,1,2,6,15,11,29}; //change generic
	int x;
	cout<<"Enter X ..."<<endl;
	cin>>x;
	int t[10][x];
	for (int j = 1; j < x; ++j)
	{
		t[1][j] = (j==a[j])?1:0;	
	}
	for (int i = 1; i < 10; ++i)
	{
		for (int j = 0; j < x; ++j)
		{
			if(t[i-1][j]==1||(j-a[i]>0 && t[i-1][j-a[i]]==1))
				t[i][j]=1;
			else
				t[i][j]=0;
		}
	}
	cout<<"ANSWER IS ....."<<t[9][x-1]; //0 for not possible 1 for possible...
}