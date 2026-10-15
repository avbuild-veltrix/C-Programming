#include<stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++){
        if(pivot > arr[j]){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1],& arr[high]);
    return i + 1;
}

void Quick_Sort(int arr[], int low, int high){
    if(low < high){
        int pivotIndex = partition(arr, low ,high);

        Quick_Sort(arr, low, pivotIndex - 1);
        Quick_Sort(arr, pivotIndex + 1, high);
    }
}

int main(){
    int arr[] = {6,3,8,1,7,4,2,5,9,0};
    int n = sizeof(arr)/sizeof(arr[0]);

    Quick_Sort(arr, 0 , n);
    printf("The result atfer sorting using Quick Sort is : ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}

// #include <stdio.h>

// void swap(int *a, int *b)
// {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// int partition(int a[], int low, int high)
// {
//     int pivot = a[high];
//     int i = low - 1;

//     for (int j = low; j < high; j++)
//     {
//         if (a[j] < pivot)
//         {
//             i++;
//             swap(&a[i], &a[j]);
//         }
//     }

//     swap(&a[i + 1], &a[high]);

//     return i + 1;
// }

// void quickSort(int a[], int low, int high)
// {
//     if (low < high)
//     {
//         int pivotIndex = partition(a, low, high);

//         quickSort(a, low, pivotIndex - 1);
//         quickSort(a, pivotIndex + 1, high);
//     }
// }

// int main()
// {
//     int arr[] = {6,3,8,1,7,4,2,5,9,0};
//     int n = sizeof(arr)/sizeof(arr[0]);

//     quickSort(arr, 0, n - 1);

//     for (int i = 0; i < n; i++)
//     {
//         printf("%d ", arr[i]);
//     }

//     return 0;
// }