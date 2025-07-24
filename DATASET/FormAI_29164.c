//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: enthusiastic
#include <stdio.h>

int main() {
    printf("Welcome to the Greedy Algorithm example program!\n");
    int n, i, j;
    float x[20], y[20], w[20], d = 0.0, u;
    printf("Enter the number of objects: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter the weight and profit of object %d: ",i+1);
        scanf("%f%f", &w[i], &x[i]);
        y[i] = x[i]/w[i];
    }
    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) {
            if (y[i] < y[j]) {
                u = w[i];
                w[i] = w[j];
                w[j] = u;
                u = x[i];
                x[i] = x[j];
                x[j] = u;
                u = y[i];
                y[i] = y[j];
                y[j] = u;
            }
        }
    }
    float c = 0.0;
    printf("\nEnter the maximum capacity of the knapsack: ");
    scanf("%f", &u);
    for (i = 0; i < n; i++) {
        if (w[i] > u) {
            break;
        }
        c += x[i];
        u -= w[i];
    }
    if (i < n) {
        c += u*y[i];
    }
    printf("\nThe maximum profit is %f", c);
    return 0;
}