#include<iostream> 
#include <queue>
#include<vector>
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
void BFS(int start); 
}; 

void Graph::BFS(int start) 
{ 

	vector<bool> visited(v, false);    // all false -----  Not Visited[V]
    queue<int> Queue; 
	Queue.push(start); 

	// Set source as visited 
	visited[start] = true; 


	while (!Queue.empty()) { 
		

		// Print the current node 
		int D=Queue.front();                     // return front value
		cout << D+1 << " ";       	             //[0 vertix, 1 vertix, 2 vertix, 3 vertix ---    9 vertix]
		Queue.pop();                            // pop/delete From Front -----but  return nothing

		// For every adjacent vertex to the current vertex 
		for (int i = 0; i < v; i++) 
		{ 
			if (adj[D][i] == 1 && (!visited[i]))               // Here  1 mean tere is a edge
			{ 
				Queue.push(i);           // Push the adjacent node to the queue  

				visited[i] = true;   				// Set 
			} 
		} 
	} 
} 
int main() 
{ 
 	Graph G(10);
	G.BFS(0);                  //Starting from index 0   --------[0 vertix,1 vertix,2 vertix,3 vertix ---9 vertix]
} 

