//FormAI DATASET v1.0 Category: Temperature monitor ; Style: minimalist
#include <stdio.h>

int main() {
    float temperature[7] = {25.5, 20.4, 31.2, 18.7, 23.1, 27.8, 19.9};
    float sum = 0, average;
    int i;

    printf("Temperature Monitor\n");
    printf("-------------------\n");

    for(i = 0; i < 7; i++) {
        sum += temperature[i];
    }

    average = sum / 7;

    printf("Average temperature: %.2f\n\n", average);

    for(i = 0; i < 7; i++) {
        if(temperature[i] > average) {
            printf("Temperature %d is %.2f above average\n", i, temperature[i] - average);
        } else if(temperature[i] < average) {
            printf("Temperature %d is %.2f below average\n", i, average - temperature[i]);
        } else {
            printf("Temperature %d is equal to the average\n", i);
        }
    }

    return 0;
}