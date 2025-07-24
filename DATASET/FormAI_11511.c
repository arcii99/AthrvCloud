//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the shape-shifting function */
void shape_shift(int* arr, int size) {
    int i, j, temp;
    for(i = 0; i < size; i++) {
        for(j = i+1; j < size; j++) {
            if(arr[i] > arr[j]) {
                /* Shape-shift the elements */
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

/* Define the bucket sort function */
void bucket_sort(int* arr, int size, int range) {
    /* Create an array of lists */
    int* list = (int*) malloc(range*sizeof(int));
    memset(list, 0, range*sizeof(int));
    
    int i, j;
    for(i = 0; i < size; i++) {
        /* Add element to its corresponding list */
        list[arr[i]]++;
    }
    
    int index = 0;
    for(i = 0; i < range; i++) {
        /* Iterate over each list and sort them */
        if(list[i] > 0) {
            int* sublist = (int*) malloc(list[i]*sizeof(int));
            for(j = 0; j < list[i]; j++) {
                sublist[j] = i;
            }
            /* Shape-shift the sublist */
            shape_shift(sublist, list[i]);
            /* Add the sorted sublist elements to the array */
            for(j = 0; j < list[i]; j++) {
                arr[index++] = sublist[j];
            }
            free(sublist);
        }
    }
    free(list);
}

/* Main function */
int main() {
    int arr[] = {9, 4, 2, 7, 10, 8, 1, 5, 6, 3};
    int size = sizeof(arr)/sizeof(int);
    printf("Unsorted array: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    /* Perform bucket sort on the array */
    bucket_sort(arr, size, 11);
    printf("Sorted array: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}