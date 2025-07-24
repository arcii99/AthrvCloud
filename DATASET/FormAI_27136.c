//FormAI DATASET v1.0 Category: Funny ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int trials = 1000;
    double mean = 0;
    double variance = 0;
    double sum = 0;
    double data[trials];

    srand(time(0)); // seed the random number generator

    printf("Rolling the dice %d times...\n", trials);

    // roll the dice, record the results, and calculate the mean
    for(int i = 0; i < trials; i++){
        int roll = rand() % 6 + 1; // random number between 1 and 6
        data[i] = roll;
        sum += roll;
    }

    mean = sum / trials;
    printf("Mean: %.2f\n", mean);

    // calculate the variance
    for(int i = 0; i < trials; i++){
        variance += pow(data[i] - mean, 2);
    }

    variance = variance / (trials - 1);
    printf("Variance: %.2f\n", variance);

    // hypothesis test: is the mean significantly different from 3.5?
    double t = (mean - 3.5) / sqrt(variance / trials);

    printf("t-score: %.2f\n", t);

    if(fabs(t) > 1.96){
        printf("Reject null hypothesis: mean is significantly different from 3.5\n");
    } else {
        printf("Accept null hypothesis: mean is not significantly different from 3.5\n");
    }

    return 0;
}