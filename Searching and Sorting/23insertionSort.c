// Iterative Program for Insertion Sort.

// #include<stdio.h>
// #include<stdlib.h>

// void insertionSort(int a[], int n) {

//     for(int i = 1; i < n; i++) {
//         int key = a[i];
//         int j = i - 1;
//         // Shift elements greater than key
//         while(j >= 0 && a[j] > key) {

//             a[j + 1] = a[j];
//             j--;
//         }
//         // Insert key at correct position
//         a[j + 1] = key;
//     }
// }

// int main() {
//     int a[] = { 4,3,7,9,1,6,2,8,5,0};
//     int n = sizeof(a) / sizeof(a[0]);
//     insertionSort(a, n);
//     printf("The array after sorting will be: ");
//     for(int i = 0; i < n; i++) {
//         printf("%d ", a[i]);
//     }
//     return 0;
// }

// Recursive Program for Insertion Sort.

#include<stdio.h>
#include<stdlib.h>

void insertionSort(int a[], int n){
    if(n <= 1){
        return;
    }

    insertionSort(a, n-1);

    int key = a[n-1];
    int j = n-2;

    while(j >= 0 && key < a[j]){
        a[j + 1] = a[j];
        j--;
    }

    a[j+1] = key;
}

int main(){
    int a[] = {3,6,2,7,9,8,1,5,4,0};
    int n = sizeof(a)/sizeof(a[0]);

    insertionSort(a, n);

    printf("Array after sorting will look like : ");

    for(int i = 0; i < n; i++){
        printf("%d", a[i]);
        printf(" ");
    }
}