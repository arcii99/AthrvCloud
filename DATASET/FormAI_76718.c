//FormAI DATASET v1.0 Category: Stock market tracker ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    float stock_value = 100.00;
    printf("Welcome to the Mind-Bending Stock Market Tracker!\n");
    printf("Currently, the stock value is: $%.2f\n", stock_value);
    printf("Enter '0' to end the program.\n");
    srand(time(NULL));
    int input, day = 1;
    float variation;
    while (scanf("%d", &input) != EOF) {
        if (input == 0) {
            printf("Thank you for using the Mind-Bending Stock Market Tracker!\n");
            break;
        }
        variation = (rand() % 21 - 10) / 100.00;
        stock_value += stock_value * variation;
        printf("Day %d - Stock value: $%.2f (%+.2f%%)\n", day, stock_value, variation * 100);
        day++;
    }
    return 0;
}