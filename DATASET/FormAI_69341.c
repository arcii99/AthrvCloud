//FormAI DATASET v1.0 Category: Temperature monitor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10 // number of readings
#define THRESHOLD 25 // threshold temperature

int main() {
    int i, temp[N];
    float sum = 0, mean, std_deviation = 0;

    printf("Enter Temperature Readings:\n");
    for(i=0; i<N; i++) {
        scanf("%d", &temp[i]);
        sum += temp[i];
    }

    mean = sum/N;

    for(i=0; i<N; i++) {
        std_deviation += pow(temp[i] - mean, 2);
    }

    std_deviation = sqrt(std_deviation/N);

    printf("Mean Temperature = %.2f\n", mean);
    printf("Standard Deviation = %.2f\n", std_deviation);

    if(mean > THRESHOLD) {
        printf("Temperature is above threshold!\n");
    }
    else {
        printf("Temperature is below threshold.\n");
    }

    return 0;
}