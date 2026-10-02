#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head;
struct node *tail;

void createCircularLinkedList(){
    struct node *new;
    head = tail = NULL;
    int choice;
    do{
        new = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data : ");
        scanf("%d", &new->data);
        new->next = NULL;
        if(head == NULL){
            head = tail = new;
            tail->next = head;
        }else{
            tail->next = new;
            tail = new;
            tail->next = head;
        }
        printf("Do you want to add node? (1 for yes 0 for NO) ");
        scanf("%d", &choice);
    }while(choice == 1);
}

// struct node* createNode()
// {
//     struct node *newNode;

//     newNode = (struct node *)malloc(sizeof(struct node));

//     printf("Enter the data: ");
//     scanf("%d", &newNode->data);

//     newNode->next = NULL;

//     return newNode;
// }

// void createCircularLinkedList()
// {
//     struct node *newNode;
//     int choice;

//     head = NULL;
//     tail = NULL;

//     do
//     {
//         newNode = createNode();

//         if(head == NULL)
//         {
//             head = newNode;
//             tail = newNode;
//         }
//         else
//         {
//             tail->next = newNode;
//             tail = newNode;
//         }

//         tail->next = head;

//         printf("Do you want to add another node? (1 = Yes, 0 = No): ");
//         scanf("%d", &choice);

//     } while(choice == 1);
// }

void display(){
    struct node *temp = head;
    if(head == NULL){
        printf("Linked List is empty.");
    }else{
        printf("Linked List : ");
        do{
            printf("%d -> ", temp->data);
            temp = temp->next;
        }while(temp != head);
        printf("head\n");
    }
}

void count(){
    struct node *temp = head;
    int count = 0;
    if(head == NULL){
        printf("Linked List is empty");
    }else{
        do{
            count++;
            temp = temp->next;
        }while(temp != head);
    }
    printf("Total nodes present in Circular Linked List is : %d\n", count);
}

void insertAtBeginning(){
    struct node *new;
    new = (struct node*)malloc(sizeof(struct node));
    new->next = NULL;
    printf("Enter the data you want to enter : ");
    scanf("%d", &new->data);
    if(head == NULL){
        head = new;
        tail = new;
        tail->next = head;
    }else{
        new->next = head;
        head = new;
        tail->next = head;
    }
}

void insertAtEnd(){
    struct node *temp = head, *new;
    new = (struct node*)malloc(sizeof(struct node));
    new->next = NULL;
    printf("Enter the data : ");
    scanf("%d", &new->data);
    if(head == NULL){
        head = new;
        tail = new;
        tail->next = head;
    }else{
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = new;
        tail = new;
        tail->next = head;
    }
}

void insertAtAnyPosition(){
    struct node *new, *temp;
    int pos;

    printf("Enter the position: ");
    scanf("%d", &pos);

    new = (struct node*)malloc(sizeof(struct node));

    printf("Enter the data: ");
    scanf("%d", &new->data);

    if(head == NULL){
        if(pos != 1){
            printf("Invalid position.\n");
            free(new);
            return;
        }

        head = new;
        tail = new;
        tail->next = head;
    }
    else if(pos == 1){
        new->next = head;
        head = new;
        tail->next = head;
    }
    else{
        temp = head;

        for(int i = 1; i < pos - 1; i++){
            temp = temp->next;

            if(temp == head){
                printf("Invalid position.\n");
                free(new);
                return;
            }
        }

        new->next = temp->next;
        temp->next = new;

        if(temp == tail){
            tail = new;
        }
    }
}

void insertAfterAnySpecificKey(){
    struct node *temp = head, *new;
    int key;

    printf("Enter the key: ");
    scanf("%d", &key);

    new = (struct node*)malloc(sizeof(struct node));

    printf("Enter the data: ");
    scanf("%d", &new->data);

    if(head == NULL){
        printf("Invalid key.\n");
        free(new);
        return;
    }else{
        while(temp->data != key){
            temp = temp->next;
            if(temp == head){
                printf("Key not found.\n");
                free(new);
                return;
            }
        }
        new->next = temp->next;
        temp->next = new;

        if(temp == tail){
            tail = new;
        }
    }
}

void deleteFromBeginning(){
    struct node *temp;
    if(head == NULL){
        printf("Empty Linked List\n");
        return;
    }else if(head == tail){
        temp = head;
        head = tail = NULL;
        free(temp);
    }else{
        temp = head;
        head = head->next;
        tail->next = head;
        free(temp);
    }
}

void deleteFromEnd(){
    struct node *temp, *prev;
    if(head == NULL){
        printf("Empty Linked List\n");
    }else if(head == tail){
        temp = head;
        head = tail = NULL;
        free(temp);
    }else{
        temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        prev = temp;
        temp = temp->next;
        tail = prev;
        tail->next = head;
        free(temp);
    }
}

void deleteFromSpecificPosition(){
    struct node *temp = head;
    int pos;
    printf("Enter the position : ");
    scanf("%d", &pos);
    if(head == NULL){
        printf("Empty Linked List\n");
    }else if(pos <= 0){
        printf("Invalid position\n");
    }else if(head == tail){
        if(pos != 1){
            printf("Invalid position\n");
        }else{
            temp = head;
            head = tail = NULL;
            free(temp);
        }
    }else if(pos == 1){
        head = head->next;
        tail = head;
        free(temp);
    }else{
        for(int i = 1; i < pos - 1; i++){
            temp = temp->next;
        }
        if(temp == tail){
            printf("Invalid position\n");
            return;
        }
        struct node *deleteNode = temp->next;
        temp->next = deleteNode->next;
        if(deleteNode == tail){
            tail = temp;
        }
        free(deleteNode);
    }
}

void deleteFromSpecificKey(){
    struct node *temp, *prev;
    int key;
    printf("Enter the key : ");
    scanf("%d", &key);
    if(head == NULL){
        printf("Empty Linked List.\n");
        return;
    }
    // Only one node
    if(head == tail){
        if(head->data == key){
            temp = head;
            head = tail = NULL;
            free(temp);
        }else{
            printf("Key is not present.\n");
        }
        return;
    }
    // If key is in first node
    if(head->data == key){
        temp = head;
        head = head->next;
        tail->next = head;
        free(temp);
        return;
    }
    // Search for key
    prev = head;
    temp = head->next;
    while(temp != head){
        if(temp->data == key){
            prev->next = temp->next;
            if(temp == tail){
                tail = prev;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Key is not present.\n");
}

int main(){
    createCircularLinkedList();
    display();
    // count();
    // insertAtBeginning();
    // insertAtEnd();
    // insertAtAnyPosition();
    // insertAfterAnySpecificKey();
    // deleteFromBeginning();
    // deleteFromEnd();
    // deleteFromSpecificPosition();
    deleteFromSpecificKey();
    display();
}