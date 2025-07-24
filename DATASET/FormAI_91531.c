//FormAI DATASET v1.0 Category: Stock market tracker ; Style: innovative
#include <stdio.h>

// Function to calculate the moving average
float movingAverage(float arr[], int n, int k)
{
    float sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += arr[n-i-1];
    }
    return sum/k;
}

int main()
{
    int n, k;
    printf("Enter the number of stocks: ");
    scanf("%d", &n);
    float prices[n];

    // Read the stock prices
    for (int i = 0; i < n; i++)
    {
        printf("Enter the price of stock %d: ", i+1);
        scanf("%f", &prices[i]);
    }

    printf("Enter the moving average period desired: ");
    scanf("%d", &k);
    printf("Stock prices and corresponding moving averages:\n");

    // Calculate and display the moving averages
    for (int i = 0; i < n; i++)
    {
        printf("Stock %d: $%.2f, Moving Average: $%.2f\n", i+1, prices[i], movingAverage(prices, i, k));
    }

    return 0;
}