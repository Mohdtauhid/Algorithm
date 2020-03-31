#include<iostream>
using namespace std;
class fibonacci
{
	public:
		void itrativeFib(int n)
		{
			long int x=0,y=1,z;
			for(int i=1;i<=n;i++)
			{
				z=x+y;
				cout<<x<<" ";
				y=z;
				x=z-x;
			}
		}
		int recursiveFib(int n)
		{
			if(n==0)
			return 0;
			else if(n==1)
			return 1;
			else
			return (recursiveFib(n-1)+recursiveFib(n-2));
		}
};
int main()
{
	fibonacci obj;
	int n;
	cout<<"\nEnter the no ";
	cin>>n;
	obj.itrativeFib(n);
	cout<<"\n\n";
	for(int i=0;i<n;i++)
	cout<<obj.recursiveFib(i)<<" ";
	return 0;
}
