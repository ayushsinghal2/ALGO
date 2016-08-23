/*max(a[j]-a[i]) for i<j*/
#include <iostream>
using namespace std;
int main()
{
		int a[15] = {5,3,2,1,6,11,55,12,41,14,0,24,31,17,23};
		int i=0,max=a[1]-a[0];
		for (int j = 1; j<15 ; ++j)
		{
			if(a[j]-a[i]>max)
				max=a[j]-a[i];
			if(a[j]<a[i])
				i=j;
		}
		cout<<"Max possible value is "<<max<<endl;
}