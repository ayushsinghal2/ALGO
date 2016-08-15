#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	fstream f;
	f.open("period.bin", ios::in | ios::binary);
	//assuming period is 300
	cout<<"Enter the number....";
	int n;
	cin>>n;
	n=n%300;
	cout<<n<<endl;
	f.seekg(4*(n-2));
	int x;
	f.read((char*)&x,sizeof(int));
	cout<<x;
	f.close();
	return 0;
}