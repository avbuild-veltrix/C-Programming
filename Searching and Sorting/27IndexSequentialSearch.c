#include<stdio.h>
#include<stdlib.h>

int indexSequentialSearch(int array[], int n, int target, int blockSize){
    int block = -1;

    for(int i = 0; i < n; i += blockSize){
        if(target >= array[i]){
            block = i;
        }else break;
    }

    if(block != -1){
        int end = block + blockSize;
        if(end > n){
            end = n;
        }
        for(int i = block; i < end; i++){
            if(array[i] == target){
                return i;
            }
        }
    }

    return -1;
}

int main(){
    int array[] = {10, 20, 30, 31, 40, 45, 60, 76, 79, 80, 84, 90};
    int n = sizeof(array)/sizeof(array[0]);
    int blockSize = 3;
    int target = 60;

    int result = indexSequentialSearch(array, n, target, blockSize);
    if(result != -1){
        printf("Element is present at %d\n",result);
    }else{
        printf("Element is not found.");
    }
    return 0;
}