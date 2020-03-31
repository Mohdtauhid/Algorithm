#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
void coded (char A[],int n)
{ string result;
for(int i=1;i<=n;i++)
{ 	
if(i%2==0)
{  
if((int)A[i]==65 || (int)A[i]==97 )
{  
cout<<char(A[i] +25);	
}
else
{
result[i]=int(A[i])-1; 

cout<< result[i];
}
}
else
{
result[i]=int(A[i])+1;
cout<< result[i];		
}
}	
}

void decoded (char B[],int n)
{ 
string result;
for(int i=1;i<=n;i++)
{ 	
if(i%2==0)
{  
if((int)B[i]==122|| (int)B[i]==90 )
{  
cout<<char(B[i]-25);	
}
else
{
result[i]=int(B[i])+1; 
cout<< result[i];
}
}
else
{
result[i]=int(B[i])-1;
cout<< result[i];		
}
}	
}
int main()
{ int n;
cout<<" ENTER A SIZE OF STRING " ;
cin>>n;
char arr[n],arr1[n];
cout<<" ENTER A STRING " ;
for(int i=1;i<=n;i++)
{
cin>>arr[i];
}
coded(arr,n);
cout<<"\n\nENTER A CODED VALUE";
for(int i=1;i<=n;i++)
{
cin>>arr1[i];
}
decoded(arr1,n);
	
	
	
	
	
	
}
