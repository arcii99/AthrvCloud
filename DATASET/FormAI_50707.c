//FormAI DATASET v1.0 Category: Sorting ; Style: medieval
#include <stdio.h>

void bubble_sort(int arr[], int len) {
    int i, j, temp;
    for (i = 0; i < len-1; i++) {
        // In this iteration of the outer loop, we're sorting the i-th element from the end
        for (j = 0; j < len-i-1; j++) {
            // In this iteration of the inner loop, we're comparing arr[j] and arr[j+1] 
            if (arr[j] > arr[j+1]) {
                // If they're not in the correct order, swap them
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int unsorted_arr[] = {7, 4, 8, 2, 1, 9, 3, 5, 6};
    int len = sizeof(unsorted_arr) / sizeof(int);

    printf("Unsorted List: ");
    for (int i=0; i < len; i++) {
        printf("%d ", unsorted_arr[i]);
    }
    printf("\n");

    bubble_sort(unsorted_arr, len);
    
    printf("Sorted List: ");
    for (int i = 0; i < len; i++) {
        printf("%d ", unsorted_arr[i]);
    }
    printf("\n");

    return 0;
}