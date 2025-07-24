//FormAI DATASET v1.0 Category: Stock market tracker ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int stock_price = rand() % 150 + 50;
    int prev_price = 0;
    int curr_price = 0;
    int days_since_last_change = 0;
    int days_to_next_change = rand() % 6 + 5;
    int num_changes = 0;
    printf("Welcome to the surreal stock market tracker!\n\n");
    printf("Current price: %d\n", stock_price);
    while (num_changes < 10) {
        prev_price = curr_price;
        curr_price = rand() % 150 + 50;
        days_since_last_change++;
        if (days_since_last_change >= days_to_next_change) {
            stock_price = curr_price;
            printf("Price change! New price: %d\n", stock_price);
            days_since_last_change = 0;
            days_to_next_change = rand() % 6 + 5;
            num_changes++;
        }
        if (curr_price > prev_price) {
            printf("Upward trend detected!\n");
        } else if (curr_price < prev_price) {
            printf("Downward trend detected!\n");
        }
        printf("Current price: %d\n", stock_price);
        printf("Days until next change: %d\n\n", days_to_next_change);
    }
    printf("The surreal stock market tracker has completed tracking.\n");
    return 0;
}