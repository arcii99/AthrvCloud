//FormAI DATASET v1.0 Category: Stock market tracker ; Style: paranoid
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Paranoid Stock Market Tracker!\n");

    srand(time(NULL));

    int currentValue = rand() % 100; // Starting point for stock value
    int currentChange = 0; // Amount the stock value will change by
    int currentDay = 1; // Keep track of the days
    int i;

    printf("Starting stock value: $%d\n", currentValue);

    for(i = 0; i < 50; i++) {
        if(currentValue < 20) {
            printf("The stock is crashing!!! Sell now before it's too late!!\n");
            break;
        }
        else if(currentValue > 80 && currentChange > 0) {
            printf("The stock is soaring!! Buy now before it gets too high!!\n");
        }
        printf("Day %d | Current value: $%d | Change for the day: %d\n", currentDay, currentValue, currentChange);

        currentChange = (rand() % 20) - 10; // Randomly change value between -10 to +10
        currentValue += currentChange; // Change current value by current change
        currentDay++; // Increment the day by 1

        if(currentChange < -5) {
            printf("Warning! Sudden drop in stock value detected. Keep a close eye on this!\n");
        }
        else if(currentChange > 5) {
            printf("Watch out! The stock value is rising rapidly! Keep an eye out for any sudden drops!\n");
        }
    }

    printf("Final stock value: $%d\n", currentValue);

    return 0;
}