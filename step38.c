#include <stdio.h>

typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} Node;

void preorder(Node *node) {
    if (node == NULL) {
        return;
    }
    printf("%c ", node->data);
    preorder(node->left);
    preorder(node->right);

}

void inorder(Node *node) {
    if (node == NULL) {
        return;
    }
    inorder(node->left);
    printf("%c ", node->data);
    inorder(node->right);
}

void postorder(Node *node) {
    if (node == NULL) {
        return;
    }
    postorder(node->left);
    postorder(node->right);
    printf("%c ", node->data);
}

int countNodes(Node *node) {
    if (node == NULL) {
        return 0;
    }

    int leftcount = countNodes(node->left);
    int rightcount = countNodes(node->right);

    return 1 + leftcount + rightcount;
}

int main(void) {
    Node d = {'D', NULL, NULL};
    Node e = {'E', NULL, NULL};
    Node f = {'F', NULL, NULL};
    Node g = {'G', NULL, NULL};


    Node b = {'B', &d, &e};
    Node c = {'C', &f, &g};
    Node a = {'A', &b, &c};

    Node *root = &a;

    printf("전위 순회 : ");
    preorder(root);
    printf("\n");

    printf("중위 순회 : ");
    inorder(root);
    printf("\n");

    printf("후위 순회 : ");
    postorder(root);
    printf("\n");

    printf("전체 노드 수 : %d\n", countNodes(root));
    return 0;
}