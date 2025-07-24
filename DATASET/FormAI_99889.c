//FormAI DATASET v1.0 Category: Sorting ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int num[], int n){
    int i, key, j;
    for(i = 1; i < n; i++){
        key = num[i];
        j = i - 1;
        while(j >= 0 && num[j] > key){
            num[j+1] = num[j];
            j--;
        }
        num[j+1] = key;
    }
}

void printArray(int num[], int n){
    int i;
    for(i = 0; i < n; i++)
        printf("%d ", num[i]);
    printf("\n");
}

int main(){
    int arr[] = {7,5,8,3,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Unsorted array: \n");
    printArray(arr, n);

    insertion_sort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}