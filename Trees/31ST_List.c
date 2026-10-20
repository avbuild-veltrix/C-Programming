// #include <stdio.h>
// #include <stdlib.h>

// struct Node {
//     int data;
//     struct Node *left;
//     struct Node *right;
// };

// struct Node* createNode(int value) {
//     struct Node *newNode = malloc(sizeof(struct Node));

//     if (newNode == NULL) {
//         printf("Memory allocation failed!\n");
//         exit(1);
//     }

//     newNode->data = value;
//     newNode->left = NULL;
//     newNode->right = NULL;

//     return newNode;
// }

// struct Node* insert(struct Node *root, int value) {
//     if (root == NULL) {
//         return createNode(value);
//     }

//     if (value < root->data) {
//         root->left = insert(root->left, value);
//     }
//     else if (value > root->data) {
//         root->right = insert(root->right, value);
//     }

//     return root;
// }

// void inorder(struct Node *root) {
//     if (root == NULL)
//         return;

//     inorder(root->left);
//     printf("%d ", root->data);
//     inorder(root->right);
// }

// void preorder(struct Node *root) {
//     if (root == NULL)
//         return;

//     printf("%d ", root->data);
//     preorder(root->left);
//     preorder(root->right);
// }

// void postorder(struct Node *root) {
//     if (root == NULL)
//         return;

//     postorder(root->left);
//     postorder(root->right);
//     printf("%d ", root->data);
// }

// int main() {
//     struct Node *root = NULL;

//     root = insert(root, 40);
//     root = insert(root, 20);
//     root = insert(root, 60);
//     root = insert(root, 10);
//     root = insert(root, 30);
//     root = insert(root, 50);
//     root = insert(root, 70);

//     printf("Inorder Traversal: ");
//     inorder(root);

//     printf("\nPreorder Traversal: ");
//     preorder(root);

//     printf("\nPostorder Traversal: ");
//     postorder(root);

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insertion
struct Node* insert(struct Node *root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Searching
struct Node* search(struct Node *root, int value) {
    if (root == NULL || root->data == value)
        return root;

    if (value < root->data)
        return search(root->left, value);

    return search(root->right, value);
}

// Find minimum node
struct Node* findMin(struct Node *root) {
    while (root != NULL && root->left != NULL)
        root = root->left;

    return root;
}

// Deletion
struct Node* deleteNode(struct Node *root, int value) {
    if (root == NULL)
        return NULL;

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    }
    else {
        // Case 1: No left child
        if (root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }

        // Case 2: No right child
        if (root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Two children
        struct Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Inorder: Left, Root, Right
void inorder(struct Node *root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Preorder: Root, Left, Right
void preorder(struct Node *root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Postorder: Left, Right, Root
void postorder(struct Node *root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    struct Node *root = NULL;
    struct Node *result;
    int choice, value;

    do {
        printf("\n\n--- BST Operations ---\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);

                result = search(root, value);

                if (result != NULL)
                    printf("%d found in BST.\n", value);
                else
                    printf("%d not found in BST.\n", value);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);

                if (search(root, value) == NULL) {
                    printf("%d not found in BST.\n", value);
                } else {
                    root = deleteNode(root, value);
                    printf("%d deleted successfully.\n", value);
                }
                break;

            case 4:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;

            case 5:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;

            case 6:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;

            case 7:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 7);

    return 0;
}2