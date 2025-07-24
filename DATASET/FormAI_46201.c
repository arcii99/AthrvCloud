//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: all-encompassing
#include <stdio.h>

// Function to implement fractional knapsack using Greedy approach
void fractionalKnapsack(int n, int W, float profits[], float weights[]) {
    // Initialize variables
    float density[n], totalProfit = 0;
    int i;
    
    // Calculate density for each item
    for (i = 0; i < n; i++) {
        density[i] = profits[i] / weights[i];
    }
    
    // Sort items based on density in decreasing order
    // using Bubble sort algorithm
    int j;
    float temp;
    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) {
            if (density[i] < density[j]) {
                // Swap items based on density
                temp = density[i];
                density[i] = density[j];
                density[j] = temp;
                
                // Swap corresponding profits
                temp = profits[i];
                profits[i] = profits[j];
                profits[j] = temp;
                
                // Swap corresponding weights
                temp = weights[i];
                weights[i] = weights[j];
                weights[j] = temp;
            }
        }
    }
    
    // Calculate total profit obtained from knapsack
    float remainingCapacity = W;
    for (i = 0; i < n; i++) {
        if (remainingCapacity >= weights[i]) {
            // Add the entire item to knapsack
            remainingCapacity -= weights[i];
            totalProfit += profits[i];
        }
        else {
            // Add the item partially to knapsack based on remaining capacity
            totalProfit += (remainingCapacity / weights[i]) * profits[i];
            remainingCapacity = 0;
            break;
        }
    }
    
    // Print the final result
    printf("The maximum total profit obtained using fractional knapsack approach is: %f", totalProfit);
}

// Main function
int main() {
    // Initialize inputs
    int n = 5, W = 10;
    float profits[] = {15, 8, 10, 12, 5};
    float weights[] = {4, 3, 5, 6, 1};
    
    // Call fractional knapsack function
    fractionalKnapsack(n, W, profits, weights);
    
    return 0;
}