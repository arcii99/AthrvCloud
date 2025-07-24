//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// A function to compare two numbers used in qsort
int compare(const void *x, const void *y) {
    return *(int*)x - *(int*)y;
}

// Function that calculates the maximum score
int maxScore(int *arr, int size, int minDiff) {
    int max = 0;
    int currScore = 0;
    int i, j;

    // sort the array in ascending order
    qsort(arr, size, sizeof(int), compare);

    // loop through the array to find the maximum score
    for (i = 0; i < size-1; i++) {
        // check if the difference between the current value and the next value is at least minDiff
        if (arr[i+1] - arr[i] >= minDiff) {
            currScore = 1; // initialize the current score to 1
            j = i + 1; // set j to i + 1

            // loop through the rest of the array to find the maximum score
            while (j < size && arr[j] - arr[i] < minDiff) {
                j++; // move j to the next element
            }

            // add the number of elements that satisfy the condition to the current score
            currScore += j - i - 1;

            // update the maximum score if the current score is higher
            if (currScore > max) {
                max = currScore;
            }
        }
    }

    return max;
}

int main() {
    int arr[] = {7, 8, 11, 17, 10, 6, 20};
    int minDiff = 5;
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("The array is: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nThe minimum difference is %d", minDiff);

    int max = maxScore(arr, size, minDiff);

    printf("\nThe maximum score is %d", max);

    return 0;
}