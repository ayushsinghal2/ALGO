#include <ctime>
#include <iostream>

using namespace std;
int main()
{
	int start = clock();
	int x[2][2] = {{1,1},{1,0}};
	int y[2][2] = {1,0,0,1};
	long long int n;
	cin>>n;
	while(n!=0)
	{
		int temp[2][2];
		if(n%2!=0)
		{	
			for(int i=0;i<2;i++)
   				for(int j=0;j<2;j++)
   				{
      				temp[i][j]=0;
      				for(int k=0;k<2;k++)
        				temp[i][j]+=y[i][k]*x[k][j];
    			}
    		for(int i=0;i<2;i++)
    			for (int j = 0; j < 2; ++j)
    			{
    				y[i][j]=temp[i][j]%100;
    			}
		}
		for(int i=0;i<2;i++)
   			for(int j=0;j<2;j++)
   			{
      			temp[i][j]=0;
      			for(int k=0;k<2;k++)
        			temp[i][j]+=x[i][k]*x[k][j];
    		}
    	for(int i=0;i<2;i++)
    		for (int j = 0; j < 2; ++j)
    		{
    			x[i][j]=temp[i][j]%100;
    			
    		}
		
		n=n/2;
		
	}
	cout<<y[1][0]<<endl;
	int stop = clock();
	cout << "time: " << (stop-start)/double(CLOCKS_PER_SEC)*1000 << endl;	
}