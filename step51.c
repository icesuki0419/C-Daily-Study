// 문제 1

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;

Node* createNode(int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;

    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
        
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

Node* search(Node* root, int target) {
    Node* current = root;

    while (current != NULL) {
        if (target == current->data) {
            return current;
        } else if (target < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    return NULL;
}

void inorder(Node *node) {
    if (node == NULL) {
        return;
    }
    inorder(node->left);
    printf("%c ", node->data);
    inorder(node->right);
}


int main(void) {
    Node* root = NULL;

    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        root = insert(root, val);
    }

    int m;
    if (scanf("%d", &m) != 1) {
        return 0;
    }

    for (int i = 0; i < m; i++) {
        int target;
        scanf("%d", &target);
        Node* result = search(root, target);
        if (result != NULL) {
            printf("FOUND\n");
        } else {
            printf("NOT FOUND\n");
        }
    }

    return 0;
}
