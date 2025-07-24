//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    double stock = 1000.00;
    int days = 30;
    double volatility = 0.1;

    srand(time(NULL));

    printf("Day\tStock Price\n");

    for (int i = 1; i <= days; i++) {
        double factor = 1 + ((double) rand() / RAND_MAX - 0.5) * 2 * volatility;
        stock *= factor;

        printf("%d\t%.2f\n", i, stock);
    }

    return 0;
}