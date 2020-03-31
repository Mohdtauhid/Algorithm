#include<iostream> 
#include <chrono>
#include<math.h>
using namespace std; 
using namespace std::chrono;
void factorial(int n,int size) 
{ 
	int f[size],carry=0; 
	f[0] = 1; 
	int fsize = 1; 
	auto start = high_resolution_clock::now();
	for (int x=2; x<=n; x++) 
	{
		for (int i=0; i<fsize; i++) 
		{ 
			int prod = f[i] * x + carry; 
			f[i] = prod % 10; 
			carry = prod/10;
		}
		while (carry) 
		{ 
			f[fsize] = carry%10; 
			carry = carry/10; 
			fsize++; 
		}
	}
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Factorial of given number is  :: "; 
	for (int i=fsize-1; i>=0; i--) 
		cout << f[i]; 
	cout << "\nTime taken by Factorial is :: "<< duration.count() << " microseconds" << endl;
}  
int main() 
{ 
	int n,d=0;
	cout<<"\nEnter number to find Factorial :: ";
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		d=d+floor(log(i));
	}
	factorial(n,d); 
	return 0; 
} 

