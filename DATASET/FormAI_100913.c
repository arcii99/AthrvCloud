//FormAI DATASET v1.0 Category: Stock market tracker ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* define constant variables */
#define MAX_STOCKS 5
#define MAX_NAME_LENGTH 25

/* function prototypes */
void printStocks(char stocks[][MAX_NAME_LENGTH], double prices[], int numStocks);
void updatePrices(double prices[], int numStocks);

/* main function */
int main()
{
    /* declare and initialize variables */
    char stocks[MAX_STOCKS][MAX_NAME_LENGTH] = {"GOOG", "AAPL", "TSLA", "AMZN", "NFLX"};
    double prices[MAX_STOCKS] = {1523.00, 125.00, 705.00, 2776.00, 518.00};
    int numStocks = MAX_STOCKS;

    /* print initial stocks and prices */
    printf("Initial Stocks and Prices:\n");
    printStocks(stocks, prices, numStocks);

    /* simulate changes in stock prices over time */
    int i;
    for(i = 0; i < 10; i++)
    {
        printf("\nUpdate %d:\n", i+1);
        updatePrices(prices, numStocks);
        printStocks(stocks, prices, numStocks);
    }

    /* end of program */
    printf("\nProgram finished.\n");
    return 0;
}

/* function to print stocks and prices */
void printStocks(char stocks[][MAX_NAME_LENGTH], double prices[], int numStocks)
{
    int i;
    for(i = 0; i < numStocks; i++)
    {
        printf("%-5s $%.2lf\n", stocks[i], prices[i]);
    }
}

/* function to update stock prices randomly */
void updatePrices(double prices[], int numStocks)
{
    int i;
    for(i = 0; i < numStocks; i++)
    {
        double change = (double)(rand() % 500) / 100;
        if(rand() % 2 == 0)
            prices[i] += change;
        else
            prices[i] -= change;

        /* make sure prices don't go below zero */
        if(prices[i] < 0)
            prices[i] = 0;
    }
}