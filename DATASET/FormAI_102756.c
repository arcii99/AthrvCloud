//FormAI DATASET v1.0 Category: Stock market tracker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomize_fluctuations(float *arr, int len) {
    srand(time(NULL));
    float max_fluctuation = 0.05;

    for(int i=0; i<len; i++) {
        float fluctuation = (rand()/(float)RAND_MAX)*2*max_fluctuation - max_fluctuation;
        arr[i] += arr[i]*fluctuation;
    }
}

int main() {
    int num_of_stocks = 5;
    char* stocks[] = {"AAPL", "GOOGL", "TSLA", "MSFT", "AMZN"};
    float stock_values[] = {156.23, 850.5, 334.71, 109.32, 1840.73};

    printf("Stock Market Tracker\n");

    for(int day=1; day<=7; day++) {
        printf("\nDay %d:\n", day);
        randomize_fluctuations(stock_values, num_of_stocks);

        for(int i=0; i<num_of_stocks; i++) {
            printf("%s: %.2f\t", stocks[i], stock_values[i]);
            for(int j=1; j<=(int)stock_values[i]%10; j++) {
                printf("*");
            }
            printf("\n");
        }

        printf("------------------------------------------------------------\n");
    }

    return 0;
}