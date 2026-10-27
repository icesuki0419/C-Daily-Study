#include <stdio.h>

#define V 5

int graph[V][V] = {
    {0, 1, 1, 0, 1},
    {1, 0, 0, 1, 0},
    {1, 0, 0, 1, 1},
    {0, 1, 1, 0, 0},
    {1, 0, 1, 0, 0}
};

void printfGraph(void) {
    printf("  ");
    for (int i = 0; i < V; i++) {
        printf("%d ", i);
    }
    printf("\n");


    for (int i = 0; i < V; i++) {
        printf("%d ", i); 
        for (int j = 0; j < V; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int visited[V] = {0};

int main(void) {
    printf("[인접 행렬]\n");
    printfGraph();

    return 0;
}

void initVisited(void) {
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
    }
}

void dfs(int v) {
    
    
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < V; i++) {
        if(graph[v][i] == 1 && visited[i] == 0) {
            dfs(i);
        } 
    }
}

void bfs(int start) {
    int queue[V];
    int front = 0;
    int rear = 0;


    visited[start]=1;
    queue[rear++] = start;
    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);
        
    }
} 