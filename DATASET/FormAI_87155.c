//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Romeo and Juliet
// Romeo and Juliet Stock Market Tracker

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Constants for the program
#define MAX_STOCK_NAME_LENGTH 20
#define MAX_HISTORY_SIZE 10

// Struct to hold each stock information
typedef struct {
    char name[MAX_STOCK_NAME_LENGTH];
    double currentPrice;
    double history[MAX_HISTORY_SIZE];
    int historyCount;
} Stock;

// Function to add a price to the stock history
void addToHistory(Stock *stock, double price) {
    int index = stock->historyCount % MAX_HISTORY_SIZE;
    stock->history[index] = price;
    stock->historyCount++;
}

// Function to display the history of a stock
void displayHistory(Stock *stock) {
    printf("%s's price history:\n", stock->name);
    int i;
    for (i = 0; i < stock->historyCount; i++) {
        printf("%.2f\n", stock->history[i]);
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Create the two stocks
    Stock stockA = {"StockA", (double)(rand() % 100)};
    Stock stockB = {"StockB", (double)(rand() % 100)};
    
    // Display the initial prices of the stocks
    printf("Initial prices:\n%s: %.2f\n%s: %.2f\n", stockA.name, stockA.currentPrice, stockB.name, stockB.currentPrice);
    
    // Loop through a set number of iterations to simulate price changes
    int iterations = 5;
    int i;
    for (i = 0; i < iterations; i++) {
        // Wait for a random time between 1-5 seconds
        int delay = rand() % 5 + 1;
        printf("Waiting for %d seconds...\n", delay);
        sleep(delay);
        
        // Generate a random price change for each stock
        double priceChangeA = (double)(rand() % 10 - 5);
        double priceChangeB = (double)(rand() % 10 - 5);
        
        // Update the stock prices and histories
        stockA.currentPrice += priceChangeA;
        stockB.currentPrice += priceChangeB;
        addToHistory(&stockA, stockA.currentPrice);
        addToHistory(&stockB, stockB.currentPrice);
        
        // Display the new prices of the stocks
        printf("Iteration %d:\n%s: %.2f\n%s: %.2f\n", i+1, stockA.name, stockA.currentPrice, stockB.name, stockB.currentPrice);
    }
    
    // Display the histories of the stocks
    displayHistory(&stockA);
    displayHistory(&stockB);
    
    return 0;
}