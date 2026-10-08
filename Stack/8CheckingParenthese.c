#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow!\n");
        return;
    }

    stack[++top] = ch;
}

char pop()
{
    if (top == -1)
    {
        return '\0';
    }

    return stack[top--];
}

int isMatchingPair(char opening, char closing)
{
    if (opening == '(' && closing == ')')
        return 1;

    if (opening == '[' && closing == ']')
        return 1;

    if (opening == '{' && closing == '}')
        return 1;

    return 0;
}

int isBalanced(char expression[])
{
    int i;
    char ch;
    char opening;

    for (i = 0; expression[i] != '\0'; i++)
    {
        ch = expression[i];

        // Opening bracket
        if (ch == '(' || ch == '[' || ch == '{')
        {
            push(ch);
        }

        // Closing bracket
        else if (ch == ')' || ch == ']' || ch == '}')
        {
            // No opening bracket available
            if (top == -1)
            {
                return 0;
            }

            opening = pop();

            // Wrong type of bracket
            if (!isMatchingPair(opening, ch))
            {
                return 0;
            }
        }
    }

    // No unmatched opening brackets
    if (top == -1)
        return 1;

    return 0;
}

int main()
{
    char expression[MAX];

    printf("Enter an expression: ");
    fgets(expression, MAX, stdin);

    if (isBalanced(expression))
        printf("Balanced Parentheses\n");
    else
        printf("Not Balanced Parentheses\n");

    return 0;
}