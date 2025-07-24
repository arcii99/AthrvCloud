//FormAI DATASET v1.0 Category: Stock market tracker ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator

    int prices[100]; // array to store the prices
    prices[0] = rand() % 1000; // initialize the first element with a random value between 0-999

    printf("Initial Price: %d\n", prices[0]);

    for (int i = 1; i < 100; i++) {
        int change = rand() % 101 - 50; // generate a random change between -50 and 50
        prices[i] = prices[i-1] + change; // update the price with the change
        printf("Day %d: %d\n", i, prices[i]);
    }

    return 0;
}