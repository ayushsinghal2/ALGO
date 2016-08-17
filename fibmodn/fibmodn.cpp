#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
int main()
{
	int x[2][2] = {{1,1},{1,0}};
	int y[2][2] = {1,0,0,1};
	fstream in;
	in.open("number.bin",ios::in | ios::binary);
	int start = clock();
	in.seekg(0,ios::end);
	int size = in.tellg(); 
	cout<<in.tellg()<<endl;
	int n=5;
	while(size>0)
	{
		int l;
		size-=4;
    	in.seekg(size,ios::beg);
    	in.read((char*)&l,sizeof(l));
		int temp[2][2];
		if(l!=0)
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
    		
	}
	cout<<y[1][0]<<endl;
	int stop = clock();
	cout << "time: " << (stop-start)/double(CLOCKS_PER_SEC)*1000 << " ms"<<endl;
	in.close();	
}