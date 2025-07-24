//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: curious
#include<stdio.h>

void bucketSort(int A[], int n) {
    // Creating Buckets of size 10 and initializing each element with 0
    int bucket[10] = {0};
 
    // Counting number of times each element occurs and storing it in corresponding bucket
    for (int i=0; i<n; i++)
        bucket[A[i]]++;

    // Sorting the elements in each bucket
    for (int i=0, k=0; i<10; i++) {
        for (int j=0; j<bucket[i]; j++, k++) {
            A[k] = i;
        }
    }
}

int main() {

    int arr[10]; // Array to be sorted

    printf("\nEnter 10 integers to be sorted using Bucket Sort: \n");
    for(int i=0;i<10;i++){
        scanf("%d",&arr[i]); // Taking input from user
    }

    printf("\nBefore sorting: ");
    for(int i=0;i<10;i++){
        printf("%d ",arr[i]); // Printing the array before sorting
    }

    bucketSort(arr,10); // Calling Bucket Sort function

    printf("\nAfter sorting: ");
    for(int i=0;i<10;i++){
        printf("%d ",arr[i]); // Printing the array after sorting
    }

    return 0;
}