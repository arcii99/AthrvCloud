//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: recursive
#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int knapsack(int W, int wt[], int val[], int n) {
    if(n == 0 || W == 0) {
        return 0;
    }
    if(wt[n-1] > W) {
        return knapsack(W, wt, val, n-1);
    }
    else {
        return max(val[n-1] + knapsack(W-wt[n-1], wt, val, n-1), knapsack(W, wt, val, n-1));
    }
}

int main() {
    int n = 3;
    int W = 50;
    int wt[] = {10, 20, 30};
    int val[] = {60, 100, 120};
    
    int max_val = knapsack(W, wt, val, n);
    
    printf("Max value is: %d", max_val);
    return 0;
}