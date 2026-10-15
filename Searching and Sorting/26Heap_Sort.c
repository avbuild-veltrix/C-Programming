// Max-Heap

// #include<stdio.h>

// void swap(int *a, int *b){
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// void heapify(int arr[], int n, int i){
//     int largest = i;
//     int left = 2*i + 1;
//     int right = 2*i + 2;

//     if(left < n && arr[left] > arr[largest]){
//         largest = left;
//     }

//     if(right < n && arr[right] > arr[largest]){
//         largest = right;
//     }

//     if(largest != i){
//         swap(&arr[i], &arr[largest]);

//         heapify(arr,n , largest);
//     }
// }

// void heapSort(int arr[], int n){
//     for(int i = n/2 - 1; i >= 0; i--){
//         heapify(arr, n, i);
//     }

//     for(int i = n-1; i > 0; i--){
//         swap(&arr[0], &arr[i]);

//         heapify(arr, i, 0);
//     }
// }

// int main(){
//     int arr[] = {4,2,6,9,5};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     heapSort(arr, n);
//     printf("Sorted array : ");
//     for(int i = 0; i < n; i++){
//         printf("%d ", arr[i]);
//     }
//     return 0;
// }

// Min-Heap

#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i)
{
    int smallest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Check left child
    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    // Check right child
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    // If parent is not smallest
    if (smallest != i)
    {
        swap(&arr[i], &arr[smallest]);

        heapify(arr, n, smallest);
    }
}

void heapSort(int arr[], int n)
{
    // Build Min Heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    // Move smallest to the end
    for (int i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);

        heapify(arr, i, 0);
    }
}

int main()
{
    int arr[] = {5, 3, 8, 4, 1};
    int n = 5;

    heapSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}