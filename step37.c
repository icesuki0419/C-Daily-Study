#include <stdio.h>

#define INF 999999
#define N 6

int findMinVertex(int dist[], int visited[]) {
    int min = INF;
    int minIndex = -1;

    for (int i = 0; i < N; i++) {
        if(visited[i] == 0 && min > dist[i]) {
            min = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void dijkstra(int graph[N][N], int start) {
    int dist[N];
    int visited[N];

    for (int i = 0; i < N; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[start] = 0; // [수정 1] = 0 추가


    while(1) {
        int u = findMinVertex(dist, visited);
        if (u == -1) {
            break;
        }
        visited[u] = 1;

        for (int v = 0; v < N; v++) {
            if (!visited[v] && graph[u][v] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }

    }

    printf("시작 정점 %c에서 각 정점까지의 최단 이동 시간\n", 'A' + start);
    for (int i = 0; i < N; i++) {
        if (dist[i] == INF) {
            printf("%c : 경로 없음\n", 'A' + i);
        } else {
            printf("%c : %d\n", 'A' + i, dist[i]);
        }
    }
}

int main() {
    int graph[N][N] = {
        {0, 7, 4, 9, INF, INF},
        {7, 0, 4, 2, 6, INF},
        {4, INF, 0, 3, INF, 8},
        {9, 2, 3, 0, 4, INF},
        {INF, 6, INF, 4, 0, 2},
        {INF, INF, 8, INF, 2, 0}
    };

    dijkstra(graph, 0);

    return 0;
}