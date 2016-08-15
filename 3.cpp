#include <iostream>
using namespace std;
void swap(int &a,int &b)
{
	int temp = a;
	a=b;
	b=temp;
}
int main()
{
	int tc;
	cin>>tc;
	int result[5];
	while (tc!=0)
	{
		int n;
		int array[100]={0};
		int swapc[100]={0};
		int bribec=0;
		cin>>n;
		for (int i = 1; i < n; ++i)
		{
			cin>>array[i];
		}
		for (int i = 1; i < n; ++i)
		{
			if(array[i]==i)
				continue;
			else
			{
				cout<<swapc[i]<<"        ";
				cout<<array[i]<<endl;
				bribec++;
				swapc[i]++;
				if(swapc[i]>2)
					{break;result[tc]=-1;}
				swap(array[i],array[i+1]);
				swap(swapc[i],swapc[i+1]);
			}
		}
		cout<<result[tc]<<endl;
		tc--;
	}
}