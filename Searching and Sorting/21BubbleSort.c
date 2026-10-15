//Iterative method for bubble sort.

// #include<stdio.h>
// #include<stdlib.h>

// void bubbleSort(int a[], int n){
//     for(int i = 0; i < n - 1; i++){
//         for(int j = 0; j < n - i - 1; j++){
//             if(a[j] > a[j+1]){
//                 int temp = a[j];
//                 a[j] = a[j + 1];
//                 a[j + 1] = temp;
//             }
//         }
//     }
// }

// int main(){
//     int a[] = {3,2,6,5,8,4,9,1};
//     int n = sizeof(a)/sizeof(a[0]);
//     bubbleSort(a, n);
//     printf("The array after sorting will be : ");
//     for(int i = 0; i < n; i++){
//         printf("%d", a[i]);
//         printf(" ");
//     }
// }

// Recursive method for bubble sort.

#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int a[], int n){
    if(n == 1){
        return;
    }

    for(int i = 0; i < n - 1; i++){
        if(a[i] > a[i+1]){
            int temp = a[i+1];
            a[i+1] = a[i];
            a[i] = temp;
        }
    }

    bubbleSort(a, n-1);
}

int main(){
    int a[] = {3,2,7,6,5,8,4,9,1,0};
    int n = sizeof(a)/sizeof(a[0]);
    bubbleSort(a, n);
    printf("The array after sorting will be : ");
    for(int i = 0; i < n; i++){
        printf("%d", a[i]);
        printf(" ");
    }
}