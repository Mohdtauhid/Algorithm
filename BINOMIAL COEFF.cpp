#include<iostream>
#include<ctime>
using namespace std;

//divide and conquer approach
int min(int i,int j)
{
	if(i<j)
		return i;
	else
		return j;
}
unsigned long bin0(int n,int k)
{
	if(k==0||k==n)
	{
		return 1;
	}
	else
	{
		return bin0(n-1,k-1)+ (long)bin0(n-1,k);
	}
}
//dynamic programming by storing coeff. into memory of 2d array
unsigned long long bin2(int n,int k)
{
	unsigned long long b[n+1][k+1];
	int i,j;
	for(i=0;i<n+1;i++)
	{
		for(j=0;j<=min(i,k);j++)
		{
			if(j==0||j==i)
				b[i][j]=1;
			else
				b[i][j]=b[i-1][j-1]+b[i-1][j];
		}
	}
	return b[n][k];
}
//dynamic programming by storing coeff. into memory of 1d array

unsigned long long bin1(int n,int k)
{
	unsigned long long b[k+1];
	int i,j;
	for(i=0;i<n+1;i++)
	{
		for(j=min(i,k);j>=0;j--)
		{
			if(j==0||j==i)
				b[j]=1;
			else
				b[j]=b[j]+b[j-1];
		}
	}
	return b[k];
}
int main()
{
	int n=100,k=5;   
	double T1,T2;
	
		T1=clock();
	    cout<<"\nUsing Divide and conquer :: "<<bin0(n,k);
	    T2=clock();
	    cout << "\nUsing Divide and conquer took : "<<(T2-T1)/(CLOCKS_PER_SEC)*1000<<endl; //milliseconds 
   
	   T1=clock(); 
	cout<<"\nUsing Dynamic Programming (2-D Array)  :: "<<bin2(n,k);
	T2=clock();
	cout << "\nUsing Dynamic Programming (2-D Array) took : "<<(T2-T1)/(CLOCKS_PER_SEC)*1000<<endl; // milliseconds 
	   
	   T1=clock(); 
	cout<<"\nUsing Dynamic Programming (1-D Array) :: "<<bin1(n,k);
	T2=clock();
	cout << "\nUsing Dynamic Programming (1-D Array)  took : "<<(T2-T1)/(CLOCKS_PER_SEC)*1000<<endl; //milliseconds 
	   
	return 0;
}
