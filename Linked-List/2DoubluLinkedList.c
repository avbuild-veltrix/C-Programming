#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};

struct node* head;
struct node* tail;

void createDoublyLinkedList(){
    struct node *new;
    head = 0;
    int choice;
    do{
        new = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data ");
        scanf("%d", &new->data);
        new->prev = 0;
        new->next = 0;
        if(head == 0){
            head = tail = new;
        }else{
            tail->next = new;
            new->prev = tail;
            tail = new;
        }
        printf("Do you want to add more data (1 for YES and 0 for NO) : ");
        scanf("%d", &choice);
    }
    while(choice == 1);
}

void display(){
    struct node *temp = head;
    printf("Linked List : ");
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }  
    printf("NULL\n");
}

void insertionAtBeginning(){
    struct node *new;
    new = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data : ");
    scanf("%d", &new->data);
    new->prev = NULL;
    new->next = NULL;
    if(head == NULL){
        head = new;
        tail = head;
    }else{
        head->prev = new;
        new->next = head;
        head = new;
    }
 
}

void insertionAtEnd(){
    struct node *new;
    new = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data : ");
    scanf("%d", &new->data);
    new->prev = NULL;
    new->next = NULL;
    if(head == NULL){
        head = new;
        tail = head;
    }else{
        tail -> next = new;
        new -> prev = tail;
        tail = new;
    }

}

void insertionAtAnyPosition(){
    struct node *new, *temp = head;
    int pos, count = 0;
    printf("Enter the position : ");
    scanf("%d", &pos);
    new = (struct node*)malloc(sizeof(struct node));
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    if(pos <  1 || pos > count+1){
        printf("Invalid Position\n");
    }else{
        if(head == NULL){
            head = new;
            tail = head;
            printf("Linked List is empty\n");
        }else if(pos == 1){
            insertionAtBeginning();
        }else if(pos == count + 1){
            insertionAtEnd();
        }else{
            printf("Enter the data : ");
            scanf("%d", &new->data);
            new->prev = NULL;
            new->next = NULL;
            for(int i = 1; i < pos - 1; i++){
                temp = temp->next;
            }
            new->prev = temp;
            new->next = temp->next;
            temp->next = new;
            new->next->prev = new;
        }
    }
}

void insertionAtAnySpecificKey(){
    struct node *temp = head, *new;
    int key;
    printf("Enter the key : ");
    scanf("%d", &key);
    new = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data to be inserted : ");
    scanf("%d", &new->data);
    if(head == NULL){
        printf("Linked List is empty\n");
    }else{
        while(temp->data != key){
            temp = temp->next;
        }
        if(temp == NULL){
            printf("Key is not found.");
            return;
        }
        new->prev = temp;
        new->next = temp->next;
        if(temp->next != NULL){
            temp->next->prev = new;
        }
       temp->next = new;
    }
}

void deleteFromBeginning(){
    struct node *temp = tail;
    if(head == NULL){
        printf("Linked List is empty\n");
    }else if(head == tail){
        head = tail = NULL;
        free(temp);
    }else{
        head->next->prev = NULL;
        head = head->next;
        free(temp);
    }
}

void deleteFromEnd(){
    struct node *temp = head;
    if(head == NULL){
        printf("Linked List is empty\n");
    }else if(head == tail){
        head = tail = NULL;
        free(temp);
    }else{
        tail = tail->prev;
        tail->next = NULL;
        free(temp);
    }
}

void deletionAtAnyPosition(){
    struct node *temp = head;
    int pos;
    printf("Enter the position : ");
    scanf("%d", &pos);
    if(head == NULL){
        printf("Linked List is empty\n");
    }else if(head == tail){
        head = tail = NULL;
        free(temp);
    }else if(pos == 1){
        head = head->next;
        head->prev = NULL;
        free(temp);
    }else{
        for(int i = 0; i < pos-1; i++){
            temp = temp->next;
        }
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        free(temp);
    }
}

void deleteAnySpecificKey(){
    struct node *temp = head;
    int key;
    printf("Enter the key : ");
    scanf("%d", &key);
    if(head == NULL){
        printf("Linked List is empty");
    }else{
        while(temp != NULL && temp->data != key){
            temp = temp->next;
        }
        if(temp == NULL){
            printf("Key is not found.");
            return;
        }
        // If key is the first node
        if(temp == head && temp == tail){
            head = tail = NULL;
            free(temp);
        }
        // If key is the last node
        else if(temp == tail){
            tail = tail->prev;
            tail->next = NULL;
            free(temp);
        }else{
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
        }
    }
}

void reverse(){
    struct node *currentNode, *nextNode;
    currentNode = head;
    while(currentNode != NULL){
        nextNode = currentNode->next;
        currentNode->next = currentNode->prev;
        currentNode->prev = nextNode;
        currentNode = nextNode;
    }
    nextNode = head;
    head = tail;
    tail = nextNode;
}

int main(){
    createDoublyLinkedList();
    display();
    // insertionAtBeginning();
    // insertionAtEnd();
    // insertionAtAnyPosition();
    // insertionAtAnySpecificKey();
    // deleteFromBeginning();
    // deleteFromEnd();
    // deletionAtAnySpecificPosition();
    // deleteAnySpecificKey();
    reverse();

    display();
    return 0;
}