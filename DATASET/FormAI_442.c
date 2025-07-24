//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: dynamic
#include <stdio.h> 
#include <stdlib.h> 

struct Item { 
    int value; 
    int weight; 
}; 

int max(int a, int b) { return (a > b) ? a : b; } 

int knapSack(int W, struct Item items[], int n) 
{ 
    int** K; 
    K = (int**)malloc((n + 1) * sizeof(int*)); 
    for (int i = 0; i < (n + 1); i++) 
        K[i] = (int*)malloc((W + 1) * sizeof(int)); 

    for (int i = 0; i <= n; i++) { 
        for (int w = 0; w <= W; w++) { 
            if (i == 0 || w == 0) 
                K[i][w] = 0; 
            else if (items[i - 1].weight <= w) 
                K[i][w] = max(items[i - 1].value 
                          + K[i - 1][w - items[i - 1].weight], 
                          K[i - 1][w]); 
            else
                K[i][w] = K[i - 1][w]; 
        } 
    } 

    int result = K[n][W]; 
    for (int i = 0; i < (n + 1); i++) 
        free(K[i]); 
    free(K); 
    return result; 
} 
  
int main() 
{ 
    int W = 50; 
    struct Item items[] = {{60, 10}, {100, 20}, {120, 30}}; 
    int n = sizeof(items) / sizeof(items[0]); 
    printf("Maximum value that can be put in a knapsack of capacity %d is %d.", W, knapSack(W, items, n)); 
    return 0; 
}