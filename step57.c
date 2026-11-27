#include <stdio.h>
#define CAPACITY 100

int heap[CAPACITY];
int size = 0;

void insert(int value) {
    int index = size;
    heap[index] = value;
    size++;

    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[index] > heap[parent]) {
            int temp = heap[index];
            heap[index] = heap[parent];
            heap[parent] = temp;

            index = parent;
        } else {
            break;
        }
    }

}


void main(void) {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        insert(value);
    }

    for (int i = 0; i < size; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", heap[i]);
    }
    printf("\n%d\n", heap[0]);
    return 0;
}