/*max(a[j]-a[i]) for i<j<i+l*/
#include <iostream>
using namespace std;
int main()
{
		int a[15] = {5,3,2,1,6,11,55,12,41,14,0,24,31,17,23};
		int i=0,max=a[1]-a[0];
		int l;
		cout<<"Enter l";
		cin>>l;
		for (int i = 0; i<15 ; ++i) ///change generic
		{
			if(a[j]-a[i]>max)
				max=a[j]-a[i];
			if(a[j]>a[j-l])
				i=j-l;
		}
		cout<<"Max possible value is "<<max<<endl;
}