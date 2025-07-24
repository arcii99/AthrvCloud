//FormAI DATASET v1.0 Category: Stock market tracker ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    float stock_price = 100.00;
    float change_limit = 5.00;
    int iterations = 10;
    float current_price = stock_price;

    printf("Starting Stock Price: $%.2f\n\n", stock_price);

    for (int i = 0; i < iterations; i++) {
        float change = (float)(rand() % (int)(change_limit * 100)) / 100;
        int positive = rand() % 2;

        if (!positive) {
            change = -change;
        }

        current_price += change;

        printf("Iteration #%d\n", i + 1);
        printf("Price Change: $%.2f %s\n", change, positive ? "(+" : "(-)");
        printf("Current Stock Price: $%.2f\n\n", current_price);

        // randomly pause the program for 1-5 seconds
        int sleep_time = rand() % 5 + 1;
        printf("Sleeping for %d seconds...\n\n", sleep_time);
        sleep(sleep_time);
    }

    printf("Final Stock Price: $%.2f\n", current_price);

    return 0;
}