#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Função para criar um novo nó
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

// Função para percorrer a árvore em pre-ordem
void preOrder(struct Node* node) {
    if (node == NULL) return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

// Função para percorrer a árvore em in-ordem
void inOrder(struct Node* node) {
    if (node == NULL) return;
    inOrder(node->left);
    printf("%d ", node->data);
    inOrder(node->right);
}

// Função para percorrer a árvore em pos-ordem
void postOrder(struct Node* node) {
    if (node == NULL) return;
    postOrder(node->left);
    postOrder(node->right);
    printf("%d ", node->data);
}

// Função para inserir um novo nó na árvore
struct Node* insert(struct Node* node, int data) {
    if (node == NULL) return newNode(data);
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    return node;
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
 
    printf("Pre-order traversal: ");
    preOrder(root);
    printf("\n");
 
    printf("In-order traversal: ");
    inOrder(root);
    printf("\n");
 
    printf("Post-order traversal: ");
    postOrder(root);
    printf("\n");
 
    return 0;
}
