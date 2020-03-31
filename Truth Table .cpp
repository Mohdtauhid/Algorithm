#include<iostream>
#include<conio.h>
#include<string>
#include<math.h>
using namespace std;
void boolean_value(int n)
{  	int j ,k;
	char * a =new char[n];
	for(int i=0;i<=n-1;i++)
	{
		a[i]='F';
	}
	for(int i=0;i<=pow(2,n)-1;i++)
	{    j=n-1;      k=i;
while(k!=0)
{
if(k%2==1)
a[j]='T';
else
a[j]='F';

j=j-1;
k=k/2;
}
for(int i=0;i<=n-1;i++)
cout<<a[i]<<" ";	
cout<<endl;
}

}
int main()
{
boolean_value(3);
	
}






