#include<iostream>
#include<conio.h>
#include<cmath>
#include<string.h>
int count=0;
using namespace std;
bool promising(int i,int col[])
{
	for(int j=1;j<=i-1;++j)
	{
	if((col[i]==col[j])||(abs(col[i]-col[j]))==abs(i-j))
	return false;
	}
	return true;
}
int N_QUEEN(int col[],int i,int n) 
{
	if(promising(i,col))
	{ 
		if(i==n)
		{
	cout<<"\n\nSolution  " <<++count<<"\n------------";
            for (int i = 1; i <= n; i++)             
            {        cout<<endl;
                for (int j = 0; j <= n - 1; j++) 
                {                    
                    if (j == col[i])
					 { 
			  cout<<"\tQ"; 
					  }
				    else 
					{ 
					cout<<"\t--";
					}
                }
            }
            return 0;
        }
	else
	{
		for(int j=0;j<n;j++)
		{
			col[i+1]=j;
			N_QUEEN(col ,i+1,n);
		}
	}
	}	
}

int main()
{
int col[4]={1,2,3,4};
int n=4;
N_QUEEN(col,0,n);
return 0;
	
}
