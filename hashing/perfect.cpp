//perfect hashing implementation ....
#include <iostream>
#include <cstdlib>
#include <ctime> 
#include <cmath>
using namespace std;
long int hash(int a ,int x ,int b, int p, int m)
{
	return (((a*x)+b) % p) % m;
}
/*struct ha
{
	int a;
	int b;
	int p;
	int m;
	int* numbers;
};*/
int main()
{
	int no [10]={1,2,3,4,5,6,7,8,9,10};
	int ht[20]={0};
	int a,b,p,m;
	srand (time(NULL));
	a = rand()%10+1;
	b = rand()%997;
	p = 997; //large prime number .....
	m = 20; 
	cout<<"a = "<<a<<" b = "<<b<<endl;
	for (int i = 0; i < 10; ++i)
	{
		int c = hash(a,no[i],b,p,m);
		if(ht[c]>0)
		{
			ht[c]++;
		}
		else
			ht[c]=1;
	}

	for (int i = 0; i < 20; ++i)
	{
		cout<<ht[i]<<endl;
	}

}