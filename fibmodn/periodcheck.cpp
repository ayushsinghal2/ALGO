#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	fstream f;
	int x;
	int n=1;
	f.open("period.bin",ios::in | ios::binary);
	while(!(f.eof()))
	{
		f.read((char*)&x,sizeof(x));
		cout<<n++<<"    "<<x<<endl;
	}
	f.close();
}