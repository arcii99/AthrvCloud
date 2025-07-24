//FormAI DATASET v1.0 Category: Stock market tracker ; Style: multivariable
#include <stdio.h> 

int main() { 
    float stock1Price, stock2Price, stock3Price; 
    int stock1Shares, stock2Shares, stock3Shares; 
  
    printf("Enter the price of stock 1: ");
    scanf("%f", &stock1Price);
    printf("Enter the number of shares for stock 1: ");
    scanf("%d", &stock1Shares);
  
    printf("Enter the price of stock 2: ");
    scanf("%f", &stock2Price);
    printf("Enter the number of shares for stock 2: ");
    scanf("%d", &stock2Shares);
  
    printf("Enter the price of stock 3: ");
    scanf("%f", &stock3Price);
    printf("Enter the number of shares for stock 3: ");
    scanf("%d", &stock3Shares);
  
    float totalValue = (stock1Price * stock1Shares) + (stock2Price * stock2Shares) + (stock3Price * stock3Shares); 
    printf("Total value of the portfolio: %.2f\n", totalValue); 
    
    float stock1Percentage = (stock1Price * stock1Shares) / totalValue * 100; 
    float stock2Percentage = (stock2Price * stock2Shares) / totalValue * 100; 
    float stock3Percentage = (stock3Price * stock3Shares) / totalValue * 100; 
  
    printf("Breakdown by Percentage:\n");
    printf("Stock 1: %.2f%%\n", stock1Percentage);
    printf("Stock 2: %.2f%%\n", stock2Percentage);
    printf("Stock 3: %.2f%%\n", stock3Percentage);
    
    if (totalValue > 10000) { 
        printf("Portfolio value is greater than $10,000.\n");
    }
    else { 
        printf("Portfolio value is less than $10,000.\n");
    }
  
    return 0; 
}