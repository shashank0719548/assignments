#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *left;
    int data;
    struct node *right;
};

struct node* createnode(int n) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->right = newnode->left = NULL;
    newnode->data = n;
    return newnode;
}

struct node* insert(struct node* root, int n) {
    if (root == NULL) {
        return createnode(n);
    }
    if (n > root->data) {
        root->right = insert(root->right, n);
    } else if (n < root->data) {
        root->left = insert(root->left, n);
    }
    return root;
}

struct node* minValueNode(struct node* root) {
    struct node* current = root;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct node* deletenode(struct node* root, int key) {
    if (root == NULL) return root;
    if (key < root->data)
        root->left = deletenode(root->left, key);
    else if (key > root->data)
        root->right = deletenode(root->right, key);
    else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deletenode(root->right, temp->data);
    }
    return root;
}

void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct node* root = NULL;
    int n, val, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("1. Insert an element\n");
    printf("2. Delete an element\n");
    printf("3. Print elements\n");
    printf("4. Exit\n");

    while (1) {
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                root = deletenode(root, val);
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
