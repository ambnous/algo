#include<iostream>

using namespace std;
 
int main() {
	int cost[10][10], i, j, queue[10], front, rare, visit[10], visited[10];	
	cout << "Enter number of vertices : ";
	int numVertex;
	cin >> numVertex;
	cout << "\nEnter number of edges : ";
	int numEdges;
	cin >> numEdges;
	cout << "\nEnter the edges \n";
	for (int k = 1; k <= numEdges; k++) {
		cin >> i >> j;
		cost[i][j] = 1;
	}
	cout << "Enter initial vertex : ";
	int vertex;
	cin >> vertex;
	cout << "Visitied vertices\n";
	cout << vertex << " ";
	visited[vertex] = 1;
	int k = 1;
	while (k < numVertex) {
		for (j = 1; j <= numVertex; j++)
			if (cost[vertex][j] != 0 && visited[j] != 1 && visit[j] != 1) {
				visit[j] = 1;
				queue[rare++] = j;
			}
		vertex = queue[front++];
		cout << vertex << " ";
		k++;
		visit[vertex] = 0; visited[vertex] = 1;
	}
	return 0;
}
