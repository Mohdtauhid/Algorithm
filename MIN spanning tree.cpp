#include<iostream>
#include<conio.h>
#define v 5 
using namespace std;
int Prim_s(int W[v][v],int n)
{     int d[n-1];	int near,min_d;  //minimum distance
   	   int nearest[n-1];

	for(int i=0;i<n-1;i++)
   {
		nearest[i]=0;
    	   d[i]=W[0][i+1];
}	
	
	for(int k=0;k<n-1;k++)
{
int min=INT_MAX;	
	for(int i=0;i<n-1;i++)
	{
	if(d[i]>=0 and d[i]<min)	
	{
	min=d[i];
	near=i;
	}
	}
	 cout<<" < "<<nearest[near]<<" , "<<near+1<<" > \n";
	 min_d=min_d+d[near];
d[near]=-1;
for(int i=near+1;i<n-1;i++)
{
	if(W[near+1][i+1]<d[i])
	{
		d[i]=W[near+1][i+1];
		nearest[i]=near+1;
	}
}
	}
   
	cout<<"\nMinimum distance will be :: "<<min_d;	
}


int main()  
{  
   
    int graph[v][v] =  {
	                    { 0, 1, 3, INT_MAX, INT_MAX },  
                        { 1, 0, 3, 6, INT_MAX },  
                        { 3, 3, 0, 4, 2 },  
                        { INT_MAX, 6, 4, 0, 5 },  
                        { INT_MAX, INT_MAX, 2, 5, 0 } 
						};  
 
    Prim_s(graph,5);  
    
    return 0;  
}  
 
