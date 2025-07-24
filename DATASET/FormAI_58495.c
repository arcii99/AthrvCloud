//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: relaxed
#include <stdio.h>

// Function to find the minimum number of coins required to make a given sum
int findMinCoins(int coins[], int n, int sum)
{
    // sort the array in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (coins[i] < coins[j]) {
                int temp = coins[i];
                coins[i] = coins[j];
                coins[j] = temp;
            }
        }
    }

    // traverse the array and pick coins greedily
    int count = 0;
    for (int i = 0; i < n; i++) {
        while (sum >= coins[i]) {
            sum -= coins[i];
            count++;
        }
    }

    return count;
}

int main()
{
    int coins[] = { 1, 2, 5, 10, 20 };
    int n = sizeof(coins) / sizeof(coins[0]);

    int sum;
    printf("Enter the sum: ");
    scanf("%d", &sum);

    int minCoins = findMinCoins(coins, n, sum);

    printf("Minimum number of coins required to make %d: %d", sum, minCoins);

    return 0;
}