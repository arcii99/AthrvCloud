//FormAI DATASET v1.0 Category: Stock market tracker ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int stock_prices[10];
    int sum = 0;
    float average = 0.0;
    printf("Welcome to the Retro Stock Market Tracker!\n\n");
    printf("Today's market update:\n");

    for (int i = 0; i < 10; i++) {
        stock_prices[i] = rand() % 200 + 1;
        sum += stock_prices[i];
        printf("Stock %d: $%d\n", i+1, stock_prices[i]);
    }

    printf("\nMarket Summary:\n");
    average = (float)sum / 10;
    printf("Average Stock Price: $%.2f\n", average);
    printf("Highest Stock Price: $%d\n", find_highest(stock_prices, 10));
    printf("Lowest Stock Price: $%d\n", find_lowest(stock_prices, 10));

    return 0;
}

int find_highest(int *arr, int size) {
    int highest = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > highest) {
            highest = arr[i];
        }
    }
    return highest;
}

int find_lowest(int *arr, int size) {
    int lowest = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < lowest) {
            lowest = arr[i];
        }
    }
    return lowest;
}