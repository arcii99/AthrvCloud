//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

int findMax(int arr[], int n){
    int max = arr[0];
    for (int i = 1; i < n; i++){
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

void bucketSort(int arr[], int n){
    int max = findMax(arr, n);
    int bucket[max + 1];

    for (int i = 0; i <= max; i++)
        bucket[i] = 0;

    for (int i = 0; i < n; i++)
        bucket[arr[i]]++;

    for (int i = 0, j = 0; i <= max; i++){
        while (bucket[i] > 0){
            arr[j++] = i;
            bucket[i]--;
        }
    }
}

int main(){
    int arr[] = {1, 4, 1, 2, 7, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, n);

    printf("After sorting: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}