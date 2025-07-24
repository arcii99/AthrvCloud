//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: imaginative
#include<stdio.h>

// function to calculate maximum number of coins can be collected
int maxCoins(int n, int a[])
{
    int result = 0;
    int coins = 0;
  
    // Sorting array in non-increasing order
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[i]) {
                int temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }
  
    // Taking maximum from every second element
    for (int i = 0; i < n; i += 2) {
        coins += a[i];
    }
  
    result = coins;
    return result;
}

// main function
int main()
{
    int n, i;
    printf("Enter the number of coins: "); // asking for number of coins
    scanf("%d",&n);

    int array[n];
    printf("Enter the value of coins: "); // asking for value of each coin
    for(i=0;i<n;i++)
        scanf("%d",&array[i]);

    // calling function to get maximum number of coins
    int max = maxCoins(n, array);
    printf("\nMaximum number of coins that can be collected: %d\n", max);

    return 0;
}