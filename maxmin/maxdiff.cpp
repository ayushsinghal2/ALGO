#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int a[15] = {5,3,2,1,6,11,55,12,41,14,0,24,31,17,23};
	int max=0 , min =15000;
	for (int i = 0; i < 15; ++i) ///// change generic
	{
		if(a[i]>max)
			max=a[i];
		if(a[i]<min)
			min=a[i];
	}
	cout<<"Max Diff = "<<abs(max-min)<<endl;
}