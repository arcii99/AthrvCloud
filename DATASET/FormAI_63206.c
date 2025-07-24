//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: decentralized
#include<stdio.h>

int max_profit(int arr[], int n, int k)
{
    int profit = 0;

    for(int i = 0; i < n - 1; i++)
    {
        // find next day to sell
        while(i < n-1 && arr[i] >= arr[i+1])
            i++;

        // buy on ith day
        int buy = arr[i];

        // find next day to sell
        while(i < n-1 && arr[i] <= arr[i+1])
            i++;

        // sell on jth day
        int sell = arr[i];

        // calculate profit
        profit += sell - buy;
    }

    // return max profit
    return profit;
}

int main(){
    int n, k;
    printf("Enter the number of days: ");
    scanf("%d", &n);
    int prices[n];
    printf("Enter the stock prices for each day: ");
    for(int i=0; i<n; i++){
        scanf("%d", &prices[i]);
    }
    printf("Enter the number of transactions: ");
    scanf("%d", &k);

    printf("Maximum possible profit is: %d", max_profit(prices, n, k));
    return 0;
}