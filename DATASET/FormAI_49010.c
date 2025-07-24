//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Romeo and Juliet
#include <stdio.h>

int main()
{
    int coins[4] = {25, 10, 5, 1}; // Array containing the coin denominations
    int n; // Input value for which change is to be made
    printf("Enter the amount for which you want to make change: ");
    scanf("%d", &n);

    int count = 0;
    for (int i = 0; i < 4; i++)
    {
        count += n / coins[i]; // Counting the number of coins required for each denomination
        n = n % coins[i]; // Updating the remaining value for which change is to be made
    }

    printf("Minimum number of coins required is: %d\n", count);

    return 0;
}