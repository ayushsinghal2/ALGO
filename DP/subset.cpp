//subset sum dp ......
#include <iostream>
using namespace std;
int main()
{
	int a[10] = {5,7,9,12,1,2,6,15,11,29}; //change generic
	int x;
	cout<<"Enter X ..."<<endl;
	cin>>x;
	int t[9][x];
	for (int i = 0; i < x; ++i)
	{
		t[i][0] = 0;
		t[0][i] = 0;
		
	}
	for (int i = 1; i < 10; ++i)
	{
		for (int j = 1; j < x; ++j)
		{
			if(t[i-1][j] + a[i-1] > j)
				t[i][j] = t[i-1][j];
			else
			{
				t[i][j] = ((t[i-1][j-a[i-1]+a[i-1]]>t[i-1][j])?(t[i-1][j-a[i-1]+a[i-1]]):(t[i-1][j]));
			}
		}
	}
	cout<<t[10][x-1]<<endl;
}