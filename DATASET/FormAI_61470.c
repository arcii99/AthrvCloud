//FormAI DATASET v1.0 Category: Stock market tracker ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Set initial stock prices for companies
    float Apple = 1504.13;
    float Google = 2300.17;
    float Microsoft = 3054.23;

    // Set time variables for simulated time
    time_t t;
    srand((unsigned) time(&t));
    int hour = 0;

    // Loop through 24 hours of simulated time
    for (int i = 0; i < 24; i++) {

        // Randomly adjust stock prices
        float AppleChange = (float)rand()/(float)(RAND_MAX/10) - 5;
        float GoogleChange = (float)rand()/(float)(RAND_MAX/10) - 5;
        float MicrosoftChange = (float)rand()/(float)(RAND_MAX/10) - 5;

        // Adjust stock prices and print out new prices
        Apple += AppleChange;
        Google += GoogleChange;
        Microsoft += MicrosoftChange;

        printf("Hour %d -- Apple: $%.2f / Google: $%.2f / Microsoft: $%.2f \n", hour, Apple, Google, Microsoft);
        hour++;
    }

    return 0;
}