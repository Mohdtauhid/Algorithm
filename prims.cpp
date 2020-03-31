#include<iostream>
using namespace std;
void prims(int n,int w[][5])
{
	int s=n-1,mindist=0;
	int nearest[s],dist[s],min,near;
	for(int i=0;i<s;i++)
	{
		nearest[i]=0;
		dist[i]=w[0][i+1];
	}
	for(int j=1;j<=n-1;j++)
	{
		min=INT_MAX;
		for(int i=0;i<s;i++)
		{
			if(dist[i]>0 && dist[i]<min)
			{
				min=dist[i];
				near=i;
			}
		}
		cout<<" < "<<nearest[near]<<" , "<<near+1<<" > \n";
		mindist=mindist+dist[near];
		dist[near]=-1;
		for(int i=near+1;i<s;i++)
		{
			if(w[near+1][i+1]<dist[i])
			{
				dist[i]=w[near+1][i+1];
				nearest[i]=near+1;
			}
		}
	}
	cout<<"\nMinimum distance will be :: "<<mindist;
}
int main()
{
	/*int **w,*/int n;
	/*cout<<"\nEnter no of vertices :: ";
	cin>>n;*/
	int w[][5]={
					{0,1,3,INT_MAX,INT_MAX},
					{1,0,3,6,INT_MAX},
					{3,3,0,4,2},
					{INT_MAX,6,4,0,5},
					{INT_MAX,INT_MAX,2,5,0}
				};
	/*w=new int*[n];
	for(int i=0;i<n;i++)
	{
		w[i]=new int[n];
	}
	
	cout<<"\nEnter a weighted matrix :: ";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j)
				w[i][j]=0;
			else
			{
				cout<<" w [ "<<i<<" ] [ "<<j<<" ]  :: ";
				cin>>w[i][j];
				if(w[i][j]==0)
					w[i][j]=INT_MAX;
			}	
		}
	}*/
	prims(5,w);
	return 0;
	
}
