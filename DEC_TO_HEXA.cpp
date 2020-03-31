#include<iostream>
#include<conio.h>
#include<cmath>
#include<math.h>
using namespace std;
void Dec_To_Hexa(int n ) 
{    
  //  int size=floor(log2(n));   binary
    int size=floor(log(n)/log(16))+1;   //hexa
    
    char hexaDeciNum[size]; 
      
    int i = 0; 
    while(n!=0) 
    {    
        int temp  = 0; 
        temp = n % 16; 
          
        if(temp < 10) 
        { 
            hexaDeciNum[i] = temp + 48; 
            i++; 
        } 
        else
        { 
            hexaDeciNum[i] = temp + 55; 
            i++; 
        } 
          
        n = n/16; 
    } 
      
    for(int j=i-1; j>=0; j--) 
        cout << hexaDeciNum[j]; 
} 
int main()
{
    int k=0;
    printf("Enter VALUE IN decimal:");
 cin>>k;
    Dec_To_Hexa(k);
    return 0;
}
