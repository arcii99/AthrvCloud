//FormAI DATASET v1.0 Category: Stock market tracker ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMBER_OF_STOCKS 5 // change this to however many stocks you want to track
#define MAX_STOCK_PRICE 200 // set maximum stock price
#define MIN_STOCK_PRICE 5 // set minimum stock price

// function to generate random stock price within range
int rand_stock_price() {
    return (rand() % (MAX_STOCK_PRICE - MIN_STOCK_PRICE + 1)) + MIN_STOCK_PRICE;
}

int main() {
    // seed random number generator with current time
    srand(time(NULL));

    int stocks[NUMBER_OF_STOCKS];
    int i;
    for (i = 0; i < NUMBER_OF_STOCKS; i++) {
        stocks[i] = rand_stock_price();
    }

    // print initial stock prices
    printf("Initial stock prices:\n");
    for (i = 0; i < NUMBER_OF_STOCKS; i++) {
        printf("STOCK %d: %d\n", i+1, stocks[i]);
    }

    // enter main loop to track stocks
    int choice;
    while (1) {
        printf("\nWhat do you want to do?\n");
        printf("1. Display current stock prices\n");
        printf("2. Check specific stock price\n");
        printf("3. Simulate stock market changes\n");
        printf("4. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        // handle user input
        switch(choice) {
            case 1:
                // display current stock prices
                printf("Current stock prices:\n");
                for (i = 0; i < NUMBER_OF_STOCKS; i++) {
                    printf("STOCK %d: %d\n", i+1, stocks[i]);
                }
                break;
            case 2:
                // check specific stock price
                printf("Enter stock number to check: ");
                scanf("%d", &i);
                if (i > 0 && i <= NUMBER_OF_STOCKS) {
                    printf("Stock %d price: %d\n", i, stocks[i-1]);
                } else {
                    printf("Invalid choice\n");
                }
                break;
            case 3:
                // simulate stock market changes
                printf("Simulating stock market changes...\n");
                for (i = 0; i < NUMBER_OF_STOCKS; i++) {
                    int change = rand() % 21 - 10; // generate random change between -10 and 10
                    stocks[i] += change;
                    if (stocks[i] < MIN_STOCK_PRICE) {
                        stocks[i] = MIN_STOCK_PRICE;
                    } else if (stocks[i] > MAX_STOCK_PRICE) {
                        stocks[i] = MAX_STOCK_PRICE;
                    }
                }
                printf("Stock prices after market changes:\n");
                for (i = 0; i < NUMBER_OF_STOCKS; i++) {
                    printf("STOCK %d: %d\n", i+1, stocks[i]);
                }
                break;
            case 4:
                // quit program
                printf("Thank you for using our stock market tracker!\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}