//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: Donald Knuth
// Bucket Sort Implementation in C
// By Donald E. Knuth

#include <stdio.h>
#include <stdlib.h>

#define N 100001
#define B 1001

int main() {
    int i, j;
    int A[N], C[B];

    // Initialize A with random values
    for (i = 0; i < N; i++)
        A[i] = rand() % B;

    // Initialize C with zeros
    for (i = 0; i < B; i++)
        C[i] = 0;

    // Count the occurrences of each value in A
    for (i = 0; i < N; i++)
        C[A[i]]++;

    // Sort the values in A using the counts in C
    for (i = 0, j = 0; j < B; j++) {
        while (C[j]--)
            A[i++] = j;
    }

    // Print the sorted array A
    for (i = 0; i < N; i++)
        printf("%d ", A[i]);

    return 0;
}