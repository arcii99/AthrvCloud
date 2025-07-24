//FormAI DATASET v1.0 Category: Stock market tracker ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum length of company name
#define MAX_COMPANY_NAME     25

// Define the maximum length of stock symbol
#define MAX_STOCK_SYMBOL     10

// Define the maximum number of companies
#define MAX_COMPANIES        1000

// Define the maximum stock price change percentage
#define MAX_PRICE_CHANGE     10

// Define the maximum number of days
#define MAX_DAYS             30

// Define the data structure of the company
typedef struct {
    char name[MAX_COMPANY_NAME];
    char symbol[MAX_STOCK_SYMBOL];
    float price;
} Company;

// Define the data structure of the stock market
typedef struct {
    Company companies[MAX_COMPANIES];
    int numCompanies;
} StockMarket;

// Define a helper function to generate a random float number between min and max
float randomFloat(float min, float max) {
    float range = max - min;
    float n = rand() / (float)RAND_MAX;
    float result = min + n * range;
    return result;
}

// Define a helper function to generate a random price change percentage
float randomPriceChange() {
    float result = randomFloat(-MAX_PRICE_CHANGE, MAX_PRICE_CHANGE);
    return result;
}

// Define a function to initialize the stock market
void initStockMarket(StockMarket *market) {
    int i;
    market->numCompanies = 0;
    for (i = 0; i < MAX_COMPANIES; i++) {
        market->companies[i].name[0] = '\0';
        market->companies[i].symbol[0] = '\0';
        market->companies[i].price = 0;
    }
}

// Define a function to add a company to the stock market
void addCompany(StockMarket *market, char *name, char *symbol, float price) {
    if (market->numCompanies < MAX_COMPANIES) {
        Company *c = &(market->companies[market->numCompanies]);
        strncpy(c->name, name, MAX_COMPANY_NAME);
        strncpy(c->symbol, symbol, MAX_STOCK_SYMBOL);
        c->price = price;
        market->numCompanies++;
    }
}

// Define a function to update the stock prices of the companies in the stock market
void updateStockPrices(StockMarket *market) {
    int i;
    for (i = 0; i < market->numCompanies; i++) {
        Company *c = &(market->companies[i]);
        float priceChange = randomPriceChange();
        c->price = c->price * (1 + priceChange / 100);
    }
}

// Define a function to print the stock prices of the companies in the stock market
void printStockPrices(StockMarket *market) {
    int i;
    printf("Company Name\tSymbol\tPrice\n");
    for (i = 0; i < market->numCompanies; i++) {
        Company *c = &(market->companies[i]);
        printf("%s\t\t%s\t%.2f\n", c->name, c->symbol, c->price);
    }
}

// Define the main function to test the stock market tracker
int main() {
    srand(time(0));

    StockMarket market;
    initStockMarket(&market);

    addCompany(&market, "Apple Inc", "AAPL", 145.96);
    addCompany(&market, "Microsoft Corporation", "MSFT", 258.74);
    addCompany(&market, "Amazon.com Inc", "AMZN", 3344.88);
    addCompany(&market, "Facebook Inc", "FB", 342.29);
    addCompany(&market, "Google LLC", "GOOGL", 2733.91);

    int day;
    for (day = 1; day <= MAX_DAYS; day++) {
        printf("Day %d:\n", day);
        updateStockPrices(&market);
        printStockPrices(&market);
        printf("\n");
    }

    return 0;
}