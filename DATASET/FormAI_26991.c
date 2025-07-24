//FormAI DATASET v1.0 Category: Stock market tracker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Generate random numbers to simulate changes in stock prices
    srand(time(NULL));
    int stockA = 100;
    int stockB = 200;
    int stockC = 300;

    // Keep track of the current shape of the stock market
    int shape = 0;

    // Set up the initial shape
    printf("Initial state: Stock A $%d, Stock B $%d, Stock C $%d\n", stockA, stockB, stockC);
    if (stockA < stockB && stockB < stockC) {
        shape = 1;
        printf("Shape 1: Ascending\n\n");
    } else if (stockC < stockB && stockB < stockA) {
        shape = 2;
        printf("Shape 2: Descending\n\n");
    } else {
        shape = 3;
        printf("Shape 3: Mixed\n\n");
    }

    // Continuously update the stock prices and track the shape of the stock market
    while (1) {
        // Generate a random number to determine which stock to update
        int randNum = rand() % 3;

        // Update the stock prices
        switch (randNum) {
            case 0:
                stockA += (rand() % 10) - 5;
                break;
            case 1:
                stockB += (rand() % 10) - 5;
                break;
            case 2:
                stockC += (rand() % 10) - 5;
                break;
        }

        // Determine the shape of the stock market based on the current stock prices
        if (stockA < stockB && stockB < stockC) {
            if (shape != 1) {
                printf("Shape 1: Ascending\n\n");
                shape = 1;
            }
        } else if (stockC < stockB && stockB < stockA) {
            if (shape != 2) {
                printf("Shape 2: Descending\n\n");
                shape = 2;
            }
        } else {
            if (shape != 3) {
                printf("Shape 3: Mixed\n\n");
                shape = 3;
            }
        }

        // Print the current stock prices
        printf("Stock A $%d, Stock B $%d, Stock C $%d\n", stockA, stockB, stockC);
        printf("Press Ctrl+C to exit\n\n");
        sleep(1);
    }

    return 0;
}