//program to do traversal using min heap.....the graph is given as adjacency list ....
#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
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
class hfs
{
	 priority_queue <int, vector<int>, greater<int> > pq; //minheap.... 
	 //(priority_queue <datatype , vector <type> , comparator <datatype>>)
	 //greater is an inbuilt function in stl....
	 //you can have your own comparator ...

	
};
int main()
{
	bfs b;
	graph h;
	b.visit(h);
}