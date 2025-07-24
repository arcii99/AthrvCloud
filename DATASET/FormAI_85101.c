//FormAI DATASET v1.0 Category: Stock market tracker ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Define the structure for the stock market tracker
struct stock {
   char company_name[50];
   float share_price;
   float share_change; // The change in share price
   float market_capitalization; // Market Cap
};

int main() {
    printf("Stock Market Tracker App\n\n");
    int num_stocks;
    printf("Enter the number of stocks you want to add to the tracker: ");
    scanf("%d", &num_stocks);

    // Create an array of type stock to hold the stock information
    struct stock stocks[num_stocks];

    // Get the stock information for each stock
    for(int i = 0; i < num_stocks; i++) {
        printf("\nStock %d\n", i+1);
        printf("Enter the company name: ");
        scanf("%s", stocks[i].company_name);
        printf("Enter the share price: ");
        scanf("%f", &stocks[i].share_price);
        printf("Enter the change in share price: ");
        scanf("%f", &stocks[i].share_change);
        printf("Enter the market capitalization: ");
        scanf("%f", &stocks[i].market_capitalization);
    }

    // Display the stock information
    printf("\n***************\n");
    printf("STOCK TRACKER\n");
    printf("***************\n");
    for(int i = 0; i < num_stocks; i++) {
        printf("\nStock %d\n", i+1);
        printf("Company name: %s\n", stocks[i].company_name);
        printf("Share price: $%.2f\n", stocks[i].share_price);
        printf("Change in share price: %.2f%%\n", stocks[i].share_change);
        printf("Market capitalization: $%.2fB\n", stocks[i].market_capitalization);
    }

    return 0;
}