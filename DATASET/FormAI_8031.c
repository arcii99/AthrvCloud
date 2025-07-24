//FormAI DATASET v1.0 Category: Temperature monitor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    float temperature[10];
    int i;

    for(i=0; i<10; i++){
        // generate random temperature between -10 to 40
        temperature[i] = ((float) rand() / RAND_MAX * 50) - 10;
    }

    printf("Temperature Monitor\n");
    printf("===================\n");

    for(i=0; i<10; i++){
        printf("Temperature %d: %.2f\n", i+1, temperature[i]);
    }

    // find average temperature
    float sum = 0, avg;
    for(i=0; i<10; i++){
        sum += temperature[i];
    }
    avg = sum / 10;

    printf("Average Temperature: %.2f\n", avg);

    // find highest and lowest temperature
    float highest = temperature[0], lowest = temperature[0];
    for(i=1; i<10; i++){
        if(temperature[i] > highest){
            highest = temperature[i];
        }
        if(temperature[i] < lowest){
            lowest = temperature[i];
        }
    }

    printf("Highest Temperature: %.2f\n", highest);
    printf("Lowest Temperature: %.2f\n", lowest);

    // determine if temperature is within normal range
    if(avg >= 10 && avg <= 30){
        printf("Temperature is within normal range\n");
    } else {
        printf("Temperature is abnormal\n");
    }

    return 0;
}