#include <iostream>
using namespace std;
int max(int a, int b) { return (a > b)? a : b; }
int main()
{
	int val[] = {60,100,120};
	int wt[] = {10,20,30};
	int w ;
	cout<<"Enter the max capacity of Knapsack ...";
	cin>>w;
	int n = sizeof(val)/sizeof(val[0]);
	int k[n+1][w+1];
	for (int i = 0; i <= n ; ++i)
	 {
	 	for (int j = 0; j <=w; ++j)
	 	{
	 		if(i==0||j==0)
	 			k[i][j]=0;
	 		else if(wt[i-1]<=j)
	 			k[i][j] = max(val[i-1]+k[i-1][j-wt[i-1]],k[i-1][j]);
	 		else
	 			k[i][j]=k[i-1][j];
	 	}
	 } 
	 cout<<"MAX Profit is "<<k[n][w]<<endl;
}