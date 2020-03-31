#include<iostream>
#include <cmath>
#include <time.h>
#include<bits/stdc++.h> 
using namespace std;
int MUL(int a[],int x)
{int n=15; //size of array
int m=10; //no of digit in array store
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
for(int i=m; i>=1 ;i--)
cout<<a[n-i];
}
int main()
{   
int arr[15]={0,0,0,0,0,8,2,3,4,5,6,7,8,9,7};
clock_t time_req; 
time_req = clock(); 
int M= MUL(arr,199);	
time_req = clock()- time_req; 
cout << "\n\nProcessor time taken for array  multiplication: "
<< (float)time_req/CLOCKS_PER_SEC << " seconds" << endl; 


}	

