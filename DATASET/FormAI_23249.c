//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMS 1000000

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main() {
    srand(time(NULL)); // seed RNG with current time
    int nums[MAX_NUMS]; // create array of ints
    printf("Unsorted Array:\n");
    for (int i = 0; i < MAX_NUMS; i++) {
         nums[i] = rand() % MAX_NUMS; // add random int to array
         printf("%d ", nums[i]); // print unsorted array for reference
    }
    printf("\nSorting Array...\n");
    bubble_sort(nums, MAX_NUMS); // sort array using bubble sort
    printf("Sorted Array:\n");
    for (int i = 0; i < MAX_NUMS; i++) {
        printf("%d ", nums[i]); // print sorted array
    }
    printf("\n");
    return 0;
}