#include<iostream>
using namespace std;
int visited[10];
class graph
{
	int l,n,i,j,cost[10],mat[10][10],dest[10],path[20];
	int edges,min,ncost,x,curentdest,s,d,final,k,m;
	public:
	graph()
	{
		edges=1;
		ncost=0;
	}
	void dijkstraw(int mat[10][10],int n);
	void read();
	void display();
};
void graph::read()
{
 	cout<<"\n enter number of vertices:-";
	cin>>n;
 	cout<<"\n enter weight of edges in this form of adjacency matrix:-";
 	for(i=1;i<=n;i++)
 	{
 		for(j=1;j<=n;j++)
		{
 			cin>>mat[i][j];
 			if(mat[i][j]==0)
 			mat[i][j]=9999;
 		}
 	}
 	dijkstraw(mat,n);
}
void graph::dijkstraw(int mat[10][10],int n)
{
	cout<<"Enter the source node:";
	cin>>s;
	cout<<"Enter the destination node:";
	cin>>d;
	for(i=0;i<=n;i++)
 	{
 		cost[i]=9999;
 	}
 	cost[s]=0;
 	x=s;
 	visited[x]=1;
 	while(x!=d)
 	{
 		curentdest=cost[x];
 		min=9999;
 		for(i=1;i<=n;i++)
 		{
 			if(visited[i]==0)
 			{
 				ncost=curentdest+mat[x][i];
 				if(ncost<cost[i])
 				{
 					cost[i]=ncost;
 					dest[i]=x;
 				}
 				if(cost[i]<min)
 				{
 					min=cost[i];
 					k=i; 
 				}
 			}
 		}
 		x=k;
 		visited[x]=1;
	}
	display();
}
void graph::display()
{
 	l=d;
 	path[final]=d;
 	final++;
 	while(dest[l]!=s)
 	{
 		m=dest[l];
 		l=m;
 		path[final]=l;
 		final++;
 	}
 	path[final]=s;
 	cout<<"\n shortest path is :";
 	for(l=final;l>=1;l--)
 	{
 		cout<<"\n "<<path[l]<<"-->"<<path[l-1]<<":"<<mat[path[l]][path[l-1]];
 	}
 	cout<<"\n total cost :"<<cost[d];
}
int main()
{
 graph x;
 x.read();
 return 0;
 
}

