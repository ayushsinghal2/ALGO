//perfect hashing implementation ....
//doesnot work if one of the elements is 0 (zero......) 
//what to do if 2 elements are same ????
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
	list <int> tt[20]; 
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
		tt[c].push_back(no[i]);
		ni[c]++;
	}
	int count=0;
	for (int i = 0; i < m; ++i) 
	{
		count += ni[i]*ni[i];
		/*cout<<ni[i]<<endl; */
	}
	if(count<m)
	{
		ha* ht = (ha*) calloc(20,sizeof(ha));
		for (int i = 0; i < 20; ++i) 
		{
			if(ni[i]>1)
			{
				int cc =0;
				recompute:
				cc++;
				cout<<cc<<endl;
				ht[i].numbers = (int * )calloc(ni[i]*ni[i],sizeof(int));
				srand (time(NULL));
				ht[i].a = rand()%10+1;
				ht[i].b = rand()%997;
				ht[i].p = 997;
				ht[i].m = ni[i]*ni[i];
				for (list<int>::iterator j = tt[i].begin(); j != tt[i].end(); ++j)
				{
					int d = hash(ht[i].a,*j,ht[i].b,ht[i].p,ht[i].m);
					if(cc>5)
					{
						cout<<"Too many reattempts run the program again.....";
						break;
					}
					if(ht[i].numbers[d]!=0 && ht[i].numbers[d]!=*j)
						goto recompute;
					else 
						{
							ht[i].numbers[d] = *j;
							cout<<ht[i].numbers[d];
						}

				}

			}
			else 
			{
				if(ni[i]==0)
				{}
				else
				{
					ht[i].numbers = new int ;
					list <int> :: iterator k;
					k = tt[i].begin();
					ht[i].numbers[0] = *k;
				}
			}
		}
	}
	else
	{
		cout<<"FATAL";
	}

}