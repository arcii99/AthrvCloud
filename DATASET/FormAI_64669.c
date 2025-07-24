//FormAI DATASET v1.0 Category: Stock market tracker ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define MAX_STOCKS 10
#define MAX_NAME_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    float current_price;
} Stock;

Stock watchlist[MAX_STOCKS];

void display_menu() {
    printf("\n\n");
    printf("1. Add a stock to watchlist\n");
    printf("2. Update stock prices\n");
    printf("3. Display watchlist\n");
    printf("4. Exit program\n");
    printf("\n");
}

void add_stock() {
    char stock_name[MAX_NAME_LENGTH];
    float stock_price;
    int index = 0;
    while (watchlist[index].current_price != 0) {
        index++;
    }
    printf("Enter stock name: ");
    scanf("%s", stock_name);
    printf("Enter current stock price: ");
    scanf("%f", &stock_price);
    strcpy(watchlist[index].name, stock_name);
    watchlist[index].current_price = stock_price;
    printf("%s added to watchlist.\n", stock_name);
}

void update_prices() {
    for (int i = 0; i < MAX_STOCKS; i++) {
        if (watchlist[i].current_price != 0) {
            printf("Enter updated price for %s: ", watchlist[i].name);
            float updated_price;
            scanf("%f", &updated_price);
            watchlist[i].current_price = updated_price;
        }
    }
    printf("Stock prices updated.\n");
}

void display_watchlist() {
    printf("\nWatchlist:\n");
    printf("Stock Name\t\tCurrent Price\n");
    for (int i = 0; i < MAX_STOCKS; i++) {
        if (watchlist[i].current_price != 0) {
            printf("%s\t\t\t%.2f\n", watchlist[i].name, watchlist[i].current_price);
        }
    }
}

int main() {
    int choice;
    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_stock();
                break;
            case 2:
                update_prices();
                break;
            case 3:
                display_watchlist();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}