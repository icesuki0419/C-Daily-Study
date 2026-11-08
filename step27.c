#include <stdio.h>

#define MAX_K 20

int queue[MAX_K + 2];
int front = 0;
int rear = 0;

int isEmpty(void) {
    return front == rear;
}

int isFull(int K) {
    return (rear + 1) % (K + 1) == front;
}

void enqueue(int value, int K) {
    if (isFull(K)) {
        front = (front + 1) % (K + 1);
    }
    
    rear = (rear + 1) % (K + 1);
    queue[rear] = value;
}

int main(void) {
    int K, N;
    if (scanf("%d %d", &K, &N) != 2) {
        return 0;
    }

    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        enqueue(x, K);
    }

    if (!isEmpty()) {
        int i = (front + 1) % (K + 1);
        while (1) {
            printf("%d", queue[i]);

            if (i == rear) {
                break;
            }

            printf(" ");
            i = (i + 1) % (K + 1);
        }
        printf("\n");
    }

    return 0;
}
