#include<stdio.h>

void merge(int a[], int low, int mid , int high){
    int i = low; int j = mid + 1;
    int k = 0;

    int temp[high - low + 1];

    while(i <= mid && j <= high){
        if(a[i] <= a[j]){
            temp[k] = a[i];
            i++;
        }else{
            temp[k] = a[j];
            j++;
        }
        k++;
    }

    while(i <= mid){
        temp[k] = a[i];
        i++;
        k++;
    }

    while(j <= high){
        temp[k] = a[j];
        k++;
        j++;
    }

    for(i = low, k = 0; i <= high; i++, k++){
        a[i] = temp[k];
    }
}

void merge_sort(int a[], int low, int high){
    if(low < high){
        int mid = low + (high - low)/2;

        merge_sort(a, low, mid);

        merge_sort(a, mid + 1, high);

        merge(a, low, mid, high);
    }
}

int main(){
    int a[] = { 5,7,2,8,1,0,3,9,4,6};

    int n = sizeof(a)/sizeof(a[0]);

    merge_sort(a, 0, n-1);

    printf("The array after sorting will look like : ");
    for(int i = 0; i < n; i++){
        printf("%d", a[i]);
        printf(" ");
    }

    return 0;

}

// #include <stdio.h>

// void merge(int a[], int low, int mid, int high) {

//     int i = low;
//     int j = mid + 1;
//     int k = 0;

//     int temp[high - low + 1];

//     // Compare elements of both halves
//     while(i <= mid && j <= high) {

//         if(a[i] <= a[j]) {
//             temp[k] = a[i];
//             i++;
//         }
//         else {
//             temp[k] = a[j];
//             j++;
//         }

//         k++;
//     }

//     // Copy remaining elements from left half
//     while(i <= mid) {
//         temp[k] = a[i];
//         i++;
//         k++;
//     }

//     // Copy remaining elements from right half
//     while(j <= high) {
//         temp[k] = a[j];
//         j++;
//         k++;
//     }

//     // Copy sorted elements back to original array
//     for(i = low, k = 0; i <= high; i++, k++) {
//         a[i] = temp[k];
//     }
// }

// void mergeSort(int a[], int low, int high) {

//     // Base case
//     if(low < high) {

//         int mid = (low + high) / 2;

//         // Sort left half
//         mergeSort(a, low, mid);

//         // Sort right half
//         mergeSort(a, mid + 1, high);

//         // Merge both sorted halves
//         merge(a, low, mid, high);
//     }
// }

// int main() {

//     int a[] = {8, 3, 5, 4, 7, 6, 1, 2};

//     int n = sizeof(a) / sizeof(a[0]);

//     mergeSort(a, 0, n - 1);

//     printf("The array after sorting will be: ");

//     for(int i = 0; i < n; i++) {
//         printf("%d ", a[i]);
//     }

//     return 0;
// }