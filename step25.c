#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = 0;
int rear = 0;

int isEmpty(void) {
    return front == rear;
}

int isFull(void) {
    return (rear+1)%SIZE == front;
}

int enqueue(int value) {
    if (isFull()) {
        return 0;
    }

    rear = (rear+1)%SIZE;
    queue[rear] = value;

    return 1;
}

int dequeue(void) {
    if (isEmpty()) {
        return -1;
    }
    front = (front + 1) % SIZE;
    return queue[front];
}

int peek(void) {
    if (isEmpty()) {
        return -1;
    }
    return queue[(front + 1) % SIZE];
}

void printQueue(void) {
    if (isEmpty()) {
        printf("Empty\n");
        return;
    }

    int i = (front + 1) % SIZE;

    while(1) {
        printf("%d", queue[i]);

        if (i == rear) {
            break;
        }

        printf(" ");
        i = (i + 1) % SIZE;
    }

    printf("\n");
}

int main(void) {
    int Q;
    if (scanf("%d", &Q) != 1) {
        return 0;
    }

    for (int q = 0; q < Q; q++) {
        int cmd;
        scanf("%d", &cmd);

        if (cmd == 1) {
            int x;
            scanf("%d", &x);
            if (enqueue(x)) {
                printf("ADDED\n");
            } else {
                printf("Full\n");
            }
        } 
        else if (cmd == 2) {
            if (isEmpty()) {
                printf("Empty\n");
            } else {
                printf("%d\n", dequeue());
            }
        } 
        else if (cmd == 3) {
            printQueue();
        }
    }

    return 0;
}
