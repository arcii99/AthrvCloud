//FormAI DATASET v1.0 Category: Stock market tracker ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_STOCKS 100

typedef struct Stock {
    char symbol[10];
    double price;
    double change;
} Stock;

int get_num_of_stocks() {
    int num_of_stocks;
    printf("Enter the number of stocks you want to track (1-100): ");
    scanf("%d", &num_of_stocks);
    if (num_of_stocks < 1 || num_of_stocks > MAX_STOCKS) {
        printf("Invalid input. Number of stocks must be between 1 and 100.\n");
        return get_num_of_stocks();
    } else {
        return num_of_stocks;
    }
}

void get_stock_data(Stock stocks[], int num_of_stocks) {
    printf("\nEnter the stock data:\n");
    for (int i = 0; i < num_of_stocks; i++) {
        printf("Stock %d Symbol: ", i + 1);
        scanf("%s", stocks[i].symbol);
        printf("Stock %d Price: ", i + 1);
        scanf("%lf", &stocks[i].price);
        printf("Stock %d Change: ", i + 1);
        scanf("%lf", &stocks[i].change);
    }
}

void print_stock_data(Stock stocks[], int num_of_stocks, int count) {
    int current_stock = count + 1;
    printf("\nStock %d Symbol: %s\n", current_stock, stocks[count].symbol);
    printf("Stock %d Price: %.2lf\n", current_stock, stocks[count].price);
    printf("Stock %d Change: %.2lf\n", current_stock, stocks[count].change);
    if (count == num_of_stocks - 1) {
        return;
    } else {
        print_stock_data(stocks, num_of_stocks, count + 1);
    }
}

void recursive_menu(Stock stocks[], int num_of_stocks) {
    int choice;
    printf("\n*****Menu*****\n");
    printf("1. View stock data\n");
    printf("2. Update stock data\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            print_stock_data(stocks, num_of_stocks, 0);
            recursive_menu(stocks, num_of_stocks);
            break;
        case 2:
            printf("\nEnter the stock number you want to update (1-%d): ", num_of_stocks);
            int stock_choice;
            scanf("%d", &stock_choice);
            if (stock_choice < 1 || stock_choice > num_of_stocks) {
                printf("Invalid input. Stock number must be between 1 and %d.\n", num_of_stocks);
                recursive_menu(stocks, num_of_stocks);
                break;
            }
            printf("\nEnter the stock data:\n");
            printf("Stock %d Symbol: ", stock_choice);
            scanf("%s", stocks[stock_choice - 1].symbol);
            printf("Stock %d Price: ", stock_choice);
            scanf("%lf", &stocks[stock_choice - 1].price);
            printf("Stock %d Change: ", stock_choice);
            scanf("%lf", &stocks[stock_choice - 1].change);
            recursive_menu(stocks, num_of_stocks);
            break;
        case 3:
            printf("\nExiting stock market tracker...");
            break;
        default:
            printf("Invalid input. Please enter a valid choice.\n");
            recursive_menu(stocks, num_of_stocks);
            break;
    }
}

int main() {
    printf("Welcome to stock market tracker!\n");
    int num_of_stocks = get_num_of_stocks();
    Stock stocks[num_of_stocks];
    get_stock_data(stocks, num_of_stocks);
    recursive_menu(stocks, num_of_stocks);

    return 0;
}