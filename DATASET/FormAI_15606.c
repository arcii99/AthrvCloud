//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void bucketSort(int arr[], int size) {
    int i, j;
    int count[SIZE] = {0};
    for (i = 0; i < size; i++) {
        count[arr[i]]++;
    }
    for (i = 0, j = 0; i < SIZE; i++) {
        while (count[i]-- > 0) {
            arr[j++] = i;
        }
    }
}

int main() {
    srand(time(NULL));
    printf("Get ready to see the most unique Bucket Sort Implementation!\n");
    int arr[SIZE];
    printf("First, let's generate some random numbers...\n");
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % SIZE;
        printf("%d ", arr[i]);
    }
    printf("\nNow, let's sort them using our own implementation of Bucket Sort!\n");
    bucketSort(arr, SIZE);
    printf("Tadaaa! The sorted array is:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nHope you're as surprised as I am with how well that worked!\n");
    return 0;
}