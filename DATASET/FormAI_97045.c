//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

void bucketSort(int arr[], int n){
    int i, j;
    int count[n];
    for(i = 0; i < n; i++){
        count[i] = 0;
    }
    for(i = 0; i < n; i++){
        ++count[arr[i]]; //increasing count for an element in arr
    }
    for(i = 0, j = 0; i < n; i++){
        while(count[i] > 0){
            arr[j++] = i; //copying an element into sorted array (arr)
            count[i]--;
        }
    }
}

int main(){
    int i, n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: ");
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("\nUnsorted array: ");
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    bucketSort(arr, n);
    printf("\nSorted array: ");
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}