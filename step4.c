#include <stdio.h> //printf, scanf
#include <stdlib.h> //malloc 사용

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertFront(struct Node* head, int data) {
    struct Node* newNode;
    newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    return head;
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}


int main() {
    struct Node* head = NULL;
    head = insertFront(head, 30);
    head = insertFront(head, 40);
    head = insertFront(head, 50);
    printList(head);

}

struct Node* search(struct Node* head, int data) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

struct Node* delete(struct Node* head, int data) {
    struct Node* current = head;
    struct Node* prev = NULL;

    while(current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) { // 못찾았을때
        return head;
    }

    if(prev == NULL) {
        head = current->next;
    }

    if (current != NULL) { //찾았을때
        prev->next = current->next;
        return head; 
    }
  
    else {
        prev->next = current->next;
    }

    free(current);

    return head;
}
