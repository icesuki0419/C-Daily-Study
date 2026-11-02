#include <stdio.h>

int N, M;
int adj[1005][1005];  
int visited[1005];    
int S, T;
int found = 0;        

void dfs(int current) {
    if (found || current == T) {
        found = 1;
        return;
    }
  
    visited[current] = 1;

    for (int i = 1; i <= N; i++) {
        if (adj[current][i] == 1 && !visited[i]) {
            dfs(i);
            if (found) return;
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
  
    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
  
    scanf("%d %d", &S, &T);

    dfs(S);
  
    if (found) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
  
    return 0;
}