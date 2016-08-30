//max sub array for a fixed length 
#include <iostream>
using namespace std;
int main()
{
	int a[4] = {-5,3,2,-1};
	int sum=0,i=0,max=0;
	int length;
	cout<<"Enter the length (1-4) ";
	cin>>length;
	for (int l = 0; l < length; ++l)
	{
		sum+=a[l];
	}
	max=sum;
	for (int j = length; j < 4; ++j,i++) // change it to generic....
	{
		sum-=a[i];
		sum += a[j];
		if(sum>max)
		{
			max=sum;
		}
	}
	cout<<"Max sub array sum is "<<max<<endl;
}