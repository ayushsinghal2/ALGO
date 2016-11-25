//minimum edit distance ...
#include <iostream>
using namespace std;
int min(int a , int b, int c )
{
	if(a<=b && a<=c)
		return a;
	else if(b<=c && b<=a)
		return b;
	else
		return c;
}
int main()
{
	char abc [] ={"ABCD"};
	char def [] ={"DCBA"};
	int a = 5;
	int d = 7;
	int r = 10;
	int t[4][4]; //length of abc and def as the dimensions...

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if(i==0||j==0)
				t[i][j]=0;
			else if(abc[i]==def[j])
				t[i][j] = t[i-1][j-1];
			else 
				t[i][j]=min((t[i-1][j-1]+r) , (t[i][j-1]+a),   (t[i-1][j]+d ));
		}
	}
	cout<<"Minimum edit distance is   "<<t[3][3]<<endl;
}