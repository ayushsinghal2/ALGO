//max sub array of length atmost l 
#include <iostream>
using namespace std;
int main()
{
	int a[15] = {5,3,2,1,6,11,55,12,41,14,0,24,31,17,23};
	int sum=a[0],i=0,max;
	int  start =0 ,end=0;
	int length;
	cout<<"Enter the max length ";
	cin>>length;
	max=sum;
	for (int j = 1; j < 15; ++j) // change it to generic....
	{
		sum += a[j];
		if(sum>max)
		{
			start = i;
			max=sum;
			end =j;
		}
		if(sum<0)
		{
			i=j+1;
			sum=0;
		}
		if(j-i==length)
		{
			sum-=a[i];
			i++;
		}
	}
	cout<<"Max sub array sum is "<<max<< " from "<<start+1<<" to "<<end+1<<endl;
}