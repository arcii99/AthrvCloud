//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000000 // number of elements in array

// function to generate random integers in range [min, max]
int *generate_random_integers(int min, int max, int n) {
    int *arr = malloc(n * sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = (rand() % (max - min + 1)) + min;
    }
    return arr;
}

// function to find max element in array
int find_max(int *arr, int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int *arr = generate_random_integers(0, 10000, N);
    int max = find_max(arr, N);
    printf("Max element is: %d\n", max);
    free(arr);
    return 0;
}