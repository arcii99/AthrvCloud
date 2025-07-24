//FormAI DATASET v1.0 Category: Stock market tracker ; Style: peaceful
#include <stdio.h>

int main() {
    // Declare variables
    int stockPrice1, stockPrice2, stockPrice3, stockPrice4, stockPrice5;
    float average;

    // Prompt user for input
    printf("Enter the stock price for day 1: ");
    scanf("%d", &stockPrice1);
    printf("Enter the stock price for day 2: ");
    scanf("%d", &stockPrice2);
    printf("Enter the stock price for day 3: ");
    scanf("%d", &stockPrice3);
    printf("Enter the stock price for day 4: ");
    scanf("%d", &stockPrice4);
    printf("Enter the stock price for day 5: ");
    scanf("%d", &stockPrice5);

    // Calculate the average of the 5 days
    average = (float)(stockPrice1 + stockPrice2 + stockPrice3 + stockPrice4 + stockPrice5) / 5;

    // Print results
    printf("\nThe average stock price for the past 5 days is $%.2f\n", average);

    // Determine if the stock price is increasing or decreasing
    if (stockPrice1 < stockPrice2 && stockPrice2 < stockPrice3 && stockPrice3 < stockPrice4 && stockPrice4 < stockPrice5) {
        printf("The stock price is increasing.\n");
    }
    else if (stockPrice1 > stockPrice2 && stockPrice2 > stockPrice3 && stockPrice3 > stockPrice4 && stockPrice4 > stockPrice5) {
        printf("The stock price is decreasing.\n");
    }
    else {
        printf("The stock price is stagnant.\n");
    }

    return 0;
}