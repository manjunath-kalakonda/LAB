#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->left = node->right = NULL;
    return node;
}
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) 
    return newNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}
struct Node* findMin(struct Node* node) { while (node->left != NULL) node = node->left;
return node;
}
struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL) return root;

    else if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);
    printf("Deleting 20...\n");
    root = deleteNode(root, 20);
    printf("\n");
    printf("Deleting 30...\n");
    root = deleteNode(root, 30);
    printf("\n");
    printf("Deleting 50...\n");
    root = deleteNode(root, 50);
    printf("\n");
    return 0;
}
