#include <ctime>
#include <iostream>

using namespace std;
int main()
{
	int start = clock();
	int a[2][2] = {{1,1},{1,0}};
	int res[2][2] = {1,1,1,1};
	long long int n;
	cin>>n;
	while(n>0)
	{
		if((n%2)==0)
		{
			int D[2][2];
			for(int R=0;R<2;R++)
   			for(int C=0;C<2;C++)
   			{
      			D[R][C]=0;
      			for(int T=0;T<2;T++)
        			D[R][C]+=res[R][T]*res[T][C];
    		}
    	for(int i=0;i<2;i++)
    		for (int j = 0; j < 2; ++j)
    		{
    			res[i][j]=D[i][j]%100;
    			a[i][j]=res[i][j];
    		}
		}
		else 
		{
			int D[2][2];
			for(int R=0;R<2;R++)
   				for(int C=0;C<2;C++)
   				{
      				D[R][C]=0;
      				for(int T=0;T<2;T++)
        				D[R][C]+=res[R][T]*a[T][C];
    			}
    		for(int i=0;i<2;i++)
    			for (int j = 0; j < 2; ++j)
    			{
    				res[i][j]=D[i][j]%100;
    			}
		}
		n=n/2;	
	}
	cout<<res[1][0]<<endl;
	int stop = clock();
	cout << "time: " << (stop-start)/double(CLOCKS_PER_SEC)*1000 << endl;	
}