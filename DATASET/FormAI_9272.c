//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: portable
#include <stdio.h>

void knapsack(int n, float weight[], float benefit[], float capacity) {
    float x[20], totalBenefit = 0;
    int i, j, u;

    u = capacity;

    for (i = 0; i < n; i++) {
        x[i] = 0.0;
    }

    for (i = 0; i < n; i++) {
        if (weight[i] > u) {
            break;
        } else {
            x[i] = 1.0;
            totalBenefit += benefit[i];
            u -= weight[i];
        }
    }

    if (i < n) {
        x[i] = u / weight[i];
    }

    totalBenefit += x[i] * benefit[i];

    printf("Items selected: ");

    for (i = 0; i < n; i++) {
        if (x[i] == 1) {
            printf("%d ", i + 1);
        } else if (x[i] > 0 && x[i] < 1) {
            printf("%d(%.2f) ", i + 1, x[i]);
        }
    }

    printf("\nTotal benefit: %.2f\n", totalBenefit);
}

int main() {
    float weight[] = {12, 7, 11, 8, 9};
    float benefit[] = {24, 13, 23, 15, 16};
    float capacity = 26;
    int n = 5;

    knapsack(n, weight, benefit, capacity);

    return 0;
}