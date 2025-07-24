//FormAI DATASET v1.0 Category: Stock market tracker ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 10
#define MAX_NAME_LENGTH 20

typedef struct Stock {
    char name[MAX_NAME_LENGTH];
    float price;
} Stock;

void updatePrices(Stock* stocks, int numStocks) {
    for (int i = 0; i < numStocks; i++) {
        stocks[i].price = (float)(rand() % 100) + ((float)(rand() % 100) / 100); // generate a random price between 0 and 100 with two decimal places
    }
}

void printStocks(Stock* stocks, int numStocks) {
    printf("------------------------------------------\n");
    printf("%-10s | %-20s\n", "Symbol", "Price");
    printf("------------------------------------------\n");
    for (int i = 0; i < numStocks; i++) {
        printf("%-10s | %-20.2f\n", stocks[i].name, stocks[i].price);
    }
    printf("------------------------------------------\n");
}

int main() {
    Stock stocks[MAX_STOCKS];
    int numStocks = 0;

    // Add some initial stocks
    strcpy(stocks[numStocks].name, "AAPL");
    stocks[numStocks].price = 149.05;
    numStocks++;
    strcpy(stocks[numStocks].name, "GOOG");
    stocks[numStocks].price = 2718.82;
    numStocks++;

    // Main loop
    char command[10];
    do {
        // Print menu
        printf("\nChoose an action:\n");
        printf("1. Add Stock\n");
        printf("2. Update Prices\n");
        printf("3. Print Stocks\n");
        printf("4. Exit\n");
        printf("> ");

        // Get user input
        fgets(command, sizeof(command), stdin);

        switch (atoi(command)) {
            case 1:
                // Add Stock
                if (numStocks >= MAX_STOCKS) {
                    printf("Error: Maximum number of stocks reached.\n");
                } else {
                    printf("Enter stock symbol (max %d characters): ", MAX_NAME_LENGTH-1);
                    fgets(stocks[numStocks].name, MAX_NAME_LENGTH, stdin);
                    stocks[numStocks].name[strcspn(stocks[numStocks].name, "\n")] = 0; // remove newline character
                    printf("Enter stock price: ");
                    scanf("%f", &stocks[numStocks].price);
                    getchar(); // consume newline character from scanf
                    printf("Stock added.\n");
                    numStocks++;
                }
                break;

            case 2:
                // Update Prices
                updatePrices(stocks, numStocks);
                printf("Prices updated.\n");
                break;

            case 3:
                // Print Stocks
                printStocks(stocks, numStocks);
                break;

            case 4:
                // Exit
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid command, please try again.\n");
                break;
        }
    } while (strcmp(command, "4\n")); // exit loop when user enters "4"
    
    return 0;
}