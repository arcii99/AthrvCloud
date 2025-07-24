//FormAI DATASET v1.0 Category: Stock market tracker ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STOCKS 100
#define MAX_NAME 20

struct stock {
    char name[MAX_NAME];
    float price;
};

void print_stock(struct stock s);
void print_all_stocks(struct stock stocks[], int count);
int add_stock(struct stock stocks[], int count, char name[], float price);
void update_stock(struct stock stocks[], int count, char name[], float new_price);

int main() {
    struct stock stocks[MAX_STOCKS];
    int count = 0;
    int choice;

    do {
        printf("\n\n1. Add a new stock\n2. Update an existing stock\n3. View all stocks\n4. Quit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                char name[MAX_NAME];
                float price;
                printf("\nEnter the name of the stock: ");
                scanf("%s", &name);
                printf("Enter the price of the stock: ");
                scanf("%f", &price);
                count = add_stock(stocks, count, name, price);
                break;

            case 2:
                char stock_name[MAX_NAME];
                float new_price;
                printf("\nEnter the name of the stock to update: ");
                scanf("%s", &stock_name);
                printf("Enter the new price of the stock: ");
                scanf("%f", &new_price);
                update_stock(stocks, count, stock_name, new_price);
                break;

            case 3:
                print_all_stocks(stocks, count);
                break;

            case 4:
                printf("\nGoodbye!\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

void print_stock(struct stock s) {
    printf("%s - $%.2f\n", s.name, s.price);
}

void print_all_stocks(struct stock stocks[], int count) {
    printf("\n\nAll stocks:\n");
    for (int i = 0; i < count; i++) {
        print_stock(stocks[i]);
    }
    printf("\n\n");
}

int add_stock(struct stock stocks[], int count, char name[], float price) {
    if (count >= MAX_STOCKS) {
        printf("\n\nError: Too many stocks. Could not add %s.\n", name);
        return count;
    }
    struct stock new_stock;
    strcpy(new_stock.name, name);
    new_stock.price = price;
    stocks[count] = new_stock;
    printf("\n\nSuccess: Added %s to the stock list.\n", name);
    return count + 1;
}

void update_stock(struct stock stocks[], int count, char name[], float new_price) {
    for (int i = 0; i < count; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            printf("\n\nSuccess: Updated the price of %s from $%.2f to $%.2f.\n", name, stocks[i].price, new_price);
            stocks[i].price = new_price;
            return;
        }
    }
    printf("\n\nError: Could not find %s in the stock list.\n", name);
}