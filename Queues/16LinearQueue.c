#include<stdio.h>
#include<stdlib.h>

#define MAX 100
int queue[MAX];
int rear = -1;
int front = -1;

// Enqueue Operation.
void enqueue(){
    int value;
    if(rear == MAX-1){
        printf("Queue overflow\n");
        return;
    }

    printf("Enter the value : ");
    scanf("%d", &value);

    if(front = -1){
        front = 0;
    }
    rear++;
    queue[rear] = value;
    printf("%d is entered in the queue at position %d", value, rear);
}

// Dequeue operation.
void dequeue(){
    if(front == -1 || front > rear){
        printf("Queue Underflow\n");
        return;
    }
    printf("%d is deleted from queue", queue[front]);
    front++;
    if(front > rear){
        front = -1;
        rear = -1;
    }
}

// Peek Operation.
void peek(){
    if(front == -1){
        printf("Queue is empty\n");
        return;
    }
    printf("Front element is : %d\n", queue[front]);
}

// Display Operation.
void display(){
    int i;

    if(front == -1){
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are : ");
    for(i = front; i <= rear; i++){
        printf("%d ",queue[i]);
    }
    printf("\n");
}

void isEmpty()
{
    if (front == -1)
        printf("Yes, Queue is Empty.!");
    else
        printf("No, Queue is not Empty.!");
}

void isFull()
{
    if (rear == MAX - 1)
        printf("Yes, Queue is Full.!");
    else
        printf("No, Queue is not Full.!");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n--------- Linear Queue ---------\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. isEmpty\n");
        printf("6, isFull\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                isEmpty();
                break;

            case 6:
                isFull();
                break;

            case 7:
                printf("Program terminated.\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}