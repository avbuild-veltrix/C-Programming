// #include <stdio.h>
// #include <stdlib.h>

// #define MAX 100

// typedef struct {
//     int items[MAX];
//     int top;
// } Stack;

// void push(Stack *s, int disk)
// {
//     s->items[++s->top] = disk;
// }

// int pop(Stack *s)
// {
//     return s->items[s->top--];
// }

// int peek(Stack *s)
// {
//     if (s->top == -1)
//         return MAX;

//     return s->items[s->top];
// }

// void moveDisk(Stack *from, Stack *to, char fromRod, char toRod)
// {
//     int disk1 = peek(from);
//     int disk2 = peek(to);

//     if (disk1 == MAX) {
//         disk1 = pop(to);
//         push(from, disk1);

//         printf("Move disk %d from %c to %c\n",
//                disk1, toRod, fromRod);
//     }
//     else if (disk2 == MAX) {
//         disk2 = pop(from);
//         push(to, disk2);

//         printf("Move disk %d from %c to %c\n",
//                disk2, fromRod, toRod);
//     }
//     else if (disk1 < disk2) {
//         disk1 = pop(from);
//         push(to, disk1);

//         printf("Move disk %d from %c to %c\n",
//                disk1, fromRod, toRod);
//     }
//     else {
//         disk2 = pop(to);
//         push(from, disk2);

//         printf("Move disk %d from %c to %c\n",
//                disk2, toRod, fromRod);
//     }
// }

// int main()
// {
//     int n;

//     printf("Enter number of disks: ");
//     scanf("%d", &n);

//     Stack source, auxiliary, destination;

//     source.top = -1;
//     auxiliary.top = -1;
//     destination.top = -1;

//     // Put disks on source rod
//     for (int i = n; i >= 1; i--)
//         push(&source, i);

//     char s = 'A';
//     char a = 'B';
//     char d = 'C';

//     // For even number of disks, swap destination and auxiliary
//     if (n % 2 == 0) {
//         char temp = d;
//         d = a;
//         a = temp;
//     }

//     long long totalMoves = (1LL << n) - 1;

//     for (long long i = 1; i <= totalMoves; i++)
//     {
//         if (i % 3 == 1)
//             moveDisk(&source, &destination, s, d);

//         else if (i % 3 == 2)
//             moveDisk(&source, &auxiliary, s, a);

//         else
//             moveDisk(&auxiliary, &destination, a, d);
//     }

//     return 0;
// }

// #include <stdio.h>

// void towerOfHanoi(int n, char source, char auxiliary, char destination)
// {
//     // Base case
//     if (n == 1)
//     {
//         printf("Move disk 1 from %c to %c\n",
//                source, destination);
//         return;
//     }

//     // Step 1: Move n-1 disks from source to auxiliary
//     towerOfHanoi(n - 1, source, destination, auxiliary);

//     // Step 2: Move the largest disk to destination
//     printf("Move disk %d from %c to %c\n",
//            n, source, destination);

//     // Step 3: Move n-1 disks from auxiliary to destination
//     towerOfHanoi(n - 1, auxiliary, source, destination);
// }

// int main()
// {
//     int n;

//     printf("Enter number of disks: ");
//     scanf("%d", &n);

//     towerOfHanoi(n, 'A', 'B', 'C');

//     return 0;
// }

#include<stdio.h>

void towerOfHanoi(int n, char source, char auxiliary, char destination){
    if(n == 1){
        printf("Move disk %d from %c to %c \n", n, source, destination);
        return;
    }
    // Move n-1 disk from source to auxiliary using destination.
    towerOfHanoi(n-1, source, destination, auxiliary);

    //Move the largest disk to destination
    printf("Move disk %d from %c to %c\n", n, source, destination);

    //Move n-1 disks from auxiliary to destination.
    towerOfHanoi(n-1, auxiliary, source, destination);
}

int main(){
    int n;
    char source, auxiliary, destination;

    printf("Enter the number of disks : ");
    scanf("%d", &n);

    towerOfHanoi(n, 'A', 'B', 'C');

    return 0;
}