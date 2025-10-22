#include <stdio.h>
#define SIZE 100

int graph[SIZE][SIZE];
int visited[SIZE];
int queue[SIZE];
int front = 0, rear = 0;

void enqueue(int node) {
    queue[rear++] = node;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

void bfs(int start, int n) {
    enqueue(start);
    visited[start] = 1;
    printf("BFS: ");
    
    while(!isEmpty()) {
        int current = dequeue();
        printf("%d ", current);
        
        for(int i = 0; i < n; i++) {
            if(graph[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int n, start;
    
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    
    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    
    printf("Enter starting node (0 to %d): ", n-1);
    scanf("%d", &start);
    
    bfs(start, n);
    return 0;
}

// This code implements a Breadth-First Search (BFS) algorithm for traversing a graph represented by an adjacency matrix.
// It allows the user to input the number of nodes, the adjacency matrix, and the starting
// node for the BFS traversal, and outputs the order of nodes visited during the traversal.

// Example usage:

// Enter number of nodes: 5
// Enter adjacency matrix (5 x 5):
// 0 1 1 0 0
// 1 0 1 1 0
// 1 1 0 0 1
// 0 1 0 0 1
// 0 0 1 1 0
// Enter starting node (0 to 4): 0
// BFS: 0 1 2 3 4