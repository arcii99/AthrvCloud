//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: expert-level
#include <stdio.h>

// function to sort items in descending order
void knapsack_sort(int weight[], int profit[], float ratio[], int n) {
    int i, j, temp_w, temp_p;
    float temp_r;
    for (i = 0; i < n; ++i)
    {
        for (j = i + 1; j < n; ++j)
        {
            if (ratio[i] < ratio[j])
            {
                temp_r = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp_r;

                temp_p = profit[i];
                profit[i] = profit[j];
                profit[j] = temp_p;

                temp_w = weight[i];
                weight[i] = weight[j];
                weight[j] = temp_w;
            }
        }
    }
}

// function to calculate maximum profit using greedy approach
void knapsack_greedy(int n, int capacity, int weight[], int profit[]) {
    int i, j;
    float ratio[n], total_profit = 0;

    for (i = 0; i < n; ++i) {
        ratio[i] = (float)profit[i]/(float)weight[i];
    }

    knapsack_sort(weight, profit, ratio, n);

    for (i = 0; i < n; ++i)
    {
        if (capacity == 0)
            break;

        if (weight[i] <= capacity)
        {
            total_profit += profit[i];
            capacity -= weight[i];
        }
        else
        {
            total_profit += ratio[i] * capacity;
            capacity = 0;
        }
    }

    printf("Maximum profit using Greedy approach: %f\n", total_profit);
}

int main() {
    int weight[] = {5, 10, 15};
    int profit[] = {10, 30, 75};
    int n = sizeof(weight)/sizeof(weight[0]);
    int capacity = 20;

    knapsack_greedy(n, capacity, weight, profit);

    return 0;
}