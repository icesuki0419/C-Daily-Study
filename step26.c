#include <stdio.h>

#define MAX_N 20

int queue[MAX_N + 2];
int front = 0;
int rear = 0;
int remaining[MAX_N + 1]; 

int isEmpty(void) {
    return front == rear;
}

int isFull(int size) {
    return (rear + 1) % (size + 1) == front;
}

void enqueue(int value, int size) {
    if (isFull(size)) {
        return;
    }
    rear = (rear + 1) % (size + 1);
    queue[rear] = value;
}

int dequeue(int size) {
    if (isEmpty()) {
        return -1;
    }
    front = (front + 1) % (size + 1);
    return queue[front];
}

int main(void) {
    int N;
    if (scanf("%d", &N) != 1) {
        return 0;
    }

    for (int i = 1; i <= N; i++) {
        scanf("%d", &remaining[i]);
        enqueue(i, N);
    }

    while (!isEmpty()) {
        int job = dequeue(N);

        remaining[job]--;

        if (remaining[job] > 0) {
            printf("%d %d\n", job, remaining[job]);
            enqueue(job, N); 
        } else {
            printf("%d DONE\n", job);
        }
    }

    return 0;
}
