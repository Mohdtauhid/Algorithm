#include<iostream>
#include<math.h>
using namespace std;
void floyd(int **d,int **p,int n)
{
	uint32_t temp;
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				temp=d[i][k]+d[k][j];
				cout<<"\nTemp :: "<<temp;
				if(d[i][j]>temp)
				{
					d[i][j]=temp;
					p[i][j]=k;
				}
			}
		}
	}
	cout<<"\nShortest path of each vertex :: \n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<d[i][j]<<" ";
		}
		cout<<"\n";
	}
}
void path(int **p,int q,int r)
{
	if(p[q][r]!=0)
	{
		path(p,q,p[q][r]);
		cout<<"\n v"<<p[q][r];
		path(p,p[q][r],r);
	}
}
void getpath(int **p,int i,int j)
{
	cout<<" v"<<i<<"-> ";
	path(p,i,j);
	cout<<"v"<<j;
}
int main()
{
	int n,**w,**p;
	cout<<"\nEnter No. of vertices :: ";
	cin>>n;
	w=new int*[n];
	for(int i=0;i<n;i++)
	{
		w[i]=new int[n];
	}
	p=new int*[n];
	for(int i=0;i<n;i++)
	{
		p[i]=new int[n];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			p[i][j]=0;
		}
	}
	cout<<"\nEnter Weighted Matrix :: ";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j)
			{
				w[i][j]=0;
			}
			else
			{
				cout<<" V [ "<<i<<" ] [ "<<j<<" ] :: ";
				cin>>w[i][j];
				if(w[i][j]==0)
				{
					w[i][j]=INT_MAX;
				}
			}
		}
	}
	cout<<"\nWeighted Matrix  :: \n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<w[i][j]<<"  ";
		}
		cout<<"\n";
	}
	
	floyd(w,p,n);
	getpath(p,0,3);
	return 0;
}
