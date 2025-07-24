//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 10
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    float current_price;
    float previous_price;
} Stock;

void generate_random_stock(Stock *s) {
    char names[10][MAX_NAME_LENGTH] = {"AAPL", "GOOGL", "MSFT", "FB", "AMZN", "TSLA", "NFLX", "NVDA", "AMD", "INTC"};
    int name_index = rand() % 10;
    strcpy(s->name, names[name_index]);
    s->previous_price = rand() % 1000 + 1;
    s->current_price = s->previous_price + ((rand() % 21) - 10) / 10.0;
}

void print_stock(Stock *s) {
    printf("%s : Current price - %.2f, Previous price - %.2f\n", s->name, s->current_price, s->previous_price);
}

int main() {
    srand(time(NULL));
    Stock stocks[MAX_STOCKS];
    int i, choice;
    for (i = 0; i < MAX_STOCKS; i++) {
        generate_random_stock(&stocks[i]);
    }
    do {
        printf("Choose an option:\n");
        printf("1. Print current prices of all stocks.\n");
        printf("2. Print a particular stock's details.\n");
        printf("3. Buy a stock.\n");
        printf("4. Sell a stock.\n");
        printf("5. Exit program.\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                for (i = 0; i < MAX_STOCKS; i++) {
                    print_stock(&stocks[i]);
                }
                break;
            case 2:
                printf("Enter stock name: ");
                char name[MAX_NAME_LENGTH];
                scanf("%s", name);
                for (i = 0; i < MAX_STOCKS; i++) {
                    if (strcmp(stocks[i].name, name) == 0) {
                        print_stock(&stocks[i]);
                        break;
                    }
                }
                if (i == MAX_STOCKS) {
                    printf("Stock not found.\n");
                }
                break;
            case 3:
                printf("Enter stock name: ");
                scanf("%s", name);
                for (i = 0; i < MAX_STOCKS; i++) {
                    if (strcmp(stocks[i].name, name) == 0) {
                        printf("Enter number of stocks to buy: ");
                        int quantity;
                        scanf("%d", &quantity);
                        stocks[i].previous_price = stocks[i].current_price;
                        stocks[i].current_price += ((rand() % 21) - 10) / 10.0;
                        printf("%d stocks of %s bought at %.2f per stock.\n", quantity, stocks[i].name, stocks[i].current_price);
                        break;
                    }
                }
                if (i == MAX_STOCKS) {
                    printf("Stock not found.\n");
                }
                break;
            case 4:
                printf("Enter stock name: ");
                scanf("%s", name);
                for (i = 0; i < MAX_STOCKS; i++) {
                    if (strcmp(stocks[i].name, name) == 0) {
                        printf("Enter number of stocks to sell: ");
                        int quantity;
                        scanf("%d", &quantity);
                        stocks[i].previous_price = stocks[i].current_price;
                        stocks[i].current_price += ((rand() % 21) - 10) / 10.0;
                        printf("%d stocks of %s sold at %.2f per stock.\n", quantity, stocks[i].name, stocks[i].current_price);
                        break;
                    }
                }
                if (i == MAX_STOCKS) {
                    printf("Stock not found.\n");
                }
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 5);
    return 0;
}