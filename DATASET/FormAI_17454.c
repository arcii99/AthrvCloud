//FormAI DATASET v1.0 Category: Sorting ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int arr[1000], n, i, j, temp;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    srand(time(NULL)); //Initializing random seed

    printf("\nOriginal Array:\n");

    for(i=0; i<n; i++) {
        arr[i] = rand() % 1001; //Generating random integers between 0 and 1000
        printf("%d ", arr[i]);
    }

    printf("\n\n");

    //Performing Bubble Sort
    for(i=0; i<n-1; i++) {
        for(j=0; j<n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("Sorted Array:\n");

    for(i=0; i<n; i++)
        printf("%d ", arr[i]);

    return 0;

}