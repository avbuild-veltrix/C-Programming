#include<stdio.h>
#include<stdlib.h>


struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

// void isEmpty()
// {
    // if(top == NULL)
    // {
    //     printf("Stack is empty\n");
    // }
    // else
    // {
    //     printf("Stack is not empty\n");
    // }
// }

void push(int value){
    struct node *new = malloc(sizeof(struct node));
    if(new == NULL){
        printf("Heap Overflow\n");
        return;
    }
    new->data = value;
    new->next = top;
    top = new;
    printf("%d is pushed on stack.\n", value);
}

void pop(){
    if(top == NULL){
        printf("Stack is empty\n");
        return;
    }
    struct node *del = top;
    top = top->next;
    printf("%d is deleted from stack.\n", del->data);
    free(del);
}

void peek(){
    if(top == NULL){
        printf("Stack is empty\n");
        return;
    }
    printf("%d is the top element", top->data);
}

void display(){
    struct node *temp = top;
    printf("The element in the stack are : ");

    if(top == NULL){
        printf("Stack is empty\n");
        return;
    }

    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int choice;
    int value;

    do
    {
        printf("\n========== STACK MENU ==========\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);

                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}