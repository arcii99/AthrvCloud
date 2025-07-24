//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: automated
#include<stdio.h>
#include<stdlib.h>

void bucketSort(int arr[], int n, int maxVal) {
    int i, j;
    int count[maxVal + 1];
    
    for(i = 0; i <= maxVal; i++) {   //initialize the count array using 0
        count[i] = 0;
    }
    
    for(i = 0; i < n; i++) {   //increment the count of the element in the array
        count[arr[i]]++;
    }
    
    for(i = 0, j = 0; i <= maxVal; i++) {   //place the elements back into the array
        while(count[i] > 0) {
            arr[j++] = i;
            count[i]--;
        }
    }
}

int main() {
    int n, maxVal, i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if(i == 0 || arr[i] > maxVal) {   //check the maximum value of the array
            maxVal = arr[i];
        }
    }
    bucketSort(arr, n, maxVal);
    printf("\nThe sorted array is:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}