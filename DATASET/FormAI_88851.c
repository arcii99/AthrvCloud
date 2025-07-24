//FormAI DATASET v1.0 Category: Stock market tracker ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STOCKS 10  // Maximum number of stocks that can be tracked
#define MAX_NAME_LENGTH 20 // Maximum length of stock names
#define MAX_HISTORY 5 // Maximum number of past prices that can be stored

typedef struct Stock { 
    char name[MAX_NAME_LENGTH];
    double current_price;
    double history[MAX_HISTORY]; // Stores past prices
    int history_count; // Keeps track of number of past prices stored
} Stock;

void add_stock(Stock stocks[], int *num_stocks); // Adds a new stock to the tracker
void remove_stock(Stock stocks[], int *num_stocks); // Removes a stock from the tracker
void view_stock(Stock stocks[], int num_stocks); // Displays information about a specific stock
void view_all_stocks(Stock stocks[], int num_stocks); // Displays information about all tracked stocks
void update_stock(Stock *stock); // Updates the current price of a stock
void display_menu(); // Displays the program menu

int main() {
    Stock stocks[MAX_STOCKS]; // Array of all tracked stocks
    int num_stocks = 0; // Number of stocks currently being tracked
    char input[10]; // Stores user input
    
    bool program_running = true; // Flag to indicate if program is still running
    
    while (program_running) {
        display_menu();
        printf("Enter your choice: ");
        fgets(input, 10, stdin);
        char *pos;
        if ((pos = strchr(input, '\n')) != NULL) {
            *pos = '\0';
        }
        int choice = atoi(input);
        switch (choice) {
            case 1:
                add_stock(stocks, &num_stocks);
                break;
            case 2:
                remove_stock(stocks, &num_stocks);
                break;
            case 3:
                view_stock(stocks, num_stocks);
                break;
            case 4:
                view_all_stocks(stocks, num_stocks);
                break;
            case 5:
                program_running = false;
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
                break;
        }
    }
    printf("Exiting program.");
    return 0;
}

void add_stock(Stock stocks[], int *num_stocks) {
    if (*num_stocks == MAX_STOCKS) {
        printf("You have reached the maximum number of tracked stocks.\n");
        return;
    }
    Stock new_stock;
    printf("Enter the name of the stock: ");
    fgets(new_stock.name, MAX_NAME_LENGTH, stdin);
    char *pos;
    if ((pos = strchr(new_stock.name, '\n')) != NULL) {
        *pos = '\0';
    }
    printf("Enter the current price of the stock: ");
    char price[10];
    fgets(price, 10, stdin);
    new_stock.current_price = atof(price);
    new_stock.history_count = 1;
    new_stock.history[0] = new_stock.current_price;
    stocks[*num_stocks] = new_stock;
    *num_stocks += 1;
    printf("Stock added successfully!\n");
}

void remove_stock(Stock stocks[], int *num_stocks) {
    if (*num_stocks == 0) {
        printf("There are no stocks to remove.\n");
        return;
    }
    view_all_stocks(stocks, *num_stocks);
    printf("Which stock do you want to remove? Enter its number: ");
    char input[10];
    fgets(input, 10, stdin);
    int stock_index = atoi(input) - 1;
    if (stock_index < 0 || stock_index >= *num_stocks) {
        printf("Invalid input.\n");
        return;
    }
    for (int i = stock_index; i < *num_stocks - 1; i++) {
        stocks[i] = stocks[i+1];
    }
    *num_stocks -= 1;
    printf("Stock removed successfully!\n");
}

void view_stock(Stock stocks[], int num_stocks) {
    if (num_stocks == 0) {
        printf("There are no stocks to view.\n");
        return;
    }
    view_all_stocks(stocks, num_stocks);
    printf("Which stock do you want to view? Enter its number: ");
    char input[10];
    fgets(input, 10, stdin);
    int stock_index = atoi(input) - 1;
    if (stock_index < 0 || stock_index >= num_stocks) {
        printf("Invalid input.\n");
        return;
    }
    Stock stock = stocks[stock_index];
    printf("Name: %s\n", stock.name);
    printf("Current price: $%.2lf\n", stock.current_price);
    printf("Past prices: ");
    for (int i = 0; i < stock.history_count; i++) {
        printf("$%.2lf", stock.history[i]);
        if (i != stock.history_count - 1) {
            printf(", ");
        } else {
            printf("\n");
        }
    }
}

void view_all_stocks(Stock stocks[], int num_stocks) {
    if (num_stocks == 0) {
        printf("There are no stocks to view.\n");
        return;
    }
    printf("Tracked Stocks:\n");
    for (int i = 0; i < num_stocks; i++) {
        Stock stock = stocks[i];
        printf("%d. %s ($%.2lf)\n", i+1, stock.name, stock.current_price);
    }
}

void update_stock(Stock *stock) {
    printf("Current price for %s is $%.2lf.\n", stock->name, stock->current_price);
    char input[10];
    printf("Enter new price: ");
    fgets(input, 10, stdin);
    stock->current_price = atof(input);
    if (stock->history_count < MAX_HISTORY) {
        stock->history[stock->history_count] = stock->current_price;
        stock->history_count += 1;
    } else {
        for (int i = 0; i < MAX_HISTORY - 1; i++) {
            stock->history[i] = stock->history[i+1];
        }
        stock->history[MAX_HISTORY-1] = stock->current_price;
    }
    printf("Price updated successfully!\n");
}

void display_menu() {
    printf("\n");
    printf("Stock Tracker\n");
    printf("1. Add a new stock\n");
    printf("2. Remove a stock\n");
    printf("3. View a specific stock\n");
    printf("4. View all tracked stocks\n");
    printf("5. Exit program\n");
}