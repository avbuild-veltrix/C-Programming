// Design a method for two stacks within a single linear array so that neither stack overflow untill all the memory is used.

#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

int arr[SIZE];
int top1 = -1;
int top2 = SIZE;

void push_stack1(int value){
    if(top1 +1 == top2){
        printf("\nStack Overflow! Array is completely full.\n");
        return;
    }
    top1++;
    arr[top1] = value;
}

void pop_stack1(){
    if(top1 == -1){
        printf("Stack Underflow\n");
        return;
    }
    printf("%d is popped out.\n", arr[top1]);
    top1--;
}

void push_stack2(int value){
    if(top1 + 1 == top2){
        printf("\nStack Overflow! Array is completely full.\n");
        return;
    }
    top2--;
    arr[top2] = value;
}

void pop_stack2(){
    if(top2 == SIZE){
        printf("Stack Underflow\n");
        return;
    }
    printf("%d is popped out.\n", arr[top2]);
    top2++;
}

void display_stack1(){
    if(top1 == -1){
        printf("Stack UnderFlow");
        return;
    }
    printf("Stack's element is : ");
    for(int i = top1; i > -1; i--){
        printf("%d", arr[i]);
        printf(" ");
    }
}

void display_stack2(){
    if(top2 == SIZE){
        printf("Stack UnderFlow");
        return;
    }
    printf("Stack's element is : ");
    for(int i = top2; i < SIZE; i++){
        printf("%d", arr[i]);
        printf(" ");
    }
}

void display_array()
{
    printf("\nComplete Array:\n");

    for(int i = 0; i < SIZE; i++)
    {
        if(i <= top1)
        {
            printf("[%d:S1] ", arr[i]);
        }
        else if(i >= top2)
        {
            printf("[%d:S2] ", arr[i]);
        }
        else
        {
            printf("[--] ");
        }
    }

    printf("\n");
}

int main()
{
    int choice;
    int value;

    do
    {
        printf("\n\n====================================");
        printf("\n       TWO STACKS IN ONE ARRAY");
        printf("\n====================================");

        printf("\n1. Push into Stack 1");
        printf("\n2. Pop from Stack 1");
        printf("\n3. Display Stack 1");

        printf("\n\n4. Push into Stack 2");
        printf("\n5. Pop from Stack 2");
        printf("\n6. Display Stack 2");

        printf("\n\n7. Display Complete Array");
        printf("\n8. Exit");

        printf("\n====================================");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);


        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);

                push_stack1(value);
                break;


            case 2:
                pop_stack1();
                break;


            case 3:
                display_stack1();
                break;


            case 4:
                printf("Enter value: ");
                scanf("%d", &value);

                push_stack2(value);
                break;


            case 5:
                pop_stack2();
                break;


            case 6:
                display_stack2();
                break;


            case 7:
                display_array();
                break;


            case 8:
                printf("\nProgram terminated.\n");
                break;


            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while(choice != 8);


    return 0;
}