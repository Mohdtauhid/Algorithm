#include<iostream>
#include<conio.h>
#include<string>
using namespace std;

void permutation(string a ,int x,int n)
{ 
if(x==n)
{
cout<<a<<endl;
}	
else
{
for(int i=x;i<=n;i++)
{char q;
q=a[i];
a[i]=a[x];
a[x]=q;
permutation(a,x+1,n);
q=a[i];
a[i]=a[x];
a[x]=q;}		
}
}
int main()
{
string A;
cout<<" Enter a string ";
cin>> A;
int N=A.size();
permutation(A,0,N-1);
getch();	
	}
