//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000000

int main() {
    int* arr = malloc(sizeof(int) * SIZE);
    if (arr == NULL) {
        perror("Memory allocation error");
        exit(1);
    }

    memset(arr, 0, SIZE * sizeof(int));

    for (int i = 0; i < SIZE; i++) {
        arr[i] = i * 2;
    }

    long long sum = 0;

    for (int i = 0; i < SIZE; i++) {
        sum += arr[i];
    }

    printf("Sum of even numbers from 0 to %d: %lld\n", SIZE * 2, sum);

    free(arr);

    return 0;
}