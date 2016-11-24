//bellman ford..
#include <iostream>
#include <bits/stdc++.h>
#include <list>
using namespace std;
class node
{
public:
	int no;
	int prev;
	int distance;
	void set (int i)
	{
		no = i;
		prev = -1;
		distance = 65536;
	}
};
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
class graph
{
	list <edge> el;
	node n [5];
public:
	graph()
	{
		el.push_back(*(new edge(0,1,6)));
		el.push_back(*(new edge(0,4,7)));
		el.push_back(*(new edge(1,2,5)));
		el.push_back(*(new edge(1,3,-4)));
		el.push_back(*(new edge(1,4,8)));
		el.push_back(*(new edge(2,1,-2)));
		el.push_back(*(new edge(3,0,2)));
		el.push_back(*(new edge(3,2,7)));
		el.push_back(*(new edge(4,2,-3)));
		el.push_back(*(new edge(4,3,9)));
	}
	void initialize(int s)
	{
		for (int i = 0; i < 5; ++i) //change generic
		{
			n[i].set(i);
		}
		n[s].distance = 0;
	}
	void relax(edge e)
	{
		if(n[e.destination].distance > n[e.source].distance + e.weight) //e.destination = v ... e.source = u....
		{
			n[e.destination].distance = n[e.source].distance + e.weight;
			n[e.destination].prev = n[e.source].no;
		}
	}
	void bellman(int s)
	{
		initialize(s);
		for (int i = 0; i < 4; ++i) /// i=0 to numberof edge -1
		{
			for (std::list<edge>::iterator i = el.begin(); i != el.end(); ++i)
			{
				edge e = *i;
				relax(e);
			}
		}
		for (std::list<edge>::iterator i = el.begin(); i != el.end(); ++i)
		{
			edge e = *i;
			if(n[e.destination].distance > n[e.source].distance + e.weight) 
			{
				cout<<"NEGATIVE EDGE CYCLE .........."<<endl;
				exit(0);
			}
		}
		display();
	}
	void display()
	{
		for (int i = 0; i < 5; ++i)
		{
			cout<<"NODE :  No "<<n[i].no<<"     Previous "<<n[i].prev<<"     Distance "<<n[i].distance<<endl;
		}
	}
};
int main()
{
	graph g;
	g.bellman(0);
}
