//FormAI DATASET v1.0 Category: Stock market tracker ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_STOCKS 10
#define MAX_PRICE 1000
#define MIN_PRICE 100
#define MAX_CHANGE 50
#define MIN_CHANGE 1

// A struct to store the details of a stock
typedef struct {
    char name[20];
    float price;
    float changePercentage;
    time_t lastUpdated;
} Stock;

// A function to randomly generate a new price and change percentage for a stock
void generateNewValues(Stock *stock) {
    // Generate a random price between MAX_PRICE and MIN_PRICE
    stock->price = (float) (rand() % (MAX_PRICE - MIN_PRICE + 1) + MIN_PRICE);

    // Generate a random change percentage between MAX_CHANGE and MIN_CHANGE
    stock->changePercentage = (float) (rand() % (MAX_CHANGE - MIN_CHANGE + 1) + MIN_CHANGE) / 100;

    // Update the last updated time for the stock to the current time
    time(&stock->lastUpdated);
}

// A function to print the details of a stock to the console
void printStock(Stock stock) {
    char timeString[30];
    strftime(timeString, 30, "%Y-%m-%d %H:%M:%S", localtime(&stock.lastUpdated));

    printf("Stock Name: %s\n", stock.name);
    printf("Price: $%.2f\n", stock.price);
    printf("Change Percentage: %.2f%%\n", stock.changePercentage * 100);
    printf("Last Updated: %s\n\n", timeString);
}

int main() {
    Stock stocks[MAX_STOCKS];

    // Initialize the random number generator
    srand(time(NULL));

    // Initialize the stocks with some sample data
    for (int i = 0; i < MAX_STOCKS; i++) {
        sprintf(stocks[i].name, "Stock %d", i + 1);
        generateNewValues(&stocks[i]);
    }

    // Print the initial details of all the stocks
    printf("Initial Stock Data:\n");
    for (int i = 0; i < MAX_STOCKS; i++)
        printStock(stocks[i]);

    // Loop to update the stock values every 5 seconds
    int counter = 0;
    while (1) {
        // Increment the counter
        counter++;

        // Generate new values for each stock every 5 seconds
        if (counter % 5 == 0) {
            for (int i = 0; i < MAX_STOCKS; i++)
                generateNewValues(&stocks[i]);
        }

        // Print the details of all the stocks
        printf("Updated Stock Data:\n");
        for (int i = 0; i < MAX_STOCKS; i++)
            printStock(stocks[i]);

        // Sleep for 1 second before updating again
        sleep(1);
    }

    return 0;
}