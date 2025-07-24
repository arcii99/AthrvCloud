//FormAI DATASET v1.0 Category: Stock market tracker ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // initialize stock prices
    double stockA = 100.0;
    double stockB = 75.0;
    double stockC = 50.0;
    double stockD = 200.0;

    // initialize random seed
    srand(time(NULL));

    // loop to simulate stock market activity
    for (int i = 1; i <= 50; i++) {
        // generate random change in stock prices
        double changeA = (double)(rand() % 50 - 25) / 100.0;
        double changeB = (double)(rand() % 50 - 25) / 100.0;
        double changeC = (double)(rand() % 50 - 25) / 100.0;
        double changeD = (double)(rand() % 50 - 25) / 100.0;

        // update stock prices
        stockA += changeA * stockA;
        stockB += changeB * stockB;
        stockC += changeC * stockC;
        stockD += changeD * stockD;

        // print current stock prices
        printf("\nDay %d:\n", i);
        printf("Stock A: $%.2f\n", stockA);
        printf("Stock B: $%.2f\n", stockB);
        printf("Stock C: $%.2f\n", stockC);
        printf("Stock D: $%.2f\n", stockD);
    }

    return 0;
}