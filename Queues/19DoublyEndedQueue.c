// Implementation usinf array

// #include<stdio.h>
// #include<stdlib.h>

// #define MAX 10
// int deque[MAX];
// int front = -1;
// int rear = -1;

// void InsertionAtRear(){
//     int value;
//     if(rear == MAX-1){
//         printf("Insertion at rear is not possible\n");
//         return;
//     }
//     printf("Enter the value : ");
//     scanf("%d", &value);
//     if(front == -1){
//         front = 0;
//         rear = 0;
//     }else{
//         rear++;
//     }

//     deque[rear] = value;
//     printf("%d is inserted into the doubly linked list at position %d",value,rear);
// }

// void InsertionAtFront(){
//     int value;
//     if(front == 0){
//         printf("Insertion at front is not possible\n");
//         return;
//     }
//     printf("Enter the value : ");
//     scanf("%d", &value);

//     if(front == -1){
//         front = 0;
//         rear = 0;
//     }else{
//         front--;
//     }

//     deque[front] = value;
//     printf("%d is inserted in the double ended queue at position %d", value, front);
// }

// void DeletionFromFront(){
//     if(front == -1){
//         printf("Queue is empty!\n");
//         return;
//     }
//     printf("%d is deleted from deque\n",deque[front]);
//     if(front == rear){
//         front = -1;
//         rear = -1;
//     }else{
//         front++;
//     }
// }

// void DeletionFromRear(){
//     if(rear == -1){
//         printf("Deque Underflow!\n");
//         return;
//     }
//     printf("%d is deleted from deque from position %d.",deque[rear], rear);
//     if(front == rear){
//         front = -1;
//         rear = -1;
//     }else{
//         rear--;
//     }
// }

// void display(){
//     int i;
//     if(front == -1){
//         printf("Deque is empty");
//         return;
//     }
//     printf("Deque elements are: ");

//     for(i = front; i <= rear; i++)
//     {
//         printf("%d ", deque[i]);
//     }

//     printf("\n");
// }

// void peek()
// {
//     if(front == -1)
//     {
//         printf("Deque is empty!\n");
//         return;
//     }

//     printf("Front element: %d\n", deque[front]);
//     printf("Rear element: %d\n", deque[rear]);
// }

// void isEmpty()
// {
//     if(front == -1)
//         printf("Deque is empty.\n");
//     else
//         printf("Deque is not empty.\n");
// }

// int main(){
//     int choice;
//     while(1){
//         printf("\n------------ Doubly Ended Queue ------------\n");
//         printf("1. InsertionAtRear.\n");
//         printf("2. InsertionAtFront.\n");
//         printf("3. DeletionFromFront.\n");
//         printf("4. DeletionFromRear.\n");
//         printf("5. Display.\n");
//         printf("6. Peek.\n");
//         printf("7. Exit.\n");

//         printf("Enter your choice : ");
//         scanf("%d", &choice);

//         switch(choice){
//             case 1:
//                 InsertionAtRear();
//                 break;

//             case 2:
//                 InsertionAtFront();
//                 break;
            
//             case 3:
//                 DeletionFromFront();
//                 break;

//             case 4:
//                 DeletionFromRear();
//                 break;

//             case 5:
//                 display();
//                 break;

//             case 6:
//                 peek();
//                 break;
            
//             case 7:
//                 printf("Program Terminated!");
//                 return;

//             default:
//                 printf("Invalid choice!!");
//         }
//     }
//     return 0;
// }



// Implementation using Circular Array.

#include <stdio.h>

#define MAX 5

int deque[MAX];

int front = -1;
int rear = -1;


// Check whether deque is full
int isFull()
{
    if((front == 0 && rear == MAX - 1) ||
       (front == rear + 1))
    {
        return 1;
    }

    return 0;
}


// Check whether deque is empty
int isEmpty()
{
    if(front == -1)
        return 1;

    return 0;
}


// Insert at Front
void insertionAtFront()
{
    int value;

    if(isFull())
    {
        printf("Deque Overflow!\n");
        return;
    }

    printf("Enter the value: ");
    scanf("%d", &value);

    // If deque is empty
    if(front == -1)
    {
        front = 0;
        rear = 0;
    }

    // If front is at first position
    else if(front == 0)
    {
        front = MAX - 1;
    }

    // Otherwise move front one position backward
    else
    {
        front--;
    }

    deque[front] = value;

    printf("%d inserted at front.\n", value);
}


// Insert at Rear
void insertionAtRear()
{
    int value;

    if(isFull())
    {
        printf("Deque Overflow!\n");
        return;
    }

    printf("Enter the value: ");
    scanf("%d", &value);

    // If deque is empty
    if(front == -1)
    {
        front = 0;
        rear = 0;
    }

    // If rear reaches last position
    else if(rear == MAX - 1)
    {
        rear = 0;
    }

    // Otherwise move rear forward
    else
    {
        rear++;
    }

    deque[rear] = value;

    printf("%d inserted at rear.\n", value);
}


// Delete from Front
void deletionFromFront()
{
    if(isEmpty())
    {
        printf("Deque Underflow!\n");
        return;
    }

    printf("%d deleted from front.\n", deque[front]);

    // Only one element
    if(front == rear)
    {
        front = -1;
        rear = -1;
    }

    // If front is at last position
    else if(front == MAX - 1)
    {
        front = 0;
    }

    // Otherwise move front forward
    else
    {
        front++;
    }
}


// Delete from Rear
void deletionFromRear()
{
    if(isEmpty())
    {
        printf("Deque Underflow!\n");
        return;
    }

    printf("%d deleted from rear.\n", deque[rear]);

    // Only one element
    if(front == rear)
    {
        front = -1;
        rear = -1;
    }

    // If rear is at first position
    else if(rear == 0)
    {
        rear = MAX - 1;
    }

    // Otherwise move rear backward
    else
    {
        rear--;
    }
}


// Display
void display()
{
    int i;

    if(isEmpty())
    {
        printf("Deque is empty!\n");
        return;
    }

    printf("Deque elements are: ");

    i = front;

    while(1)
    {
        printf("%d ", deque[i]);

        if(i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}


// Peek
void peek()
{
    if(isEmpty())
    {
        printf("Deque is empty!\n");
        return;
    }

    printf("Front element: %d\n", deque[front]);
    printf("Rear element: %d\n", deque[rear]);
}


int main()
{
    int choice;

    while(1)
    {
        printf("\n--------- CIRCULAR DEQUE ---------\n");

        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display\n");
        printf("6. Peek\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                insertionAtFront();
                break;

            case 2:
                insertionAtRear();
                break;

            case 3:
                deletionFromFront();
                break;

            case 4:
                deletionFromRear();
                break;

            case 5:
                display();
                break;

            case 6:
                peek();
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