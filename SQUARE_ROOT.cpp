#include<iostream>
#include<conio.h>
#include<cmath>
#include<math.h>
using namespace std;
double Sqrt(int n)
{
    double g1=n/2.0,g2;	
	while (true)
	{
		g2=(g1+n/g1)/2.0;
	if(abs(g1-g2)<0.0000001)
	{
		break;
	}
	g1=g2;
}
	return g2;
}  
int main() 
{ 
for (int i=2;i<=20;i++)
{
	cout<<i<<"         "<<Sqrt(i)<<"          "<<sqrt(i)<<endl;
}
return 0;
getch();

} 
