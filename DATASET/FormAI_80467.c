//FormAI DATASET v1.0 Category: Stock market tracker ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STOCKS 10
#define MAX_NAME 50
#define MAX_HISTORY 365

typedef struct {
    char name[MAX_NAME];
    double price;
    int history[MAX_HISTORY];
} Stock;

int getCountOfStocks(Stock *stocks) {
    int count = 0;
    
    while (stocks[count].name[0] != '\0')
        count++;
    
    return count;
}

void displayStock(Stock stock) {
    printf("%s: $%.2lf\n", stock.name, stock.price);
}

void displayAllStocks(Stock *stocks) {
    int count = getCountOfStocks(stocks);
    
    if (count == 0) {
        printf("No stocks found.\n");
        return;
    }
    
    for (int i = 0; i < count; i++)
        displayStock(stocks[i]);
}

void updateStockPrices(Stock *stocks) {
    int count = getCountOfStocks(stocks);
    
    srand(time(NULL));
    
    for (int i = 0; i < count; i++) {
        double price = (double) rand() / RAND_MAX * 100.0;
        
        stocks[i].price = price;
        stocks[i].history[0] = price;
        
        for (int j = 1; j < MAX_HISTORY; j++) {
            int sign = (rand() % 2 == 0) ? -1 : 1;
            double delta = (double) rand() / RAND_MAX * 5.0;
            
            stocks[i].history[j] = stocks[i].history[j-1] + sign * delta;
        }
    }
}

void displayStockHistory(Stock stock) {
    printf("Price history for %s:\n", stock.name);
    
    for (int i = 0; i < MAX_HISTORY; i++) {
        if (stock.history[i] == 0)
            break;
        
        printf("%.2lf, ", stock.history[i]);
    }
    
    printf("\n");
}

int main() {
    printf("Welcome to the Stock Market Tracker!\n");
    
    Stock stocks[MAX_STOCKS] = {
        {"AAPL", 0, {0}},
        {"GOOG", 0, {0}},
        {"AMZN", 0, {0}},
        {"MSFT", 0, {0}},
        {"FB", 0, {0}},
        {"NFLX", 0, {0}},
        {"TSLA", 0, {0}},
        {"NVDA", 0, {0}},
        {"PYPL", 0, {0}},
        {"ADBE", 0, {0}}
    };
    
    updateStockPrices(stocks);
    
    int choice;
    
    do {
        printf("\n1. Display all stocks\n");
        printf("2. Display stock history\n");
        printf("3. Update stock prices\n");
        printf("4. Quit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                displayAllStocks(stocks);
                break;
            case 2: {
                char stockName[MAX_NAME];
                printf("Please enter the stock name: ");
                scanf("%s", stockName);
                
                int count = getCountOfStocks(stocks);
                Stock stock = {"", 0, {0}};
                
                for (int i = 0; i < count; i++) {
                    if (strcmp(stockName, stocks[i].name) == 0) {
                        stock = stocks[i];
                        break;
                    }
                }
                
                if (stock.name[0] == '\0') {
                    printf("Stock not found.\n");
                    break;
                }
                
                displayStockHistory(stock);
                break;
            }
            case 3:
                updateStockPrices(stocks);
                printf("Stock prices have been updated.\n");
                break;
            case 4:
                printf("Thank you for using the Stock Market Tracker!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}