/*
	NAME:: LUNGADE KIRAN SANJAY
	ROLL NO:: 39
	BATCH:: S2
	SUBJECT:: DATA STRUCTURES AND FILES
	PRACTICAL NO.:: 03
	TITLR:: KRUSKAL's ALGORITHM
*/
#include<iostream>
using namespace std;
int visited[10];
class graph
{
	int i,j,min,u,v,mincost,cost[10][10],edge,a,b,n;
	public:
		graph()
		{
			edge=1;
			mincost=0;
		}
		void kruskal(int cost[10][10],int n);
		void read();
};
void graph::read()
{
	cout<<"\nEnter number of vertices::";
	cin>>n;
	cout<<"\nEnter weight of edge in the form of Adjacency Matrix::";
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cin>>cost[i][j];
			if(cost[i][j]==0)
				cost[i][j]=99999;
		}
	}
	kruskal(cost,n);
}
void graph::kruskal(int cost[10][10],int n)
{
	while(edge<n)
	{
		min=99999;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(cost[i][j]<min)
				{
					min=cost[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		while(visited[u])
			u=visited[u];
		while(visited[v])
			v=visited[v];
		if(u!=v)
		{
			edge++;
			cout<<"\nEgde::"<<a<<"->"<<b<<"\tWeight::"<<min<<"\n";
			mincost=mincost+min;
			visited[v]=u;
		}
		cost[a][b]=cost[b][a]=99999;
	}
	cout<<"\nMinimum cost="<<mincost<<"\n";
}
int main()
{
	graph g;
	g.read();
}
