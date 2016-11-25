//Matrix Chain Multiplication....
#include <iostream>
using namespace std;
int main()
{
	int p[] = {1,2,3,4};
	int n = sizeof(p)/sizeof(p[0]);
	int q;
	int m[n][n];
	for (int i = 0; i < n; ++i)
	{
		m[i][i]=0;
	}
	for (int l = 2; l < n; ++l)
	{
		for (int i = 1; i < n-l+1; ++i)
		{
			int j = i+l-1;
			m[i][j] = 999999; //infinity
			for (int k = i; k <= j-1; ++k)
			{
				q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
				if(q<m[i][j])
					m[i][j]=q;
			}
		}
	}
	cout<<"Minimum Multiplication are "<< m[1][n-1]<<endl;
}