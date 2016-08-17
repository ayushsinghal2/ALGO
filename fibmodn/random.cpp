#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
int main()
{
	int a ;
	fstream o;
	o.open("number.bin",ios::out |  ios::binary);
	for (int i = 0; i < 1000000; ++i)
	{
		a = (rand()%2);
		
		o.write((char *)&a,sizeof(a));
	}
	o.close();
}