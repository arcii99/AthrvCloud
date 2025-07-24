//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Romeo and Juliet
// Romeo and Juliet's Stock Market Tracker

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STOCKS 10
#define MAX_NAME_LEN 20

typedef struct Stock {
    char name[MAX_NAME_LEN];
    float price;
    float change;
} Stock;

typedef struct Portfolio {
    Stock stocks[MAX_STOCKS];
    int num_of_stocks;
    float portfolio_value;
} Portfolio;

void print_portfolio(Portfolio *p);
void add_stock(Portfolio *p, Stock *s);
void remove_stock(Portfolio *p, char *name);
void update_prices(Portfolio *p);

int main() {
    Portfolio romeo_portfolio = { .num_of_stocks = 0, .portfolio_value = 0 };
    Portfolio juliet_portfolio = { .num_of_stocks = 0, .portfolio_value = 0 };
    
    Stock apple = { .name = "Apple Inc.", .price = 151.12, .change = -0.87 };
    Stock microsoft = { .name = "Microsoft Corp.", .price = 294.38, .change = 1.55 };
    Stock tesla = { .name = "Tesla, Inc.", .price = 709.44, .change = -0.32 };
    
    add_stock(&romeo_portfolio, &apple);
    add_stock(&romeo_portfolio, &microsoft);
    add_stock(&juliet_portfolio, &tesla);
    
    printf("Welcome to Romeo and Juliet's Stock Market Tracker!\n");
    printf("Here are your portfolios:\n\n");
    printf("Romeo's Portfolio:\n");
    print_portfolio(&romeo_portfolio);
    printf("\nJuliet's Portfolio:\n");
    print_portfolio(&juliet_portfolio);
    printf("\n");
    
    update_prices(&romeo_portfolio);
    update_prices(&juliet_portfolio);
    
    printf("After today's trading session, here are your updated portfolios:\n\n");
    printf("Romeo's Portfolio:\n");
    print_portfolio(&romeo_portfolio);
    printf("\nJuliet's Portfolio:\n");
    print_portfolio(&juliet_portfolio);
    printf("\n");
    
    remove_stock(&romeo_portfolio, "Microsoft Corp.");
    add_stock(&juliet_portfolio, &microsoft);
    
    update_prices(&romeo_portfolio);
    update_prices(&juliet_portfolio);
    
    printf("After some changes, here are your updated portfolios:\n\n");
    printf("Romeo's Portfolio:\n");
    print_portfolio(&romeo_portfolio);
    printf("\nJuliet's Portfolio:\n");
    print_portfolio(&juliet_portfolio);
    printf("\n");

    return 0;
}

void print_portfolio(Portfolio *p) {
    for (int i = 0; i < p->num_of_stocks; i++) {
        printf("%s: $%.2f (%+.2f%%)\n", p->stocks[i].name, p->stocks[i].price, p->stocks[i].change);
    }
    printf("Total Portfolio Value: $%.2f\n", p->portfolio_value);
}

void add_stock(Portfolio *p, Stock *s) {
    if (p->num_of_stocks >= MAX_STOCKS) {
        printf("Error: Maximum number of stocks reached\n");
        return;
    }
    p->stocks[p->num_of_stocks] = *s;
    p->portfolio_value += s->price;
    p->num_of_stocks++;
}

void remove_stock(Portfolio *p, char *name) {
    bool found = false;
    for (int i = 0; i < p->num_of_stocks; i++) {
        if (strcmp(p->stocks[i].name, name) == 0) {
            p->portfolio_value -= p->stocks[i].price;
            for (int j = i; j < p->num_of_stocks - 1; j++) {
                p->stocks[j] = p->stocks[j+1];
            }
            p->num_of_stocks--;
            found = true;
            break;
        }
    }
    if (!found) {
        printf("Error: Stock not found\n");
        return;
    }
}

void update_prices(Portfolio *p) {
    for (int i = 0; i < p->num_of_stocks; i++) {
        float new_price = p->stocks[i].price * (1 + (p->stocks[i].change / 100));
        p->portfolio_value += (new_price - p->stocks[i].price);
        p->stocks[i].price = new_price;
    }
}