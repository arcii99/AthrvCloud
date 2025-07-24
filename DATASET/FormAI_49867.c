//FormAI DATASET v1.0 Category: Stock market tracker ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STOCK_COUNT 10
#define INITIAL_PRICE 100
#define PERCENT_CHANGE 10

struct Stock {
    int id;
    char name[20];
    float price;
};

int main() {
    struct Stock stocks[STOCK_COUNT];
    int i, choice;

    srand(time(NULL)); // seed random number generator

    // initialize stocks
    for (i = 0; i < STOCK_COUNT; i++) {
        stocks[i].id = i + 1;
        sprintf(stocks[i].name, "Stock %d", i + 1);
        stocks[i].price = INITIAL_PRICE;
    }

    // display menu and track stock prices
    do {
        system("clear"); // clear screen

        printf("*** STOCK MARKET TRACKER ***\n\n");
        printf("Select an option:\n");
        printf("1. View stock prices\n");
        printf("2. Buy stock\n");
        printf("3. Sell stock\n");
        printf("4. Quit\n");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("\n*** STOCK PRICES ***\n\n");
            for (i = 0; i < STOCK_COUNT; i++) {
                printf("%d. %s: $%.2f\n", stocks[i].id, stocks[i].name, stocks[i].price);
            }
            break;
        case 2:
            printf("\nEnter ID of stock to buy (1-%d): ", STOCK_COUNT);
            scanf("%d", &i);
            if (i < 1 || i > STOCK_COUNT) {
                printf("\nInvalid stock ID.\n");
                break;
            }
            printf("\nEnter number of shares to buy: ");
            scanf("%d", &choice);
            if (choice * stocks[i-1].price > INITIAL_PRICE) {
                printf("\nInsufficient funds.\n");
                break;
            }
            stocks[i-1].price *= 1 + PERCENT_CHANGE / 100.0;
            printf("\nSuccessfully bought %d shares of %s.\n", choice, stocks[i-1].name);
            break;
        case 3:
            printf("\nEnter ID of stock to sell (1-%d): ", STOCK_COUNT);
            scanf("%d", &i);
            if (i < 1 || i > STOCK_COUNT) {
                printf("\nInvalid stock ID.\n");
                break;
            }
            printf("\nEnter number of shares to sell: ");
            scanf("%d", &choice);
            if (choice > 10) {
                printf("\nMaximum number of shares to sell is 10.\n");
                break;
            }
            if (choice > INITIAL_PRICE / stocks[i-1].price) {
                printf("\nCannot sell more shares than owned.\n");
                break;
            }
            stocks[i-1].price *= 1 - PERCENT_CHANGE / 100.0;
            printf("\nSuccessfully sold %d shares of %s.\n", choice, stocks[i-1].name);
            break;
        case 4:
            break;
        default:
            printf("\nInvalid choice.\n");
        }

        printf("\nPress enter to continue...");
        getchar();
        getchar(); // pause program until enter is pressed
    } while (choice != 4); // repeat until user chooses to quit

    return 0;
}