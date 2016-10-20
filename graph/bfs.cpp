//program to do bfs traversal the graph is given as adjacency list ....
#include <iostream>
#include <cstdlib>
#include <list>
using namespace std;
class graph
{
public:
	int status[5];        //0 for green 1 for yellow 2 for blue....
	int prev [5];         //previous node ...... (1,2,....)
	int am [5][5];        //change generic...
	graph()
	{
		int temp [] [5] ={0,1,0,1,0,
			  0,0,1,1,0,
			  0,0,0,0,0,
			  0,0,0,0,1,
			  0,1,1,0,0	
			 }; 
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j< 5; ++j)
			{
				am[i][j] = temp[i][j];
			}
		}
		int ts[5] = {0,0,0,0,0};//change generic...
		int tp[5] = {-1,-1,-1,-1,-1};//change generic...
		for (int i = 0; i < 5; ++i)
		{
			status[i] = ts[i];
			prev[i]=tp[i];
		}
	}
	void displaytr()
	{
		for (int i = 0; i < 5; ++i)
		{
			cout<<"Status = "<<status[i]<<endl<<" Previous Node = "<<prev[i]<<endl;
		}
	}
};
class bfs
{
	list <int> ll;           //data structure for the list.... 
public:
	void visit (graph g)
	{
		ll.push_back(0);
		g.status[0] = 1;
		while(!ll.empty())
		{
			list <int> :: iterator i = ll.begin();
			//cout<<*i<<endl;
			ll.pop_front();
			g.status[*i] = 2;
			for(int j=0;j<5;j++)//change generic ...
			{	
				if(g.am[*i][j]==1 && g.status[j]==0) //adding all the neighbouring to that edge ..
				{
					cout<<*i<<" " <<j<<endl;
					g.status[j] = 1;
					g.prev[j]  = *i;
					ll.push_back(j);
					
				}
			}

		}
		g.displaytr();
	}
};
int main()
{
	bfs b;
	graph h;
	b.visit(h);
}