//longest common substring problem
#include<iostream>
#include<string.h>
#include<conio.h>
#include<cstring>
using namespace std;
class LongestCommonSub{
	int **C;
	char **B;
	public:
	LongestCommonSub(int m,int n){
		C=new int*[m+1];
		B=new char*[m+1];
		for(int i=0; i<m+1; i++){
			C[i]=new int[n+1];
			B[i]=new char[n+1];
		}
	}
	//main LCS function
	int LCS(char X[],char Y[]){
		int m=strlen(X);
		int n=strlen(Y);
		for(int i=0; i<=m; i++){
			C[i][0]=0;
		}
		for(int j=0; j<=n; j++){
			C[0][j]=0;
		}
		for(int i=1; i<=m; i++){
			for(int j=1; j<=n; j++){
				if(X[i-1]==Y[j-1]){
					C[i][j]=C[i-1][j-1]+1;
					B[i][j]='d';  //d:diagonal
				}else if(C[i-1][j] >= C[i][j-1]){
					C[i][j]=C[i-1][j];
					B[i][j]='u'; //u:up
				}else{
					C[i][j]=C[i][j-1];
					B[i][j]='l';  //l : left 
				}
			}
		}
		return C[m][n];	
	}
	//recursive function
	void PrintLCS1(char X[],int i,int j){
		if(i==0 or j==0){
			return;
		}
		if(B[i][j]=='d'){
			PrintLCS1(X,i-1,j-1);
			cout<<X[i-1]<<" ";
		}else if(B[i][j]=='u'){
			PrintLCS1(X,i-1,j);
		}else{
			PrintLCS1(X,i,j-1);
		}
	}
	//iterative function
	char * PrintLCS2(char X[],int i,int j,int length){
		char *Z=new char[length];
		int k=length-1;
		while(i!=0 and j!=0){
			if(B[i][j]=='d'){
				Z[k]=X[i-1];
				k--;
				i--;
				j--;
			}else if(B[i][j]=='u'){
				i--;
			}else{
				j--;
			}
		}
		return Z;	
	}
	
	//Print lcs without using matrix B just by using matrix C
	//iterative
	char * PrintLCS4(char X[],char Y[],int i,int j,int length){
		char *W=new char[length];
		int k=length-1;
		while(i!=0 and j!=0){
			if(X[i-1] == Y[i-1]){
				W[k]=X[i-1];
				i--;
				j--;
				k--;
			}else if(C[i-1][j] >= C[i][j-1]){
				i--;
			}else{
				j--;
			}
		}
		return W;
	}
	//Print lcs without using matrix B just by using matrix C
	//recursive
	void PrintLCS3(char X[],char Y[],int i,int j){
		if(i==0 or j==0){
			return;
		}
		if(X[i-1]==Y[j-1]){
			PrintLCS3(X,Y,i-1,j-1);
			cout<<X[i-1]<<" ";
		}else if(C[i-1][j] >= C[i][j-1]){
			PrintLCS3(X,Y,i-1,j);
		}else{
			PrintLCS3(X,Y,i,j-1);
		}
	}
	//display sequence function
	void displaySeq(char *X){
		int n=strlen(X);
		cout<<"< ";
		for(int i=0; i<n; i++){
			cout<<X[i]<<", ";
		}
		cout<<"\b\b >\n";
	}
	
};
int main(){
	int m,n;
	char *X,*Y;
	cout<<"\nEnter number of elements in seq X : ";
	cin>>m;
	X=new char[m];
	cout<<"\nEnter elements of seq X : "<<endl;
	for(int i=0; i<m; i++){
		cin>>X[i];
	}
	cout<<"\nEnter number of elements in seq Y :";
	cin>>n;
	Y=new char[n];
	cout<<"\nEnter elements of seq Y :"<<endl;
	for(int i=0; i<n; i++){
		cin>>Y[i];
	}
	LongestCommonSub L(m,n);
	cout<<"\nSequence X: ";
	L.displaySeq(X);
	cout<<"\nSequence Y: ";
	L.displaySeq(Y);
	cout<<"\nLongest Common Subsequence of sequences X and Y is :"<<endl;
	int length=L.LCS(X,Y);
	cout<<"\nLength : "<<length;
	cout<<"\nSubsequence is : < ";
	L.PrintLCS1(X,m,n);
	cout<<" >\n";
	
	cout<<"\nusing iterative function :";
	char *Z=L.PrintLCS2(X,m,n,length);
	L.displaySeq(Z);
	
	cout<<"\nRecursive without using matrix B: < ";
	L.PrintLCS3(X,Y,m,n);
	cout<<" >"<<endl;
	cout<<"\nIterative without using matrix B: ";
	char *W=L.PrintLCS4(X,Y,m,n,length);
	L.displaySeq(W);
	getch();
}




//void displayC(int m,int n){
//		cout<<endl;
//		for(int i=0; i<=m; i++){
//			for(int j=0; j<=n; j++){
//				cout<<C[i][j]<<"\t";
//			}
//			cout<<endl;
//		}
//		cout<<endl;
//	}
//	void displayB(int m,int n){
//		cout<<endl;
//		for(int i=0; i<=m; i++){
//			for(int j=0; j<=n; j++){
//				cout<<B[i][j]<<"\t";
//			}
//			cout<<endl;
//		}
//		cout<<endl;
//	}


