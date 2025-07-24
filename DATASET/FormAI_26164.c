//FormAI DATASET v1.0 Category: Stock market tracker ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 50 //maximum number of stock values to be tracked
#define RANGE_MIN 10 //minimum value for stock range
#define RANGE_MAX 100 //maximum value for stock range
#define MEAN 50 //mean value for stock range

int main(){
    srand(time(NULL)); //setting seed for random number generation

    int stock_prices[MAX]; //array to store stock prices

    /* generating stock values */
    printf("Generating stock values...\n");
    for(int i=0; i<MAX; i++){
        int random_val = (rand() % (RANGE_MAX - RANGE_MIN + 1)) + RANGE_MIN;
        if(random_val < MEAN){
            random_val -= (rand() % (MEAN - random_val + 1));
        }
        stock_prices[i] = random_val;
    }

    /* calculating statistical values */
    int sum = 0;
    float mean, variance, deviation;
    printf("\nCalculating statistical values...\n\n");
    printf("Stock values: ");
    for(int i=0; i<MAX; i++){
        printf("%d ", stock_prices[i]);
        sum += stock_prices[i];
    }
    mean = (float) sum / MAX;
    printf("\n\nMean value: %.2f\n", mean);

    sum = 0;
    for(int i=0; i<MAX; i++){
        sum += ((stock_prices[i]-mean) * (stock_prices[i]-mean));
    }
    variance = (float) sum / MAX;
    printf("Variance: %.2f\n", variance);

    deviation = sqrt(variance);
    printf("Standard deviation: %.2f\n\n", deviation);

    /* finding out maximum and minimum values */
    int max_val = stock_prices[0], max_index = 0;
    int min_val = stock_prices[0], min_index = 0;
    for(int i=1; i<MAX; i++){
        if(stock_prices[i] > max_val){
            max_val = stock_prices[i];
            max_index = i;
        }
        if(stock_prices[i] < min_val){
            min_val = stock_prices[i];
            min_index = i;
        }
    }
    printf("Maximum value: %d at index %d\n", max_val, max_index);
    printf("Minimum value: %d at index %d\n", min_val, min_index);

    return 0;
}