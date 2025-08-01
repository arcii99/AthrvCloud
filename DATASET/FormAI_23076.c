//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: careful
#include <stdio.h>

void knapSack(int W, int wt[], int val[], int n) 
{ 
    int i, w; 
    int K[n+1][W+1]; 
  
    for (i = 0; i <= n; i++) 
    { 
        for (w = 0; w <= W; w++) 
        { 
            if (i==0 || w==0)
                K[i][w] = 0; 
            else if (wt[i-1] <= w)
                K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]); 
            else
                K[i][w] = K[i-1][w]; 
        } 
    } 

    int res = K[n][W];     
    printf("Maximum value possible: %d\n", res);
    w = W; 

    for (i = n; i > 0 && res > 0; i--) 
    { 
        if (res == K[i-1][w]) 
            continue;         
        else 
        { 
            printf("%d item included\n", i);           
            res = res - val[i-1]; 
            w = w - wt[i-1]; 
        } 
    } 
} 

int max(int a, int b) 
{ 
    return (a > b)? a : b; 
} 


int main() 
{ 
    int val[] = {60, 100, 120}; 
    int wt[] = {10, 20, 30}; 
    int W = 50; 
    int n = sizeof(val)/sizeof(val[0]);
    
    knapSack(W, wt, val, n); 
    return 0; 
}