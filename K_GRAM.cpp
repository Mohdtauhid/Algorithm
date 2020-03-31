#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
void  GET_K_GRAM(string *A,int n,int k) 
{
	for(int i=0;i<n-k+1;i++)
{
	for(int j=i;j<=i+k-1;j++)
	{
		cout<<A[j]<<" ";
}
	cout<<"     ";
	
	}	
cout<<endl<<endl;		
 }  
 int main()
{ int n; 
 cout<<" ENTER NUMBER OF WORLD" ;
cin>>n; 
 string *B=new string[n] ;
 for(int i=0;i<n;i++)
  cin>>B[i];


GET_K_GRAM(B,n,1);

GET_K_GRAM(B,n,2);

GET_K_GRAM(B,n,3);
getch();	

}
