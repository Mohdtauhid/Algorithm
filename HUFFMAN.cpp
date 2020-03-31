//program to encode the substring into binary code and also decode the encoded substring
//using Huffman tree
#include<iostream>
#include<cstring>
#include<cmath>
#include<conio.h>
using namespace std;
//node class
class Node{
	public:
		char symbol;
		int frequency;
		Node *left,*right;   //for left and right child pointer
		Node(){
			symbol='\0';  //initializing with null
		}
};
//min heap tree implementation for priority queue
class MinHeapTree{
	public:
		Node **a;    //array of pointer to store all nodes
		int length;  //total length of the array
		int n;		//no. of elements present in tree
		//initializing heap tree using constructor
		MinHeapTree(int n){
			a=new Node*[n];
			length=n;
			this->n=-1;    //initially no element in array
		}
		
		//remove method : delete root node which has min frequency
		Node * remove(){
			if(n==-1){
				cout<<"\nHeap is empty";
				return NULL;
			}
			Node *x=a[0];   //taking root node in x
			a[0]=a[n];		//puting last node at root node
			n--;			//reducing size of tree
			adjust(0);		//now adjust the tree
			return x;
		}
		
		//insert method : to insert new node in the min heap tree by maintaining its property
		void insert(Node *x){
			if(n==length-1){
				cout<<"\ntree is full\n";
				return;
			}
			n++;      
			int i=n;			//taking i=n as inserting at last position
			
			//adjusting the position for new node to insert
			while(i>0 and a[(i-1)/2]->frequency > x->frequency){		//checking if parent node freq is  > new node freq and index is >0
				a[i]=a[(i-1)/2];			//if parent node freq is greater then put it at last position
				i=(i-1)/2;					//set index to newnode parent index
			}
			a[i]=x;							//fix new node at this new found index
		}
		
		//returns root node
		Node * getMin(){
			return a[0];
		}
		
		//adjust method to adjust the heap tree according to its property:
		//such that every node has freq <= freq of its both children
		void adjust(int i){
			Node *x=a[i];
			int j=2*i+1;
			while(j<=n){
				if(j<n and a[j]->frequency >a[j+1]->frequency)
					j++;
					if(x->frequency<=a[j]->frequency)
						break;
					a[(j-1)/2]=a[j];
					j=2*j+1;	
			}
			a[(j-1)/2]=x;
		}	
		void display(){
			for(int i=0; i<=n; i++){
				cout<<"(Left:"<<a[i]->left<<", symbol:"<<a[i]->symbol<<", freqency:"<<a[i]->frequency<<",right:"<<a[i]->right<<")\t";
			}
		}
};

//inorder tracing of huffman tree for getting bin code for each character
//if left child :0
//if right child :1
//codedtokens to store bincodes
//codedsymbols to store corresponding symbols 

void inorder(Node *r,char bincode[],int i,string *codedtokens,char *codedsymbols){
	static int k=0;
	//left child
	if(r->left!=NULL){
		bincode[i]='0';
		i++;
		inorder(r->left,bincode,i,codedtokens,codedsymbols);
		i--;
	}
	//storing bin code if r->symbols contains a symbol
	if(r->symbol!='\0'){
		codedtokens[k]="";
		for(int j=0; j<i; j++){
			codedtokens[k]+=bincode[j];  //storing bincode
			codedsymbols[k]=r->symbol;	 //storing corresponding symbols 
		}	
		k++;
	}
	//right child
	if(r->right!=NULL){
		bincode[i]='1';
		i++;
		inorder(r->right,bincode,i,codedtokens,codedsymbols);
		i--;
	}
}

//Huffman  : to generate huffman tree
Node * Huffman(char *symbol,int *freq,int n){
	MinHeapTree PQ(n);  //priority queue  (root contain node with min freq)
	//inserting all nodes in Priority queue with symbol and freq
	for (int i=0; i<n; i++){
		Node *nd=new Node;
		nd->symbol=symbol[i];
		nd->frequency=freq[i];
		nd->left=nd->right=NULL;
		PQ.insert(nd);	
	}
	
	//merging 2 nodes with min freq each time 
	for(int i=1; i<=n-1; i++){
		Node *p=PQ.remove();
		Node *q=PQ.remove();
		Node *r=new Node;
		r->left=p;
		r->right=q;
		r->frequency=p->frequency+q->frequency;
		PQ.insert(r);
	}
	return PQ.remove();   //root node of  huffman tree
}

int main(){
	int n=5;
	char Symbol[]={'a','b','c','d','e'};
	int freq[]={25,55,35,45,15};
	
	
	//calling huffman method to generate huffman tree
	cout<<"\nBinary equivalent code for the characters are : (using huffman tree):\n";
	Node *root=Huffman(Symbol,freq,n);
	
	//no bits required to represent n characters in binary codes
	int bitsrequired=log2(n)+1; 
	  
	char bincode[bitsrequired];   
	string *codedtokens=new string[n];   //to store bincode of each corresponding character/symbols found in inorder function
	char *codedsymbols=new char[n];		 //to store each character found in inorder function
	
	//calling inorder function to get bincode of each symbol in huffman tree
	inorder(root,bincode,0,codedtokens,codedsymbols); 
	
	//PRINTING    SYMBOLS : BINARY CODE
	for(int i=0; i<n ; i++){
		cout<<codedsymbols[i]<<":"<<codedtokens[i]<<endl;
	}
	
	//ENCODING
	cout<<"\nEnter a string for its encoding : \n";
	string substring;
	string encodedsubstring="";
	cin>>substring;
	
	//encoding of substring containing characters in symbols
	cout<<"\nEncoded string : \n";
	for(int i=0; i<substring.length(); i++){
		for(int j=0; j<n; j++){
			if(substring[i]==codedsymbols[j]){
				encodedsubstring+=codedtokens[j];
				break;
			}
		}
	}
	cout<<encodedsubstring<<endl;
	
	//DECODING
	cout<<"\nEnter a encoded substring to decode it : \n";
	cin>>encodedsubstring;
	string decodedsubstring="";
	int i=0,j=0;
	bool flag;
	while(i<encodedsubstring.length()){
		flag=false;
		for(int k=0; k<n; k++){
			if(codedtokens[k]==encodedsubstring.substr(i,j-i+1)){
				decodedsubstring+=codedsymbols[k];
				flag=true;
				break;
			}
		}
		if(flag){
			i=j+1;
		}
		j++;
	}
	cout<<decodedsubstring<<endl;
	
	getch();
}


