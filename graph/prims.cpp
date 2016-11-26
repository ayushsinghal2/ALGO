//prims algo ... need corrections...
#include <map>
#include <list>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node
{
	int index;
	
public:
	int distance; //need to figure out something.....
	Node()
	{
		index = -1;
		distance = -1;
	}
	int getindex()
	{
		return index;
	}
	int getdistance()
	{
		return distance;
	}
	void setindex(int i)
	{
		index = i;
	}
	void setdistance(int i)
	{
		distance = i;
	}
};
class myComparator 
{
public:
	int operator()(const Node& p1, const Node& p2)
	{
		/*int a = p1.getdistance();
		int b = p2.getdistance(); //need to figure out how to run this....
		return a > b;
		*/
		return p1.distance - p2.distance;
	}
};
class Graph
{
	map<int,list<Node> > al;
public:
	Graph(int no)
	{
		for (int i = 0; i < no; ++i)
		{
			list<Node> lol; 
			al[i] = lol;
		}
	}
	void putvalues() // example graph ...
	{
		setedge(0,1,40);
		setedge(0,2,20);
		setedge(0,3,13);
		setedge(1,3,14);
		setedge(2,3,25);
		setedge(2,4,15);
		setedge(3,4,30);
	}
	void setedge(int source , int destination , int cost)
	{
		list <Node> f = al[source];
		Node temp ; 
		temp.setindex(destination);
		temp.setdistance(cost);
		f.push_back(temp);
		al[source] = f;
		temp.setindex(source);
		f = al[destination];
		f.push_back(temp);
		al[destination] = f;
	}
	list <Node> getvertex(int index)
	{
		return al[index];
	}
	void calMST(int dis[][5],int V) //number of vertices = V
	{
		priority_queue <Node, vector<Node>, myComparator > pq; //min heap....
		vector<bool> inMST(V, false);
		vector<int> parent(V, -1);
		Node start;
		start.setindex(0);
		start.setdistance(0); 
		pq.push(start);
		inMST[start.getindex()]=true;
		while(!pq.empty())
		{
			Node u = pq.top();
			pq.pop();
			list <Node> ad = al[u.getindex()];
			inMST[u.getindex()]=true;
			for (list<Node>::iterator i = ad.begin(); i != ad.end(); ++i)
			{
				Node v = *i;
				int fck = v.getdistance();
				if(inMST[v.getindex()]==false && dis[u.getindex()][v.getindex()]>fck)
				{
					dis[u.getindex()][v.getindex()] = fck;
					pq.push(v);
					parent[v.getindex()]=u.getindex();
				}
			} 
		}
		int count = 0;
		for (std::vector<int>::iterator i = parent.begin() ; i != parent.end(); ++i,count++)
		{
			cout<<count<<" -> "<<*i<<endl;
		}
	}
};
int main()
{
	Graph g(5);
	g.putvalues();
	int dis[5][5];
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			dis[i][j]=65536;
		}
	}
	g.calMST(dis,5);
}