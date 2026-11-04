#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10

struct Node {
    int key;
    struct Node* next;
};

struct Node* table[TABLE_SIZE];

void initTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = NULL;
    }
}

void insert(int key) {
    int index = hash(key);
    struct Node* newNode = malloc(sizeof(struct Node));

    newNode -> key = key;
    newNode -> next = table[index];
    table[index] = newNode;

}

struct Node* search(int key) {
    int index = hash(key);
    struct Node* current = table[index];

    while (current != NULL) {
        if (current->key == key){
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void deletekey (int key) {
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





