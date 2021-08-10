#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;


int getMinIndex(int *distance,bool* visited,int n)
{
	int minVertex=-1;
	
	for(int i=0;i<n;i++)
	{
		if(!visited[i]&&(minVertex==-1 || distance[i]<distance[minVertex]))
		minVertex=i;
	}
	
	return minVertex;
}


void Dijkstras(int ** edges , int n, int src)
{
	int* distance=new int[n];
	bool* visited=new bool[n];
	
	for(int i=0;i<n;i++)
	{
		distance[i]=INT_MAX;
		visited[i]=false;
	}
	
	distance[src]=0;
	
	for(int i=0;i<n-1;i++)
	{
		int minIndex=getMinIndex(distance,visited,n);
		visited[minIndex]=true;
		
		for(int j=0;j<n;j++)
		{
			if(edges[minIndex][j]!=0 && !visited[j])
			{
				int dist=distance[minIndex]+edges[minIndex][j];
				if(distance[j]>dist)
				distance[j]=dist;
			}
		
		}
	
	}
	
	for(int i=0;i<n; i++)
	{
		cout<<i<<" "<<distance[i]<<endl;
	}

}

int main()
{
	int n;
	cin>>n;
	int **a=new int*[n];
	for(int i=0;i<n;i++)
	{
		a[i]=new int [n];
		for(int j=0;j<n;j++)
		cin>>a[i][j];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
		 cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	Dijkstras(a,n,0);
	return 0;
}
