//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

int invasionProbability(int n, int A[], int B[]) {
    if (n == 0) {
        return 0;
    } else if (A[n-1] == B[n-1]) {
        return 1 + invasionProbability(n-1, A, B);
    } else {
        return invasionProbability(n-1, A, B);
    }
}

int main() {
    int n;
    printf("Enter the number of days to simulate: ");
    scanf("%d", &n);

    int *A = (int*)malloc(n * sizeof(int));
    int *B = (int*)malloc(n * sizeof(int));

    // Generate random probabilities
    for (int i = 0; i < n; i++) {
        A[i] = rand() % 100;
        B[i] = rand() % 100;
    }

    // Calculate invasion probability
    int invProb = invasionProbability(n, A, B);

    printf("The probability of an alien invasion in the next %d days is %d%%.\n", n, invProb*100/n);

    free(A);
    free(B);

    return 0;
}