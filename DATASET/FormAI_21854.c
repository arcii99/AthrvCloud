//FormAI DATASET v1.0 Category: Stock market tracker ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 10
#define STOCK_NAME_LENGTH 20

typedef struct {
    char name[STOCK_NAME_LENGTH];
    float price;
    float change;
    float percentage_change;
} Stock;

void updatePrices(Stock *portfolio, int numStocks);

int main() {
    srand(time(NULL));
    Stock portfolio[MAX_STOCKS];
    int numStocks = 0;

    // Add initial stocks to portfolio
    strcpy(portfolio[0].name, "AAPL");
    portfolio[0].price = 135.39;
    portfolio[0].change = 0.02;
    portfolio[0].percentage_change = 0.015;
    numStocks++;
    strcpy(portfolio[1].name, "GOOGL");
    portfolio[1].price = 1837.06;
    portfolio[1].change = -0.05;
    portfolio[1].percentage_change = -0.002;
    numStocks++;
    strcpy(portfolio[2].name, "AMZN");
    portfolio[2].price = 3117.02;
    portfolio[2].change = 0.1;
    portfolio[2].percentage_change = 0.0032;
    numStocks++;

    printf("Welcome to the C Stock Market Tracker!\n");

    while (1) {
        printf("\nYour portfolio:\n");
        printf("___________________________________\n");
        printf("| %-5s | %-15s | %-10s |\n", "Rank", "Name", "Price");
        printf("|______|_________________|__________|\n");
        for (int i = 0; i < numStocks; i++) {
            printf("| %-5d | %-15s | $%-9.2f |\n", i+1, portfolio[i].name, portfolio[i].price);
        }
        printf("|______|_________________|__________|\n\n");

        printf("Enter a command (type 'help' for a list of commands): ");
        char input[10];
        scanf("%s", input);

        if (strcmp(input, "help") == 0) {
            printf("Available commands: buy, sell, update, quit\n");

        } else if (strcmp(input, "buy") == 0) {
            if (numStocks == MAX_STOCKS) {
                printf("Sorry, you cannot hold more than %d stocks in your portfolio.\n", MAX_STOCKS);
            } else {
                char stockName[STOCK_NAME_LENGTH];
                printf("Enter the stock name: ");
                scanf("%s", stockName);
                int found = 0;
                for (int i = 0; i < numStocks; i++) {
                    if (strcmp(portfolio[i].name, stockName) == 0) {
                        found = 1;
                        printf("You already own that stock.\n");
                        break;
                    }
                }
                if (!found) {
                    float price = ((float)rand()/(float)(RAND_MAX))*100;
                    printf("Price: $%.2f\n", price);
                    strcpy(portfolio[numStocks].name, stockName);
                    portfolio[numStocks].price = price;
                    portfolio[numStocks].change = ((float)rand()/(float)(RAND_MAX))*0.2 - 0.1;
                    portfolio[numStocks].percentage_change = portfolio[numStocks].change / portfolio[numStocks].price;
                    numStocks++;
                    printf("You bought %s at $%.2f.\n", stockName, price);
                }
            }

        } else if (strcmp(input, "sell") == 0) {
            if (numStocks == 0) {
                printf("You don't have any stocks to sell.\n");
            } else {
                char stockName[STOCK_NAME_LENGTH];
                printf("Enter the stock name: ");
                scanf("%s", stockName);
                int found = 0;
                for (int i = 0; i < numStocks; i++) {
                    if (strcmp(portfolio[i].name, stockName) == 0) {
                        found = 1;
                        printf("You sold %s at $%.2f.\n", stockName, portfolio[i].price);
                        numStocks--;
                        for (int j = i; j < numStocks; j++) {
                            portfolio[j] = portfolio[j+1];
                        }
                        break;
                    }
                }
                if (!found) {
                    printf("You don't own that stock.\n");
                }
            }

        } else if (strcmp(input, "update") == 0) {
            updatePrices(portfolio, numStocks);
            printf("Prices updated.\n");

        } else if (strcmp(input, "quit") == 0) {
            printf("Goodbye!\n");
            break;

        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}

void updatePrices(Stock *portfolio, int numStocks) {
    for (int i = 0; i < numStocks; i++) {
        portfolio[i].price += portfolio[i].price * portfolio[i].percentage_change;
        portfolio[i].change = ((float)rand()/(float)(RAND_MAX))*0.2 - 0.1;
        portfolio[i].percentage_change = portfolio[i].change / portfolio[i].price;
    }
}