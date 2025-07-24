//FormAI DATASET v1.0 Category: Stock market tracker ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define the stock structure
struct Stock {
    char name[30];
    float currentPrice;
    float difference;
};

// Function to get user input and update the stock
void updateStock(struct Stock* stock) {
    printf("\nEnter the new current price for %s: ", stock->name);
    scanf("%f", &stock->currentPrice);

    stock->difference = stock->currentPrice - (stock->currentPrice * 0.10); // Calculate the 10% decrease in price
}

// Function to display the stock details
void displayStock(struct Stock stock) {
    printf("\nName: %s", stock.name);
    printf("\nCurrent Price: %.2f", stock.currentPrice);
    printf("\nDifference from previous day: %.2f", stock.difference);
}

int main() {
    int numStocks;

    printf("How many stocks do you want to track? ");
    scanf("%d", &numStocks);

    struct Stock* stocks = (struct Stock*) malloc(sizeof(struct Stock) * numStocks); // Allocate memory for the stock array

    // Get user input for each stock
    for(int i=0; i<numStocks; i++) {
        printf("\nEnter the name of stock %d: ", i+1);
        scanf("%s", stocks[i].name);

        printf("Enter the current price for %s: ", stocks[i].name);
        scanf("%f", &stocks[i].currentPrice);

        stocks[i].difference = 0; // Set the initial difference to 0
    }

    int option;

    // Show menu options to the user
    do {
        printf("\nWhat do you want to do?\n");
        printf("1. Update stock price\n");
        printf("2. Display all stocks\n");
        printf("0. Exit\n");

        scanf("%d", &option);

        switch(option) {
            case 1:
                // Get user input for which stock to update
                int stockIndex;
                printf("\nWhich stock do you want to update? Enter the index: ");
                scanf("%d", &stockIndex);

                // Call the updateStock function for that stock
                updateStock(&stocks[stockIndex]);

                printf("\nStock updated successfully!\n");

                break;

            case 2:
                // Display all stocks
                printf("\nCurrent stock details:\n");
                for(int i=0; i<numStocks; i++) {
                    displayStock(stocks[i]);
                    printf("\n");
                }

                break;

            case 0:
                printf("\nExiting the program. Goodbye!\n");
                break;

            default:
                printf("\nNot a valid option. Please try again.\n");
        }
    } while(option != 0); // Loop until the user selects the exit option

    free(stocks); // Free the allocated memory

    return 0;
}