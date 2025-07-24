//FormAI DATASET v1.0 Category: Stock market tracker ; Style: cheerful
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seeding the random number generator

    int stockPrices[10] = {100, 200, 150, 250, 300, 275, 225, 175, 125, 225}; // initial stockPrices

    for (int i = 0; i < 10; i++) { // loop for 10 times, simulating 10 trading days
        int random = rand() % 6 - 2; // generating a random number between -2 and 3
        stockPrices[i] += random * 10; // adjusting the stock price by the random number
        printf("Day %d: ", i+1);

        if (random < 0) { // if the random number is negative, show a sad face :(
            printf("\u2639 ");
        } else { // otherwise, show a happy face :)
            printf("\u263A ");
        }

        printf("%d\n", stockPrices[i]); // print the adjusted stock price
    }

    return 0;
}