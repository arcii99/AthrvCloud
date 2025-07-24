//FormAI DATASET v1.0 Category: Temperature monitor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to read the temperature */
float readTemperature() {
    /* Generate a random temperature between 0 to 100 */
    float temperature = (float)rand()/(float)RAND_MAX * 100;
    
    return temperature;
}

int main() {
    int count = 0;
    float temperature = 0.0, sum = 0.0, max_temp = 0.0, min_temp = 100.0;

    /* Seed the random number generator with current time */
    srand(time(NULL));

    /* Read the temperature 10 times */
    while(count < 10) {
        temperature = readTemperature();

        /* Print the temperature */
        printf("Temperature %d: %.2f\n", count+1, temperature);

        /* Add the temperature to sum */
        sum += temperature;

        /* Check for maximum temperature */
        if(temperature > max_temp) {
            max_temp = temperature;
        }

        /* Check for minimum temperature */
        if(temperature < min_temp) {
            min_temp = temperature;
        }

        /* Increment the count */
        count++;
    }

    /* Calculate the average temperature */
    float avg_temp = sum/count;

    /* Print the average, maximum and minimum temperature */
    printf("Average temperature: %.2f\n", avg_temp);
    printf("Maximum temperature: %.2f\n", max_temp);
    printf("Minimum temperature: %.2f\n", min_temp);

    return 0;
}