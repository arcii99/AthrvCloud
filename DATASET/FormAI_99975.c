//FormAI DATASET v1.0 Category: Benchmarking ; Style: creative
#include <stdio.h>
#include <time.h>

int main(){
    int n, i, j, temp;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of array:\n");
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    clock_t t1, t2;
    t1 = clock();

    for(i=0; i<n-1; i++){
        for(j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    t2 = clock();
    double time_taken = (double)(t2 - t1) / CLOCKS_PER_SEC;

    printf("Array after sorting:\n");
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    printf("\nTime taken by Bubble Sort: %f seconds\n", time_taken);

    return 0;
}