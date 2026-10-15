#include<stdio.h>
#include<stdlib.h>

struct node{
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
    new->next = NULL;

    if(front == NULL){
        front = new;
        rear = new;
    }else{
        rear->next = new;
        rear = new;
    }
    printf("%d is inserted in the queue.", value);
}

void dequeue(){
    if(front == NULL){
        printf("Queue Underflow\n");
        return;
    }
    struct node *temp = front;

    printf("%d is deleted from the queue\n",front->data);
    
    front = front->next;

    if(front == NULL){
        rear = NULL;
    }
    free(temp);
}

void peek(){
    if(front == NULL){
        printf("Queue is empty!");
        return;
    }
    printf("%d is the element at the front", front->data);
}

void display(){
    struct node *temp = front;
    if(front == NULL ){
        printf("Queue is empty!");
        return;
    }
    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf(" NULL\n");
}

void isEmpty(){
    if(front == NULL){
        printf("Yes, Queue is empty.");
    }else{
        printf("No. Queue is not empty.");
    }
}

int main(){
    int choice;

    while(1){
        printf("\n----------Linked List Queue-----------\n");
        printf("1. Enqueue.\n");
        printf("2. Dequeue.\n");
        printf("3. Peek.\n");
        printf("4. Display.\n");
        printf("5. isEmpty.\n");
        printf("6. Exit.\n");

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
                printf("Program terminated!!");
                return 0;
            default:
                printf("Invalid choice!!");
        }
    }
    return 0;
}