#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 5

struct Node {
    int key;
    struct Node* next;
};

struct Node* table[TABLE_SIZE];

int hash(int key) {
    return key % TABLE_SIZE;
}

void initTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = NULL;
    }
}

void insert(int key) {
    int index = hash(key);
    struct Node* newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) {
        return;
    }

    newNode->key = key;
    newNode->next = table[index];
    table[index] = newNode;
}

struct Node* search(int key) {
    int index = hash(key);
    struct Node* current = table[index];

    while (current != NULL) {
        if (current->key == key) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void deletekey(int key) {
    int index = hash(key);
    struct Node* current = table[index];
    struct Node* prev = NULL;

    while (current != NULL && current->key != key) {
        prev = current;
        current = current->next;
    }
    
    if (current == NULL) {
        return;
    }
    else if (prev == NULL) {
        table[index] = current->next;
    }
    else {
        prev->next = current->next;
    }

    free(current);
}

void printTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        struct Node* current = table[i];
        while (current != NULL) {
            printf("%d -> ", current->key);
            current = current->next;
        }
        printf("NULL\n");
    }
}

void freeTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        struct Node* current = table[i];
        while (current != NULL) {
            struct Node* temp = current;
            current = current->next;
            free(temp);
        }
        table[i] = NULL;
    }
    printf("메모리 해제 완료\n");
}

int main() {
    initTable();

    insert(1);
    insert(3);
    insert(2);
    insert(7);
    insert(12);

    printTable();
    printf("\n");

    struct Node* found1 = search(7);
    if (found1 != NULL)
        printf("찾은 값: %d\n", found1->key);
    else
        printf("찾을 수 없음\n");
    printf("\n");

    struct Node* found2 = search(99);
    if (found2 != NULL)
        printf("찾은 값: %d\n", found2->key);
    else
        printf("찾을 수 없음\n");
    printf("\n");

    deletekey(12);
    printTable();
    printf("\n");

    deletekey(7);
    printTable();
    printf("\n");

    deletekey(99);
    printTable();
    printf("\n");

    freeTable();

    return 0;
}


