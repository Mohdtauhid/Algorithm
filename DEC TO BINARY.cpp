#include<iostream>
#include<conio.h>
#include<string>
#include<math.h>
using namespace std;
int dec_bin_iterative(int num)
{
    int i=0;  int size=floor(log2(num)); 
	int binaryNum[size]; 
    while (num > 0) 
	{ 
        binaryNum[i] = num % 2; 
        num = num / 2; 
        i++; 
    }   
for(int i=size;i>=0;i--)   
cout<<binaryNum[i];	
}

int dec_bin_recursiv(int num)
{   
	if(num==0)
	return 0;
	else
	return num%2 +10 * dec_bin_recursiv(num/2);
}
int main()
{
 dec_bin_iterative(64);
cout<<endl<<dec_bin_recursiv(64);	
}
