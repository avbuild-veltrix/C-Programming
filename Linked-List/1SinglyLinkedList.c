#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void createList(){
    int choice = 0;
    struct node *temp;
    do{
        struct node *new = malloc(sizeof(struct node));
        printf("Enter the data you want to insert : ");
        scanf("%d", &new->data);
        new->next = NULL;
        if(head == NULL){
            head = temp = new;
        }else{
            temp->next = new;
            temp = new;   
        }
        printf("Do you want to add more nodes? (1 for yes/ 0 for no) ");
        scanf("%d", &choice);
    }while(choice == 1);
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

void countNodes(){
    int count = 0, positive = 0, negative = 0, zero = 0;
    struct node *temp = head;
    while(temp != NULL){
        count++;
        if(temp->data > 0){
            positive++;
        }else if(temp->data < 0){
            negative++;
        }else{
            zero++;
        }
        temp = temp->next;
    }
    printf("Total number of nodes is %d", count);
    printf("\nTotal number of positive nodes is %d", positive);
    printf("\nTotal number of negative nodes is %d", negative);
    printf("\nTotal number of zero nodes is %d", zero);
}

void search(){
    int key, found = 0;
    printf("\nEnter the key you want to search : ");
    scanf("%d", &key);
    struct node *temp = head;
    while(temp != NULL){
        if(head == NULL){
            printf("\nLinked List is empty.");
        }else{
            if(temp->data == key){
                found = 1;
                break;
            }else{
                temp = temp->next;
            }
        }
    }
    if(found == 1){
        printf("%d is present in the linked list.");
    }else{
        printf("%d is not present in the linked list.");
    }
}

void insertAtBeginning(){
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->next = NULL;
    printf("Enter node data you want to insert at the beginning of the list : ");
    scanf("%d", &new->data);
    new->next = head;
    head = new;
}

void insertAtEnd(){
    struct node *new, *temp;
    new = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data you want to insert at the end of the list : ");
    scanf("%d",&new->data);
    if(head == NULL){
        head = new;
    }else{
        temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new;
    }
}

void insertAtPosition(){
    struct node *new, *temp;
    int pos;
    new = (struct node *)malloc(sizeof(struct node));
    new->next = NULL;
    printf("Enter the position you want to enter the data : ");
    scanf("%d", &pos);
    printf("Enter the data you want to enter at postion %d ", pos);
    scanf("%d", &new->data);
    if(head == NULL){
        printf("Linked list is empty.");
    }else{
        temp = head;
        for(int i = 1; i < pos - 1; i++){
            temp = temp->next;
        }
        new->next = temp->next;
        temp->next = new;
    }
}

void insertAfterGivenPosition(){
    struct node *new, *temp;
    int pos;
    new = (struct node *)malloc(sizeof(struct node));
    new->next = NULL;
    printf("Enter the position you want to enter the data : ");
    scanf("%d", &pos);
    printf("Enter the data you want to enter at postion %d ", pos);
    scanf("%d", &new->data);
    if(head == NULL){
        printf("Linked list is empty.");
    }else{
        temp = head;
        for(int i = 1; i < pos; i++){
            temp = temp->next;
        }
        new->next = temp->next;
        temp->next = new;
    }
}

void insertBeforeGivenPosition(){
    struct node *new, *temp;
    int pos;
    new = (struct node *)malloc(sizeof(struct node));
    new->next = NULL;
    printf("Enter the position you want to enter the data : ");
    scanf("%d", &pos);
    printf("Enter the data you want to enter at postion %d ", pos);
    scanf("%d", &new->data);
    if(head == NULL){
        printf("Linked list is empty.");
    }else if(pos == 1){
        new->next = head;
        head = new;
    }else{
        temp = head;
        for(int i = 1; i < pos-1; i++){
            temp = temp->next;
        }
        new->next = temp->next;
        temp->next = new;
    }
}

