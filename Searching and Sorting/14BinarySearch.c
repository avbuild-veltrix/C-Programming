// Using Iterative function.

// #include<stdio.h>
// int BinarySearch(int arr[], int target, int high){
//     int low = 0;
//     while(low <= high){
//         int mid = low + (high - low) / 2;
//         if(arr[mid] < target){
//             low = mid + 1;
//         }else if(arr[mid] > target){
//             high = mid - 1;
//         }else{
//             return mid;
//         }
//     }
//     return -1;
// }
// int main(){
//     int n, a[100], result;
//     int target;
//     printf("Enter the number of elements: ");
//     scanf("%d", &n);
//     printf("Enter the elements in sorted order:\n");
//     for(int i = 0; i < n; i++){
//         scanf("%d", &a[i]);
//     }
//     printf("Enter the target: ");
//     scanf("%d", &target);
//     result = BinarySearch(a, target, n - 1);
//     if(result != -1){
//         printf("Target is present at index %d\n", result);
//     }else{
//         printf("Element is not present\n");
//     }
//     return 0;
// }

// Using Recursive Method

// #include<stdio.h>

// int BinarySearch(int a[], int target, int low , int high){
//     if(low > high){
//         return -1;
//     }

//     int mid = low + (high - low)/2;

//     if(a[mid] == target){
//         return mid;
//     }

//     if(a[mid] < target){
//         return BinarySearch(a, target, mid+1, high);
//     }

//     if(a[mid] > target){
//         return BinarySearch(a, target, low, mid-1);
//     }
// }

// int main(){
//     int n, a[100], result;
//     int target;
//     printf("Enter the number of elements: ");
//     scanf("%d", &n);
//     printf("Enter the elements in sorted order:\n");
//     for(int i = 0; i < n; i++){
//         scanf("%d", &a[i]);
//     }
//     printf("Enter the target: ");
//     scanf("%d", &target);
//     result = BinarySearch(a, target, 0, n - 1);
//     if(result != -1){
//         printf("Target is present at index %d\n", result);
//     }else{
//         printf("Element is not present\n");
//     }
//     return 0;
// }

#include <stdio.h>

int BinarySearch(int arr[], int target, int low, int high) {

    // Base case: element not found
    if (low > high) {
        return -1;
    }

    int mid = low + (high - low) / 2;

    // Target found
    if (arr[mid] == target) {
        return mid;
    }

    // Search in right half
    if (arr[mid] < target) {
        return BinarySearch(arr, target, mid + 1, high);
    }

    // Search in left half
    return BinarySearch(arr, target, low, mid - 1);
}

int main() {

    int n, a[100], result;
    int target = 7;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter elements in sorted order:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    result = BinarySearch(a, target, 0, n - 1);

    if (result != -1) {
        printf("Target is present at index %d\n", result);
    } else {
        printf("Element is not present\n");
    }

    return 0;
}