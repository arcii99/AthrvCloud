//FormAI DATASET v1.0 Category: Stock market tracker ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX_STOCKS 50

// Structure for holding stock information
typedef struct {
    char symbol[10];
    float price;
    float change;
    float percentage_change;
    int total_volume;
} Stock;

// Function to display stock information
void display_stock(Stock s) {
    printf("Symbol: %s\n", s.symbol);
    printf("Price: $%.2f\n", s.price);
    printf("Change: $%.2f\n", s.change);
    printf("Percentage Change: %.2f%%\n", s.percentage_change);
    printf("Total Volume: %d\n\n", s.total_volume);
}

// Function to get user input for stock symbol to track
void get_symbol(char symbol[]) {
    printf("Enter the stock symbol to track: ");
    scanf("%s", symbol);
}

int main() {
    Stock portfolio[MAX_STOCKS];
    int num_of_stocks = 0;

    while (1) {
        // Display menu options
        printf("Menu:\n");
        printf("1. Display all stocks\n");
        printf("2. Enter stock information\n");
        printf("3. Search for a specific stock\n");
        printf("4. Exit program\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Display all stocks in portfolio
                for (int i = 0; i < num_of_stocks; i++) {
                    display_stock(portfolio[i]);
                }
                break;
            case 2:
                // Get user input for stock information
                printf("Enter stock symbol: ");
                scanf("%s", portfolio[num_of_stocks].symbol);
                printf("Enter stock price: ");
                scanf("%f", &portfolio[num_of_stocks].price);
                printf("Enter stock change: ");
                scanf("%f", &portfolio[num_of_stocks].change);
                printf("Enter percentage change: ");
                scanf("%f", &portfolio[num_of_stocks].percentage_change);
                printf("Enter total volume: ");
                scanf("%d", &portfolio[num_of_stocks].total_volume);
                num_of_stocks++;
                break;
            case 3:
                // Search for stock by symbol
                char symbol_to_search[10];
                get_symbol(symbol_to_search);
                for (int i = 0; i < num_of_stocks; i++) {
                    if (strcmp(portfolio[i].symbol, symbol_to_search) == 0) {
                        display_stock(portfolio[i]);
                        break;
                    }
                }
                break;
            case 4:
                // Exit program
                printf("Exiting program.\n");
                exit(0);
            default:
                // Invalid choice
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}