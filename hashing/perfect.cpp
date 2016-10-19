//perfect hashing implementation ....
#include <iostream>
#include <cstdlib>
#include <ctime> 
#include <cmath>
#include <list>
using namespace std;
long int hash(int a ,int x ,int b, int p, int m)
{
	return (((a*x)+b) % p) % m;
}
class ha
{	
public:
	int a;
	int b;
	int p;
	int m;
	int* numbers;
	ha()
	{
		a=b=p=m=0;
		numbers = NULL;
	}
};
int main()
{
	int no [10]={1,2,3,4,5,6,7,8,9,10};
	int ni[20]={0};
	int* 
	int a,b,p,m;
	srand (time(NULL));
	a = rand()%10+1;
	b = rand()%997;
	p = 997; //large prime number .....
	m = 20; 
	cout<<"a = "<<a<<" b = "<<b<<endl;
	for (int i = 0; i < 10; ++i) //change generic
	{
		int c = hash(a,no[i],b,p,m);
		if(ni[c]==0)
		{
			ni[c]++;
		}
		else
		{

		}
	}
	int count=0;
	for (int i = 0; i < m; ++i) 
	{
		count += ni[i]*ni[i]; 
	}
	if(count<m)
	{
		ha* ht = (ha*) calloc(20,sizeof(ha));
		for (int i = 0; i < 10; ++i) 
		{
			int c = hash(a,no[i],b,p,m);
			if(ht[i].numbers == NULL)
			{
					ht[i].numbers = new int[ni[c]*ni[c]];
					srand (time(NULL));
					ht[i].a = rand()%10+1;
					ht[i].b = rand()%997;
					ht[i].p = 997;
					ht[i].m = ni[c]*ni[c];
					int d = hash(ht[i].a,no[i],ht[i].b,ht[i].p,ht[i].m);

			}

		}
	}

}