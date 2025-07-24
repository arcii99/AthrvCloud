//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
    int i, j, temp;
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(arr[i] > arr[j]) {  
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void greedyKnapsack(int W, int wt[], int val[], int n) {
    sort(val, n);  
    int i, profit = 0;
    for (i = n-1; i >= 0; i--) {
        if (wt[i] <= W) {
            profit += val[i];
            W -= wt[i];
        }
        else {
            float frac = (float)W / (float)wt[i];
            profit += (int)(val[i] * frac);
            W = (int)(W - (wt[i] * frac));
            break;
        }
    }
    printf("Total profit: %d\n", profit);
}

int main() {
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    int wt[n], val[n], i;
    printf("Enter the weight and value of each item:\n");
    for (i = 0; i < n; i++) {
        scanf("%d%d", &wt[i], &val[i]);
    }
    printf("Enter the maximum weight of the knapsack: ");
    scanf("%d", &W);
    greedyKnapsack(W, wt, val, n);
    return 0;
}