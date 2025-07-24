//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: detailed
#include <stdio.h>

// Function to perform insertion sort
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to perform fractional knapsack algorithm
double fractionalKnapsack(int W, int n, int wt[], int val[])
{
    double maxVal = 0.0;
    double frac[n];
    int i;

    // Calculate the value per unit weight of each item
    for(i=0; i<n; i++)
        frac[i] = (double)val[i] / (double)wt[i];

    // Perform insertion sort on the array containing value per unit weight of each item
    insertionSort(frac, n);

    // Take items that give the maximum value till knapsack capacity is reached
    for(i=n-1; i>=0; i--)
    {
        if(wt[i] <= W)
        {
            W -= wt[i];
            maxVal += val[i];
        }
        else
        {
            maxVal += (double)W * frac[i];
            W = 0;
            break;
        }
    }

    return maxVal;
}

int main()
{
    int W = 50; // Maximum capacity of knapsack
    int val[] = {60, 100, 120}; // Array containing values of each item
    int wt[] = {10, 20, 30}; // Array containing weights of each item
    int n = sizeof(val)/sizeof(val[0]); // Number of items

    double maxVal = fractionalKnapsack(W, n, wt, val);

    printf("Maximum value in the knapsack = %f\n", maxVal);

    return 0;
}