#include<iostream> 
#include<stack>

using namespace std; 
class Graph 
{ 
	// Number of vertex 
	int v; 

	// Adjacency matrix 
	int adj[10][10]={ 
	            {0,1,0,1,0,0,0,0,0,0},
	            {1,0,1,0,1,0,1,1,0,0},
			    {0,1,0,1,0,0,0,0,1,1},
			    {1,0,1,0,0,0,0,0,0,0},
			    {0,1,0,0,0,1,1,1,0,0},
			    {0,0,0,0,1,0,0,0,0,0},
			    {0,1,0,0,1,0,0,1,0,0},
			    {0,1,0,0,1,0,1,0,0,0},
			    {0,0,1,0,0,0,0,0,0,0},
			    {0,0,1,0,0,0,0,0,0,0}
			   }; 
			   
public: 
Graph(int v) 
{ 
this->v = v;    
}
void DFS(int start); 
}; 

void Graph::DFS(int start) 
{ 

	bool visited[v];
	for(int i = 0; i < v; i++)           //all false -----  Not Visited[V] 
		visited[i] = false;  
		
		
    stack<int> Stack; 
	Stack.push(start); 

	// Set source as visited 
	visited[start] = true; 


	while (!Stack.empty()) { 
		

		// Print the current node 
		int D=Stack.top();                     // return top value
		cout << D+1 << " ";       	             //[0 vertix, 1 vertix, 2 vertix, 3 vertix ---    9 vertix]
		Stack.pop();                            // pop/delete From top -----but  return nothing

		// For every adjacent vertex to the current vertex 
		for (int i = 0; i < v; i++) 
		{ 
			if (adj[D][i] == 1 && (!visited[i]))               // Here  1 mean tere is a edge
			{ 
				Stack.push(i);           // Push the adjacent node to the queue  

				visited[i] = true;   				// Set 
			} 
		} 
	} 
} 
int main() 
{ 
 	Graph G(10);
	G.DFS(0);                  //Starting from index 0   --------[0 vertix,1 vertix,2 vertix,3 vertix ---9 vertix]
} 



 
