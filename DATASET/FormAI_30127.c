//FormAI DATASET v1.0 Category: Stock market tracker ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 50

typedef struct {
    char name[20];
    double price;
    double change;
} stock_t;

stock_t stocks[MAX_STOCKS];
int current_stock = 0; // current number of added stocks

void add_stock(char* name, double price, double change) {
    if (current_stock >= MAX_STOCKS) {
        printf("Cannot add more stocks.\n");
        return;
    }
    stock_t new_stock;
    strcpy(new_stock.name, name);
    new_stock.price = price;
    new_stock.change = change;
    stocks[current_stock++] = new_stock;
    printf("%s stock added.\n", name);
}

void remove_stock(char* name) {
    int index = -1;
    for (int i = 0; i < current_stock; i++) {
        if (strcmp(name, stocks[i].name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Cannot find %s stock.\n", name);
        return;
    }
    current_stock--;
    for (int i = index; i < current_stock; i++) {
        stocks[i] = stocks[i+1];
    }
    printf("%s stock removed.\n", name);
}

void update_stock(char* name, double price, double change) {
    int index = -1;
    for (int i = 0; i < current_stock; i++) {
        if (strcmp(name, stocks[i].name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Cannot find %s stock.\n", name);
        return;
    }
    stocks[index].price = price;
    stocks[index].change = change;
    printf("%s stock updated.\n", name);
}

void print_stock(char* name) {
    int index = -1;
    for (int i = 0; i < current_stock; i++) {
        if (strcmp(name, stocks[i].name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Cannot find %s stock.\n", name);
        return;
    }
    printf("%s stock:\n Price: %.2lf\n Change: %.2lf\n", stocks[index].name, stocks[index].price, stocks[index].change);
}

void print_all_stocks() {
    printf("All stocks:\n");
    for (int i = 0; i < current_stock; i++) {
        printf("%s:\n Price: %.2lf\n Change: %.2lf\n", stocks[i].name, stocks[i].price, stocks[i].change);
    }
}

int main() {
    add_stock("Google", 1521.91, 1.50);
    add_stock("Amazon", 3206.22, -0.23);
    add_stock("Apple", 120.96, 0.85);
    add_stock("Facebook", 295.30, 0.67);
    
    update_stock("Amazon", 3225.00, 0.39);
    remove_stock("Facebook");
    
    print_stock("Google");
    print_all_stocks();
    
    return 0;
}