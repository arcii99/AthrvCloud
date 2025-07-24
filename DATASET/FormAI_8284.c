//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: careful
#include <stdio.h>

void CoinChange(int amount); //Function for Coin Change Algorithm

int main()
{
    int amount;
    printf("Enter the amount for which you want to make change: ");
    scanf("%d", &amount);
    CoinChange(amount);
    return 0;
}

void CoinChange(int amount)
{
    int denominations[9] = { 5000, 2000, 1000, 500, 100, 50, 20, 10, 5 }; //Array of denominations
    int count[9] = { 0,0,0,0,0,0,0,0,0 }; //Array for counting each denomination used
    int i;
    for(i = 0; i < 9; i++)
    {
        while(amount >= denominations[i])
        {
            amount -= denominations[i]; //Reduce the amount by denomination used
            count[i]++; //Increase the count of that denomination
        }
    }
    printf("Coin Change Algorithm:\n");
    for(i = 0; i < 9; i++)
    {
        printf("%d x %d\n", denominations[i], count[i]); //Display the result
    }
}