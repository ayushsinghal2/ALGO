//program to do traversal using min heap.....the graph is given as adjacency list ....
//dijikstra...
#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
	int no;
	int pri;
};
class graph
{
public:
	int status[5];        //0 for green 1 for yellow 2 for blue....
	int prev [5];         //previous node ...... (1,2,....)
	int am [5][5]; 
	int weight [5][5];       //change generic...
	graph()
	{
		//temp contains weight of all edges 0 implies no edge is present...
		     int temp [] [5] ={0,3,0,4,0,
			  0,0,9,2,0,
			  0,0,0,0,0,
			  0,0,0,0,6,
			  0,3,1,0,0	
			 }; 
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j< 5; ++j)
			{
				weight[i][j] = temp[i][j];
				if(temp[i][j]!=0)
					am[i][j]=1;
				else
					am[i][j]=0;
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
class myComparator 
{
public:
	int operator()(const node& p1, const node& p2)
	{
		return p1.pri > p2.pri;
	}
};
class hfs
{
	priority_queue <node, vector<node>, myComparator > pq; //minheap.... 
	//(priority_queue <datatype , vector <type> , comparator <datatype>>)
	//greater is an inbuilt function in stl....
	//you can have your own comparator ...
	node n [5];
public:
	void visit(graph g)
	{
		for (int i = 0; i < 5; ++i)
		{
			n[i].no = i;
			n[i].pri = 0; 
		}
		pq.push(n[0]);
		g.status[0] = 1;
		while(!pq.empty())
		{
			node temp = pq.top();
			pq.pop();
			int i = temp.no;
			g.status[i] = 2;
			for (int j = 0; j < 5; ++j)
			{
				if(g.status[j]==0 && g.am[i][j]==1) //adding all the neighbours to the heap...
				{
					n[j].pri = n[i].pri + g.weight[i][j];
					g.prev[j] = i;
					g.status[j]=1;
					pq.push(n[j]);
				}
				else if(g.status[j]==1 &&g.am[i][j]==1) //relaxing the weights ....
				{
					if(n[j].pri>n[i].pri+g.weight[i][j])
					{
						n[j].pri = n[i].pri + g.weight[i][j];
						g.prev[j] = i;
					}
				}
			}
		}
		g.displaytr();	
	}
	
};
int main()
{
	hfs b;
	graph h;
	b.visit(h);
}