#include <stdio.h>
#define CAPACITY 100

int heap[CAPACITY];
int size = 0;

void insert(int value) {
    if (size >= CAPACITY) {
        return;
    }

    int index = size;
    heap[index] = value;
    size++;

    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[index] < heap[parent]) {
            int temp = heap[index];
            heap[index] = heap[parent];
            heap[parent] = temp;

            index = parent;
        } else {
            break;
        }
    }
}

int main(void) {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int priority;
        scanf("%d", &priority);
        insert(priority);
        printf("%d\n", heap[0]);
    }

    return 0;
}