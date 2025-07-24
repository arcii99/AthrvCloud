//FormAI DATASET v1.0 Category: Stock market tracker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 10
#define NAME_LENGTH 20
#define MAX_PRICE 500
#define MIN_PRICE 100
#define MAX_CHANGE 20

typedef struct {
    char name[NAME_LENGTH];
    double price;
    double change_percent;
} Stock;

Stock createStock(char name[])
{
    Stock stock;
    strcpy(stock.name, name);

    stock.price = (double)(rand() % (MAX_PRICE - MIN_PRICE + 1) + MIN_PRICE);

    stock.change_percent = (double)(rand() % MAX_CHANGE) - (double)(rand() % MAX_CHANGE);

    return stock;
}

void printStock(Stock stock)
{
    printf("%-20s $%7.2f %c%6.2f%%", stock.name, stock.price, (stock.change_percent >= 0) ? '+' : '-', stock.change_percent);
}

void updateStock(Stock *stock)
{
    double change_percent = (double)(rand() % MAX_CHANGE) - (double)(rand() % MAX_CHANGE);

    stock->price = stock->price * (1 + (change_percent / 100));

    stock->change_percent = change_percent;
}

int main()
{
    srand(time(NULL));

    Stock portfolio[MAX_STOCKS] = {
        createStock("AAPL"),
        createStock("GOOG"),
        createStock("AMZN"),
        createStock("FB"),
        createStock("MSFT"),
        createStock("TSLA"),
        createStock("NVDA"),
        createStock("JPM"),
        createStock("BA"),
        createStock("NKE")
    };

    printf("%-20s %-10s %-10s", "Name", "Price", "Change");
    printf("\n--------------------------------------------------------");
    printf("\n");

    while (1)
    {
        for (int i = 0; i < MAX_STOCKS; i++)
        {
            updateStock(&portfolio[i]);
            printStock(portfolio[i]);
            printf("\n");
        }

        printf("\n");

        // Wait for 5 seconds
        for (int i = 0; i < 5; i++)
        {
            printf("Waiting %d seconds...\n", 5 - i);
            sleep(1);
        }

        system("clear");
        printf("%-20s %-10s %-10s", "Name", "Price", "Change");
        printf("\n--------------------------------------------------------");
        printf("\n");
    }

    return 0;
}