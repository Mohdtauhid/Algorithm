//dijkstra's algorithm for single source shortest path
#include<iostream>
#include<conio.h>
using namespace std;
int * Dijkstra(int **W,int n){
	int *touch=new int[n-1];
	int *length=new int[n-1];
	int *slength=new int[n-1];
	for(int i=0; i<n-1; i++){
		touch[i]=1;
		length[i]=W[0][i+1];
		slength[i]=INT_MAX;
	}
	int vnear;
	for(int k=1; k<=n-1; k++){
		int min=INT_MAX;
		for(int i=0; i<n-1; i++){
			if(length[i]>0 and length[i]<min){
				min=length[i];
				vnear=i;
			}
		}
		for(int i=0; i<n-1; i++){
			if(min+W[vnear+1][i+1]<length[i]){
				length[i]=min+W[vnear+1][i+1];
				touch[i]=vnear+2;
			}
		}
		slength[vnear]=min;
		length[vnear]=-1;
	}
	return touch;
}
void getPath(int *touch,int i){
	if(touch[i]!=1){
		getPath(touch,touch[i]-2);
		cout<<"v"<<touch[i]<<"->";
	}
}
void PrintShortestPath(int *touch,int i){
	cout<<"v1->";
	getPath(touch,i);
	cout<<"v"<<i+2;
}


int main(){
	cout<<"\nEnter number of vertices in graph : ";
	int n;
	cin>>n;
	int **W=new int*[n];
	for(int i=0; i<n ;i++){
		W[i]=new int[n];
	}
	
//	int W[5][5]={{0,1,3,1000,1000},{1,0,3,6,1000},{3,3,0,4,2},{1000,6,4,0,5},{1000,1000,2,5,0}};
	cout<<"\nEnter weight between egdes if not(then give 1000):\n";
	for(int i=0; i<n ; i++){
		for(int j=0; j<n ;j++){
			if(i!=j){
				cout<<"\n edge (v"<<i+1<<",v"<<j+1<<"):";
				cin>>W[i][j];
			}else{
				W[i][j]=0;
			}
		}
	}
	cout<<"\nweighted matrix:\n";
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<W[i][j]<<"\t";
		}
		cout<<endl;
	}
	int *touch=Dijkstra(W,n);
	cout<<"\nShortest path from v1 to all other vertices are : \n";
	for(int i=0; i<n-1; i++){
		cout<<"\nfrom v1 to v"<<i+2<<":";
		PrintShortestPath(touch,i);
	}
	getch();
}
