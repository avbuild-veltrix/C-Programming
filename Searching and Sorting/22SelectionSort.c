// Iterative program for Selection sort

// #include<stdio.h>
// #include<stdlib.h>

// void selectionSort(int a[], int n){
//     for(int i = 0; i < n; i++){
//         int min = i;
//         for(int j = i + 1; j < n; j++){
//             if(a[j] < a[min]){
//                 min = j;
//             }
//         }
//         int temp = a[i];
//         a[i] = a[min];
//         a[min] = temp;
//     }
// }

// int main(){
//     int a[] = { 4,3,7,9,1,6,2,8,5,0};
//     int n = sizeof(a)/sizeof(a[0]);
//     selectionSort(a, n);
//     printf("The array after sorting will look like : ");
//     for(int i = 0; i < n; i++){
//         printf("%d", a[i]);
//         printf(" ");
//     }
//     return 0;
// }

// Recursive Program for Selection Sort.

#include<stdio.h>
#include<stdlib.h>

void selectionSort(int a[], int n, int index){
    if(index == n-1){
        return;
    }
    int min = index;
    for(int i = index + 1; i < n; i++){
        if(a[min] > a[i]){
            min = i;
        }
    }
    
    int temp = a[index];
    a[index] = a[min];
    a[min] = temp;
    
    selectionSort(a, n, index+1);

}

int main(){
    int a[] = { 4,3,7,9,1,6,2,8,5,0};
    int n = sizeof(a)/sizeof(a[0]);
    selectionSort(a, n, 0);
    printf("The array after sorting will look like : ");
    for(int i = 0; i < n; i++){
        printf("%d", a[i]);
        printf(" ");
    }
    return 0;
}