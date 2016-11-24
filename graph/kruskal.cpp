//kruskal's MST .....
//could be optimized....
#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
#include <list>
using namespace std;

class edge
{
public:
	int source;
	int destination;
	int weight;
	edge()
	{
		source=0;
		destination=0;
		weight=0;
	}
	edge(int s,int d, int w)
	{
		weight=w;
		source=s;
		destination=d;
	}
	void setedge(int s ,int d,int w)
	{
		weight=w;
		source=s;
		destination=d;
	}
};
bool compare(const edge& p1, const edge& p2)
{
		return p1.weight < p2.weight;
}
class graph
{
public:
	int colour[5];        //colouring the same connected components... //change generic  1,2,3,4,5
	list <edge> el ;
	graph()
	{
		el.push_back(*(new edge(0,1,1)));
		el.push_back(*(new edge(2,3,4)));
		el.push_back(*(new edge(3,4,5)));
		el.push_back(*(new edge(4,0,6)));
		el.push_back(*(new edge(1,2,2)));
		el.push_back(*(new edge(1,3,3)));
		el.sort(::compare);
	}
	void calMST()
	{
		vector <edge> mst;
		while(!el.empty())
		{
			edge e = el.front();
			el.pop_front();
			if(colour[e.source]!=colour[e.destination])
			{
				for (int i = 0; i < 5; ++i)
				{
					if(colour[i]==colour[e.destination])
						colour[i] = colour[e.source];
				}
				colour[e.destination]=colour[e.source];
				mst.push_back(e);
			}
		}
		for (std::vector<edge>::iterator i = mst.begin(); i != mst.end(); ++i)
		{
			edge e = *i;
			cout<<"Edge :  Source "<<e.source+1<<"     Destination "<<e.destination+1<<"     Weight "<<e.weight<<endl;
		}
	}
};

int main()
{
	graph g;
	g.calMST();
}