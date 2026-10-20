// #include <stdio.h>

// #define SIZE 100

// int tree[SIZE];

// void insert(int value)
// {
//     int i = 0;

//     while (i < SIZE)
//     {
//         if (tree[i] == -1)
//         {
//             tree[i] = value;
//             return;
//         }

//         if (value < tree[i])
//         {
//             i = 2 * i + 1;
//         }
//         else if (value > tree[i])
//         {
//             i = 2 * i + 2;
//         }
//         else
//         {
//             printf("Duplicate values are not allowed.\n");
//             return;
//         }
//     }

//     printf("Tree is full or array capacity is insufficient.\n");
// }

// int main()
// {
//     for (int i = 0; i < SIZE; i++)
//     {
//         tree[i] = -1;
//     }

//     insert(50);
//     insert(30);
//     insert(70);
//     insert(20);
//     insert(40);

//     printf("BST array representation:\n");

//     for (int i = 0; i < SIZE; i++)
//     {
//         if (tree[i] != -1)
//         {
//             printf("Index %d: %d\n", i, tree[i]);
//         }
//     }

//     return 0;
// }

// #include<stdio.h>

// #define SIZE 100

// int tree[SIZE];

// void inorder(int i) {
//     if (i >= SIZE || tree[i] == -1)
//         return;

//     inorder(2 * i + 1);
//     printf("%d ", tree[i]);
//     inorder(2 * i + 2);
// }

// void preorder(int i) {
//     if (i >= SIZE || tree[i] == -1)
//         return;

//     printf("%d ", tree[i]);
//     preorder(2 * i + 1);
//     preorder(2 * i + 2);
// }

// void postorder(int i) {
//     if (i >= SIZE || tree[i] == -1)
//         return;

//     postorder(2 * i + 1);
//     postorder(2 * i + 2);
//     printf("%d ", tree[i]);
// }

// void insert(int value){
//     int i = 0;

//     while(i < SIZE){

//         if(tree[i] == -1){
//             tree[i] = value;
//             return;
//         }

//         if(value < tree[i]){
//             i = 2 * i + 1;
//         }
//         else if(tree[i] < value){
//             i = 2 * i + 2;
//         }

//         else{
//             printf("Duplicate values are not allowed!\n");
//             return;
//         }
//     }
//     printf("Tree is full or array capacity is insufficient!\n");
//     return;
// }

// int main(){
//     for(int i = 0; i < SIZE; i++){
//         tree[i] = -1;
//     }

//     printf("Binary Tree Representation is : \n");

//     insert(40);
//     insert(10);
//     insert(60);
//     insert(30);
//     insert(50);
//     insert(20);
//     insert(70);

//     for(int i = 0; i < SIZE; i++){
//         if(tree[i] != -1){
//             printf("Index %d : %d\n",i, tree[i]);
//         }
//     }

//     printf("Inorder: ");
//     inorder(0);

//     printf("\nPreorder: ");
//     preorder(0);

//     printf("\nPostorder: ");
//     postorder(0);

//     return 0;
// }

#include <stdio.h>

#define SIZE 100

int tree[SIZE];

// Insertion
void insert(int value) {
    int i = 0;

    while (i < SIZE) {
        if (tree[i] == -1) {
            tree[i] = value;
            return;
        }

        if (value < tree[i])
            i = 2 * i + 1;
        else if (value > tree[i])
            i = 2 * i + 2;
        else {
            printf("Duplicate values are not allowed!\n");
            return;
        }
    }

    printf("Array capacity exceeded!\n");
}

// Searching
int search(int value) {
    int i = 0;

    while (i < SIZE && tree[i] != -1) {
        if (tree[i] == value)
            return i;

        if (value < tree[i])
            i = 2 * i + 1;
        else
            i = 2 * i + 2;
    }

    return -1;
}

