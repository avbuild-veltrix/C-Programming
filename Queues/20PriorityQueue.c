#include <stdio.h>

#define MAX 10

struct element
{
    int data;
    int priority;
};

struct element pq[MAX];

int size = 0;


// 1. Insertion
void insertion()
{
    int value, priority;

    if(size == MAX)
    {
        printf("Priority Queue is full!\n");
        return;
    }

    printf("Enter the value: ");
    scanf("%d", &value);

    printf("Enter the priority: ");
    scanf("%d", &priority);

    pq[size].data = value;
    pq[size].priority = priority;

    size++;

    printf("%d inserted successfully.\n", value);
}


// 2. Deletion
void deletion()
{
    int i;
    int highest;

    if(size == 0)
    {
        printf("Priority Queue is empty!\n");
        return;
    }

    // Assume first element has highest priority
    highest = 0;

    // Find element with highest priority
    for(i = 1; i < size; i++)
    {
        if(pq[i].priority > pq[highest].priority)
        {
            highest = i;
        }
    }

    printf("%d with priority %d is deleted.\n",
           pq[highest].data,
           pq[highest].priority);

    // Shift elements to fill the empty position
    for(i = highest; i < size - 1; i++)
    {
        pq[i] = pq[i + 1];
    }

    size--;
}


// 3. Peek
void peek()
{
    int i;
    int highest;

    if(size == 0)
    {
        printf("Priority Queue is empty!\n");
        return;
    }

    highest = 0;

    // Find highest priority element
    for(i = 1; i < size; i++)
    {
        if(pq[i].priority > pq[highest].priority)
        {
            highest = i;
        }
    }

    printf("Element with highest priority: %d\n",
           pq[highest].data);

    printf("Priority: %d\n",
           pq[highest].priority);
}


// 4. Display
void display()
{
    int i;

    if(size == 0)
    {
        printf("Priority Queue is empty!\n");
        return;
    }

    printf("\nPriority Queue:\n");

    printf("Data\tPriority\n");

    for(i = 0; i < size; i++)
    {
        printf("%d\t%d\n",
               pq[i].data,
               pq[i].priority);
    }
}


// 5. Is Empty
void isEmpty()
{
    if(size == 0)
    {
        printf("Priority Queue is empty.\n");
    }
    else
    {
        printf("Priority Queue is not empty.\n");
    }
}


// Main function
int main()
{
    int choice;

    while(1)
    {
        printf("\n---------- PRIORITY QUEUE ----------\n");

        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Is Empty\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                insertion();
                break;

            case 2:
                deletion();
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
                printf("Program terminated.\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}