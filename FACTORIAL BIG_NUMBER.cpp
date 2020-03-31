#include<iostream>
#include <cmath>
#include <time.h>
#include<bits/stdc++.h> 
using namespace std;
int MUL(int a[],int x,int size,int digit)
{ int n=size;  // //size of array
int m=digit; //no of digit in array store
int c=0;
for(int i=1;i<=m; i++)	
{
int y=a[n-i]*x+c;
a[n-i]=y%10;
c=floor(y/10);
}	
while(c!=0)
{	m=m+1;
	a[n-m]=c%10;
	c=floor(c/10);
}
return m;  
}

int main()
{
int N, digit=1;float F=0.0;    
cout<<"ENTER A NUMBER TO CALCULATE FACTORIAL : ";
cin>>N;
for(int j=2;j<=N;j++)   // number of digit present in N factorial
{
F=F+log10(j);	
}
int size=floor(F)+1;
int arr[size]; //size of array
arr[size-1]=1;// number at last index of array
clock_t time_req; 
time_req = clock();    //return clock per cycle

for(int I=2;I<=N;I++)
{
digit=MUL(arr,I,size,digit);	
}


time_req = clock()- time_req;  //return clock per cycle

//print  factorial 
for(int i=digit; i>=1 ;i--)
cout<<arr[size-i];


cout << "\n\nExecution time required for calculating  "<< N <<" factorial: "
<< (float)time_req/CLOCKS_PER_SEC << " seconds" << endl; 
}



