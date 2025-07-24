//FormAI DATASET v1.0 Category: Stock market tracker ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSTOCKS 10

typedef struct {
    char symbol[10];
    float price;
} Stock;

int main()
{
    Stock stocks[MAXSTOCKS];
    int numStocks = 0;
    char input[10];

    while(1)
    {
        printf("\nEnter a stock symbol or 'done' to exit: ");
        scanf("%s", input);

        if(strcmp(input, "done") == 0)
        {
            printf("\nExiting...\n");
            break;
        }
        else if(numStocks == MAXSTOCKS)
        {
            printf("\nMax number of stocks reached!\n");
            continue;
        }
        // adding stock 
        else
        {
            strcpy(stocks[numStocks].symbol, input);
            printf("Enter the current price: ");
            scanf("%f", &stocks[numStocks].price);
            numStocks++;
        }
    }
    // print all stocks
    for(int i = 0; i < numStocks; i++)
    {
        printf("\n%s: %.2f", stocks[i].symbol, stocks[i].price);
    }

    return 0;
}