// Author: Akshay A Baiju
// Problem: Counting Rooms
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1192/
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Problem tag: dfs, connected components
// TC: O(n+m)
// SC: O(n+m)

#include<bits/stdc++.h>
using namespace std;

char building[1007][1007];
bool vis[1007][1007];

void dfs(int x, int y, int n, int m)
{
	vis[x][y]=true;
	int dx[]={-1,0,1,0};
	int dy[]={0,1,0,-1};
	for (int i=0;i<4;i++)				  //traverse the neighbouing cells
	{
		int newx=x+dx[i];
		int newy=y+dy[i];
		if ((newx>=0 && newx<n && newy>=0 && newy<m) && building[newx][newy]=='.' && !vis[newx][newy])	//if valid cell and cell is floor and unvisited
			dfs(newx,newy,n,m);
	}
}

int countConnectedComponents(int n, int m)
{
	//dfs traversal on grid
	int count=0;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		{
			if (building[i][j]=='.' && !vis[i][j])
			{
				dfs(i,j,n,m);
				count++;
			}
		}
	}
	return count;
}

int main()
{
	int n,m;
	cin>>n>>m;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
			cin>>building[i][j];
	}
	//count number of connected components
	int room=countConnectedComponents(n,m);
	cout<<room;
	return 0;
}
