//FormAI DATASET v1.0 Category: Stock market tracker ; Style: multivariable
#include<stdio.h>
#include<string.h>

struct StockData{
    char name[20];
    float currentPrice;
    float prevClose;
    float dayRangeLow;
    float dayRangeHigh;
    int volume;
};

int main(){

    struct StockData stock1 = {"Tesla", 574.00, 579.00, 550.00, 586.00, 100000};
    struct StockData stock2 = {"Apple", 133.00, 131.00, 127.00, 135.00, 50000};
    struct StockData stock3 = {"Microsoft", 226.00, 223.00, 220.00, 230.00, 75000};

    printf("STOCK MARKET TRACKER\n");
    printf("--------------------\n");

    // Display stock1 information
    printf("\nStock Name: %s\n", stock1.name);
    printf("Current Price: %.2f\n", stock1.currentPrice);
    printf("Previous Close: %.2f\n", stock1.prevClose);
    printf("Day Range Low: %.2f\n", stock1.dayRangeLow);
    printf("Day Range High: %.2f\n", stock1.dayRangeHigh);
    printf("Volume: %d\n", stock1.volume);
    printf("\n");

    // Display stock2 information
    printf("\nStock Name: %s\n", stock2.name);
    printf("Current Price: %.2f\n", stock2.currentPrice);
    printf("Previous Close: %.2f\n", stock2.prevClose);
    printf("Day Range Low: %.2f\n", stock2.dayRangeLow);
    printf("Day Range High: %.2f\n", stock2.dayRangeHigh);
    printf("Volume: %d\n", stock2.volume);
    printf("\n");

    // Display stock3 information
    printf("\nStock Name: %s\n", stock3.name);
    printf("Current Price: %.2f\n", stock3.currentPrice);
    printf("Previous Close: %.2f\n", stock3.prevClose);
    printf("Day Range Low: %.2f\n", stock3.dayRangeLow);
    printf("Day Range High: %.2f\n", stock3.dayRangeHigh);
    printf("Volume: %d\n", stock3.volume);
    printf("\n");

    return 0;
}