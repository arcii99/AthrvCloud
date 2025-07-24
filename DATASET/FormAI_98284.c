//FormAI DATASET v1.0 Category: Stock market tracker ; Style: authentic
#include<stdio.h>

#define MAX 100

int main(){
    int n, i, j, stock_prices[MAX];
    float profit[MAX], max_profit;
    
    //Take user input
    printf("Enter the number of days:\n");
    scanf("%d", &n);
    printf("Enter the stock prices:\n");
    for(i=0;i<n;i++){
        scanf("%d", &stock_prices[i]);
    }
    
    //Calculate the profit for each day
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            profit[j] = (float)(stock_prices[j] - stock_prices[i]) / stock_prices[i];
        }
    }
    
    //Find the maximum profit
    max_profit = profit[1];
    for(i=1;i<n-1;i++){
        if(profit[i+1] > max_profit){
            max_profit = profit[i+1];
        }
    }
    
    //Output the maximum profit
    printf("The maximum profit is: %.2f%%\n", max_profit*100);
    
    return 0;
}