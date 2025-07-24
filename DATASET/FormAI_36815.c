//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

int n, m, coins[MAX_N];

int cmp(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main(void) {
    // Read input
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &coins[i]);
    }

    // Sort coins in decreasing order
    qsort(coins, n, sizeof(int), cmp);

    // Initialize variables
    int sum = 0;
    int num_coins = 0;
    int i = 0;

    // Greedy algorithm
    while (sum < m) {
        while (i < n && sum + coins[i] <= m) {
            sum += coins[i];
            num_coins += 1;
        }
        i += 1;
    }

    // Print result
    printf("%d\n", num_coins);

    return 0;
}