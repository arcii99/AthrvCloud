//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: synchronous
#include<stdio.h> 

struct Item 
{ 
    int value; 
    int weight; 
}; 

double fractionalKnapsack(int W, struct Item arr[], int n) 
{ 
    int i;
    double totalValue = 0.0;

    // Calculation of the value per unit weight for all items
    double valuePerUnitWeight[n];
    for (i = 0; i < n; i++) 
    {
        valuePerUnitWeight[i] = (double) arr[i].value / arr[i].weight;
    }

    // Sorting of items based on value per unit weight
    int j;
    struct Item temp;
    double tempValuePerUnitWeight;
    for (i = 0; i < n-1; i++) 
    {
        for (j = i+1; j < n; j++) 
        {
            if (valuePerUnitWeight[i] < valuePerUnitWeight[j]) 
            {
                // Swap items
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;

                // Swap value per unit weight
                tempValuePerUnitWeight = valuePerUnitWeight[i];
                valuePerUnitWeight[i] = valuePerUnitWeight[j];
                valuePerUnitWeight[j] = tempValuePerUnitWeight;
            }
        }
    }

    // Calculation of maximum value that can be obtained
    for (i = 0; i < n; i++) 
    {
        if (W == 0) 
        {
            break;
        }

        if (arr[i].weight <= W) 
        {
            W -= arr[i].weight;
            totalValue += arr[i].value;
        } 
        else 
        {
            totalValue += ((double) arr[i].value / arr[i].weight) * W;
            W = 0;
        }
    }

    return totalValue; 
} 

int main() 
{ 
    int W = 50; 
    struct Item arr[] = {{60, 10}, {100, 20}, {120, 30}}; 
    int n = sizeof(arr) / sizeof(arr[0]); 

    double max_value = fractionalKnapsack(W, arr, n); 

    printf("Maximum value that can be obtained from the knapsack is: %f", max_value); 

    return 0; 
}