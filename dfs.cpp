#include <iostream>
using namespace std;
 
typedef struct node {
    struct node *next;
    int vertex;
}node;
 
node *G[20];   
//heads of linked list
int visited[20]; int n;
void read_graph(); 
//create adjacency list
void insert(int,int);  
//insert an edge (vi,vj) in te adjacency list
void DFS(int);
 
int main() {
    int i, startVertex;
    read_graph();
    //initialised visited to 0
   
	for(i=0;i<n;i++)
        visited[i]=0;
	cout << "\nEnter the starting vertex : ";
	cin >> startVertex; 
    DFS(startVertex);
    return 0;
}
 
void DFS(int i) {
    node *p;
	cout << i;
    p = G[i];
    visited[i] = 1;
    while (p != NULL) {
       i = p->vertex;
       
	   if (!visited[i])
            DFS(i);
        p = p->next;
    }
}
 
void read_graph() {
    int i, vi, vj, no_of_edges;
    cout << "Enter number of vertices : ";
	cin >> n;
    //initialise G[] with a null
	for (i = 0; i < n; i++) {
        G[i] = NULL;
        //read edges and insert them in G[]
		cout << "Enter number of edges : ";
       	cin >> no_of_edges;
       	for (i = 0; i < no_of_edges; i++) {
        	cout << "Enter an edge(u,v) : ";
			cin >> vi >> vj;
			insert(vi,vj);
        }
    }
}
 
void insert(int vi,int vj) {
    node *p,*q;
    
	//acquire memory for the new node
	q = new node;
    q->vertex = vj;
    q->next = NULL;
 
    //insert the node in the linked list number vi
    if (G[vi] == NULL)
        G[vi] = q;
    else {
        //go to end of the linked list
        p = G[vi];
       
		while (p->next != NULL)
        	p = p->next;
        p->next = q;
    }
}
