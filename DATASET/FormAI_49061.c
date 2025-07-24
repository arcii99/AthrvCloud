//FormAI DATASET v1.0 Category: Stock market tracker ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int stocks[5] = {0};    // Initializing all stocks with zero
    srand(time(NULL));      // Setting seed for random number generation
    int i;

    // Stock market tracker
    printf("Welcome to stock market tracker!\n");
    printf("-----------------------------\n");

    // Simulation for 10 days
    for(i=0; i<10; i++) {
        printf("Day %d: \n", i+1);

        // Generating random values for each stock based on previous day's value
        stocks[0] = stocks[0] + rand()%101 - 50;      // Stock A
        stocks[1] = stocks[1] + rand()%101 - 50;      // Stock B
        stocks[2] = stocks[2] + rand()%101 - 50;      // Stock C
        stocks[3] = stocks[3] + rand()%101 - 50;      // Stock D
        stocks[4] = stocks[4] + rand()%101 - 50;      // Stock E

        printf("Stock A: %d \n", stocks[0]);
        printf("Stock B: %d \n", stocks[1]);
        printf("Stock C: %d \n", stocks[2]);
        printf("Stock D: %d \n", stocks[3]);
        printf("Stock E: %d \n", stocks[4]);

        // Checking for percentage change in each stock
        if(stocks[0] > 0) {
            printf("Stock A is up by %f%%\n", ((float)(stocks[0]-50)/50)*100);
        } else {
            printf("Stock A is down by %f%%\n", ((float)(50-stocks[0])/50)*100);
        }

        if(stocks[1] > 0) {
            printf("Stock B is up by %f%%\n", ((float)(stocks[1]-50)/50)*100);
        } else {
            printf("Stock B is down by %f%%\n", ((float)(50-stocks[1])/50)*100);
        }

        if(stocks[2] > 0) {
            printf("Stock C is up by %f%%\n", ((float)(stocks[2]-50)/50)*100);
        } else {
            printf("Stock C is down by %f%%\n", ((float)(50-stocks[2])/50)*100);
        }

        if(stocks[3] > 0) {
            printf("Stock D is up by %f%%\n", ((float)(stocks[3]-50)/50)*100);
        } else {
            printf("Stock D is down by %f%%\n", ((float)(50-stocks[3])/50)*100);
        }

        if(stocks[4] > 0) {
            printf("Stock E is up by %f%%\n", ((float)(stocks[4]-50)/50)*100);
        } else {
            printf("Stock E is down by %f%%\n", ((float)(50-stocks[4])/50)*100);
        }

        printf("-----------------------------\n");
    }

    return 0;
}