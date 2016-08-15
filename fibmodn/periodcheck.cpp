#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	fstream f;
	int x;
	f.open("period.bin",ios::in | ios::binary);
	while(!(f.eof()))
	{
		f.read((char*)&x,sizeof(x));
		cout<<x<<endl;
	}
	f.close();
}