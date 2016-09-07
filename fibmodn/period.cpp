#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
int main()
{
	fstream o;
	o.open("period.bin",ios::out | ios::app | ios::binary);
	int f=0,s=1,next;
    int nooo;
    cin>>nooo;
	for (int n = 1; n <=(6*nooo)+1; ++n) ////can be modified for all numbers...
	{
    	next=(f+s)%nooo;
    	f=s;
    	s=next;
    	o.write((char*)&next,sizeof(next));
    	if (n>1&&f==0&&s==1)
    	{
    			cout<<n;
    			break;
    	}	
	}
	o.close();
}