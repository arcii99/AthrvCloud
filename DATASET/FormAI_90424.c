//FormAI DATASET v1.0 Category: Stock market tracker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    float stocks[5] = {20.25, 30.50, 40.00, 50.75, 60.25};
    float currPrice[5];
    int i;

    // Generate current prices with +/- 10% variation
    for (i = 0; i < 5; i++) {
        float var = (rand() % 21) / 100.0; // Generate variation between 0-0.2
        if (rand() % 2 == 0) {
            currPrice[i] = stocks[i] * (1.0 + var); // Increase price
        } else {
            currPrice[i] = stocks[i] * (1.0 - var); // Decrease price
        }
    }

    printf("Stock prices:\n");
    for (i = 0; i < 5; i++) {
        printf("Stock %d: Original Price=%0.2f, Current Price=%0.2f, Variation=%0.2f%%\n", i+1, stocks[i], currPrice[i], ((currPrice[i]-stocks[i])/stocks[i])*100);
    }

    // Find highest and lowest priced stocks
    int highestIndex = 0, lowestIndex = 0;
    for (i = 1; i < 5; i++) {
        if (currPrice[i] > currPrice[highestIndex]) {
            highestIndex = i;
        }
        if (currPrice[i] < currPrice[lowestIndex]) {
            lowestIndex = i;
        }
    }

    printf("Highest priced stock: Stock %d with price %0.2f\n", highestIndex+1, currPrice[highestIndex]);
    printf("Lowest priced stock: Stock %d with price %0.2f\n", lowestIndex+1, currPrice[lowestIndex]);

    return 0;
}