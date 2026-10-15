// Circular Queue using array.

// #include<stdio.h>
// #include<stdio.h>

// #define MAX 100
// int queue[MAX];
// int front = -1;
// int rear = -1;

// void enqueue(){
//     int value;

//     if(front == (rear + 1)%MAX){
//         printf("Queue Overflow!\n");
//         return;
//     }

//     printf("Enter the value : ");
//     scanf("%d", &value);

//     if(front == -1){
//         front = 0;
//         rear = 0;
//     }else{
//         rear = (rear + 1) % MAX;
//     }

//     queue[rear] = value;
//     printf("%d is added into the queue at position %d\n", value, rear);
// }

// void dequeue(){
//     if(front == -1){
//         printf("Underflow!\n");
//         return;
//     }
//     printf("%d is deleted from the position %d from the circular queue\n", queue[front], front);
    
//     if(front == rear){
//         front = -1;
//         rear = -1;
//     }else{
//         front = (front + 1) % MAX;
//     }
// }

// void peek(){
//     if(front == -1){
//         printf("Circular Queue is empty!\n");
//         return;
//     }
//     printf("%d is the front element.\n", queue[front]);
// }

// void display(){
//     int i;
//     if(front == -1){
//         printf("Circular Queue is empty!\n");
//         return;
//     }
    
//     printf("Circular queue elements are : ");
//     i = front;
//     while(1){
//         if(i == front){
//             break;
//         }
//         printf("%d ",queue[i]);
//         i = (i + 1) % MAX;
//     }
// }

// void isEmpty(){
//     if(front == -1){
//         printf("Yes, Circular Queue is empty!\n");
//     }else{
//         printf("No, Circular queue is not empty\n");
//     }
// }

// int main(){
//     int choice;
//     while(1){
//         printf("\n------------Circular Queue Using Array------------\n");
//         printf("1. Enqueue.\n");
//         printf("2. Dequeue.\n");
//         printf("3. Peek.\n");
//         printf("4. Display\n");
//         printf("5. isEmpty.\n");
//         printf("6. Terminate the program.\n");

//         printf("Enter your choice : ");
//         scanf("%d", &choice);

//         switch(choice){
//             case 1:
//                 enqueue();
//                 break;

//             case 2:
//                 dequeue();
//                 break;
            
//             case 3:
//                 peek();
//                 break;

//             case 4:
//                 display();
//                 break;
            
//             case 5:
//                 isEmpty();
//                 break;
            
//             case 6:
//                 printf("Program terminated.");
//                 return 0;

//             default:
//                 printf("Invalid Prompty");
//         }
//     }
//     return 0;
// }


// Circular Queue using Linked List.

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(){
    int value;
    printf("Enter the value : ");
    scanf("%d", &value);
    struct node *new = (struct node*)malloc(sizeof(struct node));
    if(new == NULL){
        printf("Memory allocation failed!");
        return;
    }
    new->data = value;
    if(front == NULL){
        front = new;
        rear = new;

        rear -> next = front;
    }else{
        new->next = front;
        rear->next = new;
        rear = new;
    }
    printf("%d is inserted in the circular queue\n", value);
}

void dequeue(){
    if(front == NULL){
        printf("Underflow!");
        return;
    }
    struct node *temp = front;
    if (front == rear){
        printf("%d is deleted from the circular queue\n", temp->data);

        front = NULL;
        rear = NULL;

        free(temp);
    }else{
        front = front->next;
        rear->next = front;

        printf("%d is deleted from the circular queue\n", temp->data);

        free(temp);
    }
}

void peek(){
    if(front == NULL){
        printf("Circular Queue is empty\n");
        return;
    }
    printf("%d is the front element\n", front->data);
}

void display(){
    if(front == NULL){
        printf("Circular queue is empty!.");
    }
    struct node *temp = front;
    printf("Queue elements are : ");
    do{
        printf("%d - ", temp->data);
        temp = temp->next;
    }while(temp != front);
    printf("End\n");
}

void isEmpty(){
    if(front == NULL){
        printf("Yes, Circular Queue is empty!");
    }else{
        printf("No, Circular Queue is not empty!");
    }
}

int main(){
    int choice;
    while(1){
        printf("\n------------Circular Queue Using Linked List------------\n");
        printf("1. Enqueue.\n");
        printf("2. Dequeue.\n");
        printf("3. Peek.\n");
        printf("4. Display\n");
        printf("5. isEmpty.\n");
        printf("6. Terminate the program.\n");

        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice){
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
                printf("Program terminated.");
                return 0;

            default:
                printf("Invalid Prompty");
        }
    }
    return 0;
}