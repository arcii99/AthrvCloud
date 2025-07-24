//FormAI DATASET v1.0 Category: Sorting ; Style: introspective
#include <stdio.h>

void bubbleSort(int arr[], int n){
    int i, j, temp;
    for(i=0; i<n-1; i++){
        for(j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int i, n, arr[50];
    printf("Enter size of array: ");
    scanf("%d", &n);
    printf("Enter array elements: ");
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Before Sorting: ");
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    bubbleSort(arr, n);
    printf("\nAfter Sorting: ");
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}