void insertAtSpecificPosition(){
    int i, key;
    struct node *new, *temp;
    new = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data you want to enter : ");
    scanf("%d", &new->data);
    new->next = NULL;
    printf("Enter the element after which you want to insert the key : ");
    scanf("%d", &key);

    temp = head;
    while(temp != NULL){
        if(temp->data == key){
            new->next = temp->next;
            temp->next = new;
        }
        temp = temp->next;
    }

}

void deleteFromBeginning(){
    struct node* temp;
    temp = head;
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    if(head->next == NULL){
        head = 0;
        free(temp);
    }
    head = head->next;
    free(temp);
}

void deleteFromEnd(){
    struct node *prev, *temp;
    temp = head;
    if(head == NULL){
        printf("Empty Linked List");
        return;
    }
    else if(head->next == NULL){
        head = 0;
        free(temp);
    }else{
        while(temp->next != NULL){
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
    }
}

// void deleteFromEnd(){
//     struct node *prev, *temp;
//     temp = head;
//     if(head == NULL){
//         printf("Empty Linked List");
//         return;
//     }
//     else if(head->next == NULL){
//         head = 0;
//         free(temp);
//     }else{
//         while(temp->next->next != NULL){
//             temp = temp->next;
//         }
//         free(temp->next);
//         temp->next = NULL;
//     }
// }

void deleteFromGivenPosition(){
    struct node *temp, *deletenode;
    int pos, i;
    if(head == NULL){
        printf("Linked List is empty.");
        return;
    }
    temp = head;
    if(head->next == NULL){
        head = 0;
        free(temp);
        return;
    }
    printf("Enter the position number: ");
    scanf("%d", &pos);
    if(pos == 1){
        deleteFromBeginning();
    }
    else{
        for(i = 1; i < pos-1; i++){
            temp = temp->next;
            if(temp == NULL){
                printf("Cannot be deleted.");
                return;
            }
        }
        deletenode = temp->next;
        temp->next = deletenode->next;
        free(deletenode);
    }
}

// void deleteBeforeGivenPosition(){
//     struct node *temp, *prev;
//     int pos,i;
//     if(head == NULL){
//         printf("Empty Linked List");
//         return;
//     }
//     temp = head;
//     printf("Enter the position: ");
//     scanf("%d", &pos);
//     for(i = 1; i < pos-1; i++){
//         prev = temp;
//         temp = temp->next;
//     }
//     prev->next = temp->next;
//     free(temp);
// }


void deleteBeforeGivenPosition(){

    struct node *temp, *prev;

    int pos,i;

    if(head == NULL){
        printf("Empty Linked List");
        return;
    }

    temp = head;

    printf("Enter the position: ");
    scanf("%d", &pos);

    if(pos <= 1){
        printf("No node exists before this position");
        return;
    }

    if(pos == 2){
        temp = head;
        head = head->next;
        free(temp);
        return;
    }

    for(i = 1; i < pos-1; i++){
        prev = temp;
        temp = temp->next;
    }

    prev->next = temp->next;
    free(temp);
}

// void deleteAfterGivenPosition(){
//     struct node *temp, *delnode, *nextnode;
//     int pos, i;
//     if(head == NULL){
//         printf("Empty Linked List.");
//         return;
//     }
//     temp = head;
//     printf("Enter position: ");
//     scanf("%d", &pos);

//     for(int i = 1; i < pos; i++){
//         temp = temp->next;
//     }

//     if(temp->next == NULL){
//         printf("Linked LIst is shorter");
//         return;
//     }

//     delnode = temp->next;
//     nextnode = delnode->next;
//     temp->next = nextnode;
//     free(delnode);
// }

void deleteAfterGivenPosition(){
    struct node *temp, *delnode, *nextnode;
    int pos, i;

    if(head == NULL){
        printf("Empty Linked List.");
        return;
    }

    temp = head;

    printf("Enter position: ");
    scanf("%d", &pos);

    if(pos < 1){
        printf("Invalid position.");
        return;
    }

    for(i = 1; i < pos; i++){
        if(temp == NULL){
            printf("Position does not exist.");
            return;
        }
        temp = temp->next;
    }

    if(temp == NULL){
        printf("Position does not exist.");
        return;
    }

    if(temp->next == NULL){
        printf("No node exists after this position.");
        return;
    }

    delnode = temp->next;
    nextnode = delnode->next;

    temp->next = nextnode;

    free(delnode);
}

void deleteSpecificElement(){
    struct node *temp, *prev;
    int element;

    if(head == NULL){
        printf("Empty Linked List.");
        return;
    }

    printf("Enter element to delete: ");
    scanf("%d", &element);

    // If element is in the first node
    if(head->data == element){
        temp = head;
        head = head->next;
        free(temp);
        return;
    }

    temp = head;

    while(temp != NULL && temp->data != element){
        prev = temp;
        temp = temp->next;
    }

    // Element not found
    if(temp == NULL){
        printf("Element not found.");
        return;
    }

    // Delete the node
    prev->next = temp->next;
    free(temp);
}

void createAlternateList(){
    struct node *temp, *newHead = NULL, *newNode, *last = NULL;

    temp = head;

    while(temp != NULL){
        newNode = (struct node*)malloc(sizeof(struct node));

        newNode->data = temp->data;
        newNode->next = NULL;

        if(newHead == NULL){
            newHead = newNode;
            last = newNode;
        }
        else{
            last->next = newNode;
            last = newNode;
        }

        if(temp->next != NULL)
            temp = temp->next->next;
        else
            break;
    }

    printf("Alternate Linked List: ");

    temp = newHead;

    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

void deleteBeforeSpecificNode(){
    struct node *temp, *delnode;
    int element;

    if(head == NULL){
        printf("Empty Linked List.");
        return;
    }

    printf("Enter the element: ");
    scanf("%d", &element);

    // If the specific node is the head
    if(head->data == element){
        printf("No node exists before this element.");
        return;
    }

    // If the specific node is the second node
    if(head->next != NULL && head->next->data == element){
        delnode = head;
        head = head->next;
        free(delnode);
        return;
    }

    temp = head;

    while(temp->next != NULL &&
          temp->next->next != NULL &&
          temp->next->next->data != element){
        temp = temp->next;
    }

    if(temp->next == NULL || temp->next->next == NULL){
        printf("Element not found or no node before it.");
        return;
    }

    delnode = temp->next;
    temp->next = delnode->next;

    free(delnode);
}

void deleteAfterSpecificNode(){
    struct node *temp, *delnode;
    int element;

    if(head == NULL){
        printf("Empty Linked List.");
        return;
    }

    printf("Enter the element: ");
    scanf("%d", &element);

    temp = head;

    while(temp != NULL && temp->data != element){
        temp = temp->next;
    }

    // Specific element not found
    if(temp == NULL){
        printf("Element not found.\n");
        return;
    }

    // No node exists after the specific node
    if(temp->next == NULL){
        printf("No node exists after this element.");
        return;
    }

    delnode = temp->next;
    temp->next = delnode->next;

    free(delnode);
}

void reverse(){
    struct node *prev, *currentNode, *nextNode;
    prev = NULL;
    currentNode =  head;
    while(currentNode != NULL){
        nextNode = currentNode->next;
        currentNode->next = prev;
        prev = currentNode;
        currentNode = nextNode;
    }
    head = prev;
}

// void reverse(){
//     struct node *prev, *currentNode, *nextNode;
//     prev = NULL;
//     currentNode = head;
//     while(currentNode != NULL){
//         nextNode = currentNode->next;
//         currentNode->next = prev;
//         prev = currentNode;
//         currentNode = nextNode;
//     }
//     head = prev;
// }

int main(){
    createList();
    display();
    // countNodes();
    // search();
    // insertAtBeginning();
    // insertAtEnd();
    // insertAtPosition();
    // insertAfterGivenPosition();
    // insertBeforeGivenPosition();
    // insertAtSpecificPosition();
    // deleteFromBeginning();
    // deleteFromEnd();
    // deleteFromGivenPosition();
    // deleteBeforeGivenPosition();
    // deleteAfterGivenPosition();
    // deleteSpecificElement();
    // deleteBeforeSpecificNode();
    // deleteAfterSpecificNode();
    reverse();
    display();
    // createAlternateList();

    return 0;
}