//FormAI DATASET v1.0 Category: Stock market tracker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SYMBOL_LENGTH 10
#define MAX_TRACKED_STOCKS 5

// Define a struct to hold information about a tracked stock.
typedef struct {
    char symbol[MAX_SYMBOL_LENGTH + 1];
    float price;
} TrackedStock;

// Declare global variables.
TrackedStock trackedStocks[MAX_TRACKED_STOCKS];
int numTrackedStocks = 0;

// Declare function prototypes
void addStock();
void removeStock();
void displayStocks();
void updateStockPrice();
void clearInput();

int main() {
    char command;

    // Print welcome message
    printf("Welcome to the Shape-Shifting Stock Market Tracker!\n");

    // Enter main program loop
    while (1) {
        // Print menu options
        printf("\nPlease choose an option:\n");
        printf("a) Add a stock\n");
        printf("r) Remove a stock\n");
        printf("d) Display tracked stocks\n");
        printf("u) Update stock prices\n");
        printf("q) Quit program\n");

        // Get user command
        printf("Command: ");
        scanf("%c%*c", &command);

        // Process user command
        switch (tolower(command)) {
            case 'a':
                addStock();
                break;
            case 'r':
                removeStock();
                break;
            case 'd':
                displayStocks();
                break;
            case 'u':
                updateStockPrice();
                break;
            case 'q':
                printf("Thanks for using the Shape-Shifting Stock Market Tracker!\n");
                exit(0);
            default:
                printf("Invalid command! Please try again.\n");
        }
    }

    return 0;
}

// Add a stock to the tracker.
void addStock() {
    char symbol[MAX_SYMBOL_LENGTH + 1];
    float price;

    // Check if the tracker is already full.
    if (numTrackedStocks == MAX_TRACKED_STOCKS) {
        printf("Sorry, the tracker is already full!\n");
        return;
    }

    // Get stock symbol and price from user.
    printf("Please enter the stock symbol: ");
    scanf("%s%*c", symbol);
    printf("Please enter the current stock price: ");
    scanf("%f%*c", &price);

    // Add the stock to the tracker.
    strcpy(trackedStocks[numTrackedStocks].symbol, symbol);
    trackedStocks[numTrackedStocks].price = price;
    numTrackedStocks++;

    printf("%s has been added to the tracker!\n", symbol);
}

// Remove a stock from the tracker.
void removeStock() {
    char symbol[MAX_SYMBOL_LENGTH + 1];
    int i, j;

    // Check if the tracker is empty.
    if (numTrackedStocks == 0) {
        printf("Sorry, the tracker is already empty!\n");
        return;
    }

    // Get stock symbol to remove from user.
    printf("Please enter the stock symbol to remove: ");
    scanf("%s%*c", symbol);

    // Search for the stock to remove in the tracked stocks array.
    for (i = 0; i < numTrackedStocks; i++) {
        if (strcmp(trackedStocks[i].symbol, symbol) == 0) {
            // Found the stock, now remove it by shifting all subsequent stocks back one index.
            for (j = i; j < numTrackedStocks - 1; j++) {
                strcpy(trackedStocks[j].symbol, trackedStocks[j+1].symbol);
                trackedStocks[j].price = trackedStocks[j+1].price;
            }
            numTrackedStocks--;
            printf("%s has been removed from the tracker!\n", symbol);
            return;
        }
    }

    printf("%s is not being tracked!\n", symbol);
}

// Display all tracked stocks.
void displayStocks() {
    int i;

    // Check if the tracker is empty.
    if (numTrackedStocks == 0) {
        printf("The tracker is empty!\n");
        return;
    }

    printf("%-10s%-10s\n", "Symbol", "Price");
    printf("---------------------\n");
    for (i = 0; i < numTrackedStocks; i++) {
        printf("%-10s%-10.2f\n", trackedStocks[i].symbol, trackedStocks[i].price);
    }
}

// Update the price of a tracked stock.
void updateStockPrice() {
    char symbol[MAX_SYMBOL_LENGTH + 1];
    int i;

    // Check if the tracker is empty.
    if (numTrackedStocks == 0) {
        printf("Sorry, the tracker is empty!\n");
        return;
    }

    // Get stock symbol and new price from user.
    printf("Please enter the stock symbol to update: ");
    scanf("%s%*c", symbol);

    for (i = 0; i < numTrackedStocks; i++) {
        if (strcmp(trackedStocks[i].symbol, symbol) == 0) {
            // Update the price of the tracked stock.
            printf("Please enter the new stock price: ");
            scanf("%f%*c", &trackedStocks[i].price);
            printf("%s price updated to %.2f!\n", symbol, trackedStocks[i].price);
            return;
        }
    }

    printf("%s is not being tracked!\n", symbol);
}

// Clear input buffer.
void clearInput() {
    while (getchar() != '\n');
}