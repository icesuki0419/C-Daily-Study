#include <stdio.h>

int N, M;
int map[55][55];     
int visited[55][55];   

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void dfs(int r, int c) {
    visited[r][c] = 1; 

    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr >= 0 && nr < N && nc >= 0 && nc < M) {

            if (map[nr][nc] == 1 && !visited[nr][nc]) {
                dfs(nr, nc);
            }
        }
    }
}

int main() {

    scanf("%d %d", &N, &M);
    

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    
    int island_count = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {

            if (map[i][j] == 1 && !visited[i][j]) {
                dfs(i, j);       
                island_count++; 
            }
        }
    }
    
    printf("%d\n", island_count);
    
    return 0;
}