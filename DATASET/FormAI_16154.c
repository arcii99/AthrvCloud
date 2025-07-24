//FormAI DATASET v1.0 Category: Stock market tracker ; Style: curious
#include<stdio.h>

int main() {

    printf("Welcome to the Stock Market Tracker Application!\n");

    float stockPrice = 0.0;
    float indexPrice = 0.0;
    float changePercent = 0.0;

    printf("Please enter the current stock price: ");
    scanf("%f", &stockPrice);

    printf("Please enter the current index price: ");
    scanf("%f", &indexPrice);

    changePercent = ((stockPrice - indexPrice) / indexPrice) * 100;

    printf("Change Percentage: %f %%\n", changePercent);

    if(changePercent < 0) {
        printf("Uh oh! It seems like the stock is underperforming compared to the index. It's time to reconsider.\n");
    } else if(changePercent > 0) {
        printf("Great news! The stock is currently outperforming compared to the index. Keep holding on or consider buying more.\n");
    } else {
        printf("The stock is performing at par with the index. You can continue holding on.\n");
    }

    return 0;
}