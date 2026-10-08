#include <stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    top++;
    stack[top] = value;

    printf("%d is pushed into the stack.\n", value);
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }

    printf("%d is popped from the stack.\n", stack[top]);

    top--;
}

void peek()
{
    if (top == -1)
    {
        printf("Stack is empty.\n");
        return;
    }

    printf("%d is the top element in the stack.\n", stack[top]);
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty.\n");
        return;
    }

    printf("\nStack elements:\n");

    for (int i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }

    printf("\n");
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