#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 20

char stack[MAX];
int top = -1;

void push(char item)
{
    if(top == MAX - 1){
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = item;
}

char pop(){
    if(top == -1){
        printf("Stack Underflow\n");
        return;
    }
    char item = stack[top];
    top--;
    return item;
}

// int main(){
//     char str[MAX];
//     int length;

//     printf("Enter the string : ");
//     fgets(str, MAX, stdin);

//     str[strcspn(str, "\n")] = '\0';

//     length = strlen(str);

//     for(int i = 0; i < length; i++){
//         push(str[i]);
//     }
//     printf("Reversed string : ");
//     while(top != -1){
//         printf("%c", pop());
//     }
// }

int main(){
    char str[MAX];
    int i;

    printf("Enter the string : ");
    fgets(str, MAX, stdin);

    for(int i = 0; i < strlen(str); i++){
        push(str[i]);
    }

    printf("Reversed string is : ");

    while(top != -1){
        printf("%c", pop());
    }

    return 0;
}