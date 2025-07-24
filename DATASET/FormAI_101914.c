//FormAI DATASET v1.0 Category: Stock market tracker ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 10
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
    float high;
    float low;
} Stock;

void updatePrice(Stock *s);
void updateHighLow(Stock *s);
void printStocks(Stock s[]);
void displayMenu();

int main() {
    srand(time(NULL)); // Seeding random number generator with current time.

    Stock stocks[MAX_STOCKS]; // Creating stocks array.
    char input;
    int choice, amount;

    // Initializing stocks array with random stock information.
    for (int i = 0; i < MAX_STOCKS; i++) {
        sprintf(stocks[i].name, "Stock %d", i);
        stocks[i].price = rand() % 1000 + 1;
        stocks[i].high = stocks[i].price;
        stocks[i].low = stocks[i].price;
    }

    // Main program loop
    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Display current stock prices
                printStocks(stocks);
                break;
            case 2: // Update stock prices
                printf("Enter the amount of stocks to update: ");
                scanf("%d", &amount);

                for (int i = 0; i < amount; i++) {
                    printf("Enter the name of the stock to update: ");
                    scanf("%s", stocks[i].name);
                    printf("Enter the new price of the stock: ");
                    scanf("%f", &stocks[i].price);
                    updateHighLow(&stocks[i]); // Updating high and low values.
                }

                printf("Stock prices updated successfully.\n");
                break;
            case 3: // Exit program
                printf("Exiting program...");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

    } while (choice != 3);

    return 0;
}

// Updates the price of a stock with a new random value.
void updatePrice(Stock *s) {
    float modifier = (float) (rand() % 10 + 1) / 100; // Generating random modifier between 0.01 and 0.10.
    int signModifier = rand() % 2; // Generating random modifier for sign of price change (1 for positive, 0 for negative).

    if (signModifier == 1) {
        s->price += (s->price * modifier);
    } else {
        s->price -= (s->price * modifier);
    }
}

// Updates the high and low values of a stock based on its current price.
void updateHighLow(Stock *s) {
    if (s->price > s->high) {
        s->high = s->price;
    } else if (s->price < s->low) {
        s->low = s->price;
    }
}

// Prints the current stock information for all stocks in the stocks array.
void printStocks(Stock s[]) {
    printf("Name\tPrice\tHigh\tLow\n");

    for (int i = 0; i < MAX_STOCKS; i++) {
        printf("%s\t%.2f\t%.2f\t%.2f\n", s[i].name, s[i].price, s[i].high, s[i].low);
    }
}

// Displays the main program menu.
void displayMenu() {
    printf("Stock Market Tracker\n");
    printf("--------------------\n");
    printf("1. Display current stock prices\n");
    printf("2. Update stock prices\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}