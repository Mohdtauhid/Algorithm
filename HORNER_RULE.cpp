#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
  
int horner(int poly[], int n, int x) 
{ 
    int result = poly[n]*x; 
	
    for (int i=n-1; i>0; i--)
	{
	    result =(result + poly[i])*x; 
    }
        result =result + poly[0]; 
  
    return result; 
} 
  

int main() 
{ 
    int poly[] = {2, -6, 2, -1}; 
    int x = 2; // value of x in function f(x)
    int n = sizeof(poly)/sizeof(poly[0]);   //degree of polynomial 
    cout << "Value of polynomial is " << horner(poly, 3, x); 
    return 0;
}
