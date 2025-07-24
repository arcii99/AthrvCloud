//FormAI DATASET v1.0 Category: Stock market tracker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 10

struct Stock {
    char name[50];
    double price;
};

struct Stock stocks[MAX_STOCKS];
int numStocks = 0;

// Function to add a new stock to the tracker
void addStock(char* name, double price) {
    struct Stock newStock;
    strcpy(newStock.name, name);
    newStock.price = price;

    if (numStocks < MAX_STOCKS) {
        stocks[numStocks++] = newStock;
        printf("Stock %s added to the tracker!\n", name);
    } else {
        printf("Maximum number of stocks reached! Cannot add %s to the tracker.\n", name);
    }
}

// Function to generate a random price change for a stock
double randPriceChange() {
    return ((double)rand()/(double)RAND_MAX) * 10 - 5;
}

// Function to update the price of a stock
void updatePrice(int index) {
    double change = randPriceChange();
    stocks[index].price += change;
}

// Function to print the current prices of all tracked stocks
void printPrices() {
    printf("Current stock prices:\n");
    for (int i = 0; i < numStocks; i++) {
        printf("%s: $%.2f\n", stocks[i].name, stocks[i].price);
    }
}

int main() {
    srand(time(NULL));  // Seed random number generator with current time

    // Add some initial stocks to the tracker
    addStock("AAPL", 148.48);
    addStock("GOOG", 2715.57);
    addStock("TSLA", 729.40);

    // Main loop to simulate stock price changes
    int time = 0;
    while (1) {
        printf("---------------------------\n");
        printf("Time: %d\n", time++);

        // Update the prices of all tracked stocks
        for (int i = 0; i < numStocks; i++) {
            updatePrice(i);
        }

        // Print the current prices of all tracked stocks
        printPrices();

        // Wait for 1 second before updating prices again
        printf("Press enter to update prices again...\n");
        getchar();
    }

    return 0;
}