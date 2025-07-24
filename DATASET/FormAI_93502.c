//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 10
#define BUCKET_SIZE 10

void bucket_sort(int arr[], int n)
{
    int i, j;
    int buckets[BUCKET_SIZE];

    memset(buckets, 0, sizeof(buckets));

    for (i = 0; i < n; i++) {
        ++buckets[arr[i]];
    }

    for (i = 0, j = 0; i < BUCKET_SIZE; i++) {
        while ((buckets[i]--) > 0) {
            arr[j++] = i;
        }
    }
}

int main()
{
    int arr[ARRAY_SIZE] = {10, 8, 7, 5, 3, 2, 6, 1, 4, 9};
    int i;

    printf("Before bucket sort: ");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucket_sort(arr, ARRAY_SIZE);

    printf("After bucket sort: ");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}