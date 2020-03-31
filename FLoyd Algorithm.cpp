#include<iostream>
#include<conio.h>
#include<iomanip>
using namespace std;
class Floyd
{
public:
	int **P;
	int **D;
	int n;
	int len;
Floyd(int **W,int m)
{
			n=m;
			D=new int*[n];
			for(int i=0; i<n; i++){
				D[i]=new int[n];
			}
			P=new int*[n];
			for(int i=0; i<n; i++){
				P[i]=new int[n];
			}
			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++){
					P[i][j]=0;
				}
			}
			
			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++){
					D[i][j]=W[i][j];
				}
			}
			len=1;
			
		}	
		void calFloyd(){
			for(int k=0; k<n; k++){
				for(int i=0; i<n; i++){
					for(int j=0; j<n; j++){
						if(D[i][j]>(D[i][k]+D[k][j])){
							D[i][j]=D[i][k]+D[k][j];
							P[i][j]=k+1;
						}
					}
				}
			}
		}
		void Path(int q,int r){
			if(P[q][r]!=0){
				Path(q,P[q][r]-1);
				cout<<"V"<<P[q][r]<<"->";
				len++;
				Path(P[q][r]-1,r);
			}
		}
		void getPath(int i,int j){
			cout<<"V"<<i+1<<"->";
			Path(i,j);
			cout<<"V"<<j+1;
		}
		void show(){
			cout<<"\nvertices\tShortest Path\t\tPath\t\t\tPath length\n";
			cout<<"\n-----------------------------------------------------------------------------------\n";
			for(int i=0; i<n ; i++){
				for(int j=0; j<n ;j++){
					len=1;
					if(i!=j){
						cout<<"\nv"<<i+1<<" - v"<<j+1<<"\t\t"<<D[i][j]<<"\t\t";
						getPath(i,j);
						cout<<"\t\t\t"<<len;
					}	
				}
				cout<<endl; 
			}
		}
		void displayP(){
			cout<<endl;
			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++){
					cout<<P[i][j]<<"\t";
				}
				cout<<endl;
			}
		}
	};
int main(){
	int n;
	cout<<"Enter number of vertices : ";
	cin>>n;
	int **W=new int*[n];
	for(int i=0; i<n ; i++){
		W[i]=new int[n];
	}
	cout<<"\nenter values of weighted matrix(enter 10000 for infinity) : \n";
	for(int i=0; i<n ; i++){
		for(int j=0; j<n ;j++){
			if(i==j){
				W[i][j]=0;
			}else{
				cout<<"\nweight between v"<<i+1<<" and v"<<j+1<<":";
				cin>>W[i][j];
			}
			
		}
	}
	cout<<"\nWeighted matrix is : \n";
	for(int i=0; i<n ; i++){
		for(int j=0; j<n; j++){
				cout<<W[i][j]<<"\t";	
		}
		cout<<endl;
	}
	Floyd F(W,n);
	F.calFloyd();
	F.show();
	getch();
}


