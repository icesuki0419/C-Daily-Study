#include <stdio.h>

int N, M;
int map[105][105];
int dist[105][105]; 

int queue_r[10005];
int queue_c[10005];
int front = 0, rear = 0;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int main() {
   
    scanf("%d %d", &N, &M);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
            dist[i][j] = 0; 
        }
    }

    queue_r[rear] = 0;
    queue_c[rear] = 0;
    rear++;
    dist[0][0] = 1;

    while (front < rear) {

        int r = queue_r[front];
        int c = queue_c[front];
        front++;

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < N && nc >= 0 && nc < M) {

                if (map[nr][nc] == 0 && dist[nr][nc] == 0) {
                    dist[nr][nc] = dist[r][c] + 1; 
                    queue_r[rear] = nr;           
                    queue_c[rear] = nc;
                    rear++;
                }
            }
        }
    }

    if (dist[N-1][M-1] == 0) {
        printf("-1\n");
    } else {

        printf("%d\n", dist[N-1][M-1]);
    }
    
    return 0;
}