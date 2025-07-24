//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 5
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int price;
} Stock;

void printMenu();
void updateStockPrices(Stock *stocks, int numStocks);
void printStocks(Stock *stocks, int numStocks);
void sortStocks(Stock *stocks, int numStocks);
void searchStocks(Stock *stocks, int numStocks);

int main() {
    srand(time(NULL));

    Stock stocks[MAX_STOCKS];

    // Initialize stocks
    strcpy(stocks[0].name, "ACME");
    strcpy(stocks[1].name, "GLOBEX");
    strcpy(stocks[2].name, "OMEGA");
    strcpy(stocks[3].name, "ZAP");
    strcpy(stocks[4].name, "XYZ");

    for (int i = 0; i < MAX_STOCKS; i++) {
        stocks[i].price = rand() % 100 + 1;
    }

    int choice = 0;

    do {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                updateStockPrices(stocks, MAX_STOCKS);
                break;
            case 2:
                printStocks(stocks, MAX_STOCKS);
                break;
            case 3:
                sortStocks(stocks, MAX_STOCKS);
                break;
            case 4:
                searchStocks(stocks, MAX_STOCKS);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }

    } while (choice != 5);

    return 0;
}

void printMenu() {
    printf("\nStock Market Tracker\n\n");
    printf("1. Update Stock Prices\n");
    printf("2. View Stock Prices\n");
    printf("3. Sort Stocks\n");
    printf("4. Search Stocks\n");
    printf("5. Exit\n\n");
    printf("Enter your choice: ");
}

void updateStockPrices(Stock *stocks, int numStocks) {
    for (int i = 0; i < numStocks; i++) {
        stocks[i].price = rand() % 100 + 1;
    }

    printf("\nStock prices updated.\n");
}

void printStocks(Stock *stocks, int numStocks) {
    printf("\nStock Prices:\n");
    printf("--------------------\n");

    for (int i = 0; i < numStocks; i++) {
        printf("%-8s%-8d\n", stocks[i].name, stocks[i].price);
    }

    printf("--------------------\n");
}

void sortStocks(Stock *stocks, int numStocks) {
    Stock temp;

    for (int i = 0; i < numStocks - 1; i++) {
        for (int j = i + 1; j < numStocks; j++) {
            if (strcmp(stocks[i].name, stocks[j].name) > 0) {
                temp = stocks[i];
                stocks[i] = stocks[j];
                stocks[j] = temp;
            }
        }
    }

    printf("\nStocks sorted alphabeticaly.\n");
}

void searchStocks(Stock *stocks, int numStocks) {
    char search[MAX_NAME_LENGTH];
    int found = 0;

    printf("\nEnter stock name to search for: ");
    scanf("%s", search);

    for (int i = 0; i < numStocks; i++) {
        if (strcmp(search, stocks[i].name) == 0) {
            printf("\nStock found:\n");
            printf("--------------------\n");
            printf("%-8s%-8d\n", stocks[i].name, stocks[i].price);
            printf("--------------------\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nStock not found.\n");
    }
}