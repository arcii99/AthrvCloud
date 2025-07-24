//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STOCKS 10
#define MAX_NAME_LEN 20

typedef struct Stock {
    char name[MAX_NAME_LEN];
    double price;
    double change;
} Stock;

void initializeStocks(Stock stocks[]);
void updatePrices(Stock stocks[]);
void displayStocks(Stock stocks[]);
double generateRandomNumber(double min, double max);

int main() {

    srand(time(NULL));

    Stock stocks[MAX_STOCKS];

    initializeStocks(stocks);

    printf("Welcome to the Stock Market Tracker!\n\n");

    int choice = 0;

    while (choice != 4) {
        printf("Please select an option:\n");
        printf("1. Display stocks\n");
        printf("2. Update prices\n");
        printf("3. Display stock with highest change\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayStocks(stocks);
                break;
            case 2:
                updatePrices(stocks);
                break;
            case 3:
                {
                    double maxChange = 0.0;
                    int index = 0;

                    for (int i = 0; i < MAX_STOCKS; i++) {
                        if (stocks[i].change > maxChange) {
                            maxChange = stocks[i].change;
                            index = i;
                        }
                    }

                    printf("Stock with the highest change:\n");
                    printf("Name: %s\n", stocks[index].name);
                    printf("Price: %.2lf\n", stocks[index].price);
                    printf("Change: %.2lf%%\n", stocks[index].change);
                }
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        printf("\n");
    }

    return 0;
}

void initializeStocks(Stock stocks[]) {
    for (int i = 0; i < MAX_STOCKS; i++) {
        sprintf(stocks[i].name, "Stock %d", i + 1);
        stocks[i].price = generateRandomNumber(10.0, 100.0);
        stocks[i].change = 0.0;
    }
}

void updatePrices(Stock stocks[]) {
    for (int i = 0; i < MAX_STOCKS; i++) {
        double change = generateRandomNumber(-10.0, 10.0);
        stocks[i].change = change;
        stocks[i].price += stocks[i].price * (change/100.0);
    }

    printf("Prices updated!\n");
}

void displayStocks(Stock stocks[]) {
    printf("Current stock prices and changes:\n");

    for (int i = 0; i < MAX_STOCKS; i++) {
        printf("Name: %s\n", stocks[i].name);
        printf("Price: %.2lf\n", stocks[i].price);
        printf("Change: %.2lf%%\n", stocks[i].change);
    }
}

double generateRandomNumber(double min, double max) {
    return ((double)rand() / RAND_MAX) * (max - min) + min;
}