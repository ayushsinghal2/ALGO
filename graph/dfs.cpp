//program to do dfs traversal the graph is given as adjacency list ....
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
	int st[5]; //start time
	int ft[5]; //finish time
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
			st[i] = tp[i];
			ft[i] = tp[i];
		}
	}
	void displaytr()
	{
		for (int i = 0; i < 5; ++i)
		{
			cout<<"Previous Node = "<<prev[i]<<endl<<"Discover Time = " <<st[i]<<endl
			<<"End Time = "<<ft[i]<<endl;
		}
	}
};
class dfs
{
	list <int> ll;           //data structure for the list stack.... 
public:
	void visit (graph g)
	{
		int tim = 1;
		ll.push_back(0);
		g.status[0]=1;
		g.st[0] = tim;
		while(!ll.empty())
		{
			int i = ll.back();
			ll.pop_back();
			g.status[i]=2;
			tim++;
			for (int j = 0; j < 5; ++j)
			{
				
				if(g.am[i][j]==1 && g.status[j]!=2) //adding all neighbours to the stack...
				{
					ll.push_back(j);
					g.prev[j] = i;
					g.status[j] = 1; 
					g.st[j] = tim;
				}
				if (g.status[j]==2)
				{
					if(g.ft[j]==-1)
						{g.ft[j]=tim;}
				}
			}
		}
		g.displaytr();
	}
};
int main()
{
	dfs b;
	graph h;
	b.visit(h);
}