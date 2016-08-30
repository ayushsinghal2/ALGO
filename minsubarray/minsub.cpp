//min sub array with sum atleast k
//complexity is o(n^2) min length  ..... 
//http://ideone.com/Xztnsv for o(n) solution with extra space
#include <iostream>
using namespace std;
int main()
{
	int a[15] = {-5,3,2,-1,-6,11,55,12,41,14,0,-24,-31,-17,-23};
	int sum=0 ,i=0;
	int min = 15;
	int start = 0 ,end = 0;
	cout<<"Enter the min addition ";
	int s;
	cin>>s;
	for (int j = 0; j<15; ++j)
	{
		sum=sum+a[j];
		while(sum>=s && start <=j)
		{
			if(min>j-i+1)
				{
					min=j-i+1;
					start = i+1;
					end = j+1;
				}
			sum-=a[i];
			i++;
		}
		
	}
	cout<<"Minimum length is ...."<<min<<endl;
	cout<<"start "<<start<<endl;
	cout<<"end "<<end<<endl;
}