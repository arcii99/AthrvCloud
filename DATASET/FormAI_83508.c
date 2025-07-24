//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: cheerful
#include <stdio.h>

void findMinCoins(int coins[], int ncoins, int amt)
{
    int i, count=0;
    for(i = 0; i < ncoins; i++)
    {
        while(amt >= coins[i])
        {
            printf("%d ", coins[i]);
            amt -= coins[i];
            count++;
        }
    }
    printf("\nTotal coins needed: %d\n", count);
}

int main()
{
    printf("Welcome to the Coin Change Calculator!\n\n");
    printf("Enter the total amount you want to make change for: ");
    
    int amt;
    scanf("%d", &amt);

    int coins[] = {50, 25, 10, 5, 1};
    int ncoins = 5;
    
    printf("\nThe minimum coins needed to make change for %d are:\n", amt);
    findMinCoins(coins, ncoins, amt);

    printf("\nThank you for using our program! Have a nice day!\n");
    return 0;
}