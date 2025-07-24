//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

void bucketSort(float arr[], int n) {
    //Create empty buckets
    int i, j;
    int count[n];
    for(i=0; i < n; i++)
        count[i] = 0;

    //Fill the buckets
    for(i=0; i < n; i++)
        ++count[(int)(arr[i]*10)];

    //Sort using an insertion sort
    for(i=0; i < n; i++)
        for(j=0; j < count[i]; j++)
            arr[i+j] = (float)i/10;

}

int main() {
    int n,i;
    printf("Enter the number of elements in the array\n");
    scanf("%d",&n);
    float * arr = (float *) malloc(n * sizeof(float));
    printf("Enter the elements of the array\n");
    for(i=0;i<n;i++)
        scanf("%f",&arr[i]);
    printf("Before sorting...\n");
    for(i=0;i<n;i++)
        printf("%.2f ",arr[i]);
    printf("\n");

    //Sort the array
    bucketSort(arr, n);

    printf("After sorting...\n");
    for(i=0;i<n;i++)
        printf("%.2f ",arr[i]);
    printf("\n");
    return 0;
}