//FormAI DATASET v1.0 Category: Stock market tracker ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize variables
    int stock_price = 100;
    int day_count = 0;
    srand(time(NULL));

    // Loop for 50 days
    while (day_count < 50) {
        // Generate a random change between -5 and 5
        int change = rand() % 11 - 5;
        stock_price += change;

        // Print out the stock price for that day
        printf("Day %d: $%d\n", day_count + 1, stock_price);

        // Check if there was a significant change in price
        if (change > 2 || change < -2) {
            if (change > 0) {
                printf("The stock price increased by %d\n", change);
            } else {
                printf("The stock price decreased by %d\n", -change);
            }
        } else {
            printf("The stock price did not change significantly\n");
        }

        // Increment the day count
        day_count++;
    }

    return 0;
}