// Find minimum value's index in a subtree
int findMin(int i) {
    while (2 * i + 1 < SIZE && tree[2 * i + 1] != -1)
        i = 2 * i + 1;

    return i;
}

// Deletion
void deleteNode(int value) {
    int i = search(value);

    if (i == -1) {
        printf("Value not found!\n");
        return;
    }

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // No children
    if ((left >= SIZE || tree[left] == -1) &&
        (right >= SIZE || tree[right] == -1)) {
        tree[i] = -1;
    }

    // Only right child
    else if (left >= SIZE || tree[left] == -1) {
        int child = right;

        while (child < SIZE && tree[child] != -1) {
            int l = 2 * child + 1;
            int r = 2 * child + 2;

            if (l < SIZE && tree[l] != -1) {
                tree[i] = tree[child];
                i = child;
                child = l;
            } else if (r < SIZE && tree[r] != -1) {
                tree[i] = tree[child];
                i = child;
                child = r;
            } else {
                tree[i] = tree[child];
                tree[child] = -1;
                return;
            }
        }
        tree[i] = -1;
    }

    // Only left child
    else if (right >= SIZE || tree[right] == -1) {
        int child = left;

        while (child < SIZE && tree[child] != -1) {
            int l = 2 * child + 1;
            int r = 2 * child + 2;

            if (l < SIZE && tree[l] != -1) {
                tree[i] = tree[child];
                i = child;
                child = l;
            } else if (r < SIZE && tree[r] != -1) {
                tree[i] = tree[child];
                i = child;
                child = r;
            } else {
                tree[i] = tree[child];
                tree[child] = -1;
                return;
            }
        }
        tree[i] = -1;
    }

    // Two children
    else {
        int minIndex = findMin(right);
        tree[i] = tree[minIndex];
        deleteNode(tree[minIndex]);
    }
}

// Inorder: Left, Root, Right
void inorder(int i) {
    if (i >= SIZE || tree[i] == -1)
        return;

    inorder(2 * i + 1);
    printf("%d ", tree[i]);
    inorder(2 * i + 2);
}

// Preorder: Root, Left, Right
void preorder(int i) {
    if (i >= SIZE || tree[i] == -1)
        return;

    printf("%d ", tree[i]);
    preorder(2 * i + 1);
    preorder(2 * i + 2);
}

// Postorder: Left, Right, Root
void postorder(int i) {
    if (i >= SIZE || tree[i] == -1)
        return;

    postorder(2 * i + 1);
    postorder(2 * i + 2);
    printf("%d ", tree[i]);
}

// Display array positions
void display() {
    for (int i = 0; i < SIZE; i++) {
        if (tree[i] != -1)
            printf("Index %d: %d\n", i, tree[i]);
    }
}

int main() {
    int choice, value;

    for (int i = 0; i < SIZE; i++)
        tree[i] = -1;

    do {
        printf("\n--- BST Using Array ---\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Inorder\n");
        printf("5. Preorder\n");
        printf("6. Postorder\n");
        printf("7. Display Array\n");
        printf("8. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1)
            return 1;

        switch (choice) {
            case 1:
                printf("Enter value: ");
                if (scanf("%d", &value) != 1)
                    return 1;
                insert(value);
                break;

            case 2:
                printf("Enter value to search: ");
                if (scanf("%d", &value) != 1)
                    return 1;

                if (search(value) != -1)
                    printf("Value found at index %d\n", search(value));
                else
                    printf("Value not found!\n");
                break;

            case 3:
                printf("Enter value to delete: ");
                if (scanf("%d", &value) != 1)
                    return 1;
                deleteNode(value);
                break;

            case 4:
                printf("Inorder: ");
                inorder(0);
                printf("\n");
                break;

            case 5:
                printf("Preorder: ");
                preorder(0);
                printf("\n");
                break;

            case 6:
                printf("Postorder: ");
                postorder(0);
                printf("\n");
                break;

            case 7:
                display();
                break;

            case 8:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 8);

    return 0;
}