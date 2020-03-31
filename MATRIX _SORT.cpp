#include<iostream>
#include<conio.h>
using namespace std;
int Matrix (int A[4][4],int S)
{ int index=0;
if(S<A[0][0]   || S>A[0][3])
{
	cout<<"ELEMENT NOT PRESENT IN MATRIX";
	return 0;
}
int i=0,j=3;  
    while (i < 4 && j >= 0)
	 { 
        if (A[i][j] == S)
		 { 
            cout << "\nFound at "  << i << ", " << j; 
            return 1; 
        } 
        if (A[i][j] > S) 
            j--; 
        else  
            i++; 
    
	} 
  cout<<"\n ELEMENT NOT FOUND";
  return -1;
} 

int main()
{
int S;
int DATA[4][4]={ 
                 {10,20,30,40},
                 {15,25,35,45},
				 {27,29,37,48},
				 {32,33,39,50}
                 };
cout<<"\nENTER NUMBER YOU WANT TO SEARCH";
cin>>S;
Matrix(DATA,S);
}
