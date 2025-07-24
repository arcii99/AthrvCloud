//FormAI DATASET v1.0 Category: Temperature monitor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DATA_SIZE 10 // Maximum number of temperature readings

int main() {
    float temperature[MAX_DATA_SIZE];
    int i, j;
    float sum_temp=0, avg_temp=0, min_temp=0, max_temp=0;
    
    // Generate random temperature data for demo purposes
    srand(time(NULL)); // Set the random seed
    for(i=0; i<MAX_DATA_SIZE; i++) {
        temperature[i] = (rand() % 100) / 2.0; // Random temperature between 0 and 50 with decimal value
    }
    
    // Calculate average temperature
    for(i=0; i<MAX_DATA_SIZE; i++) {
        sum_temp += temperature[i];
    }
    avg_temp = sum_temp / MAX_DATA_SIZE;
    
    // Find minimum and maximum temperature
    min_temp = temperature[0];
    max_temp = temperature[0];
    for(i=1; i<MAX_DATA_SIZE; i++) {
        if(temperature[i] < min_temp) {
            min_temp = temperature[i];
        }
        if(temperature[i] > max_temp) {
            max_temp = temperature[i];
        }
    }
    
    // Display temperature data and analyze the readings
    printf("Temperature readings:\n");
    for(i=0; i<MAX_DATA_SIZE; i++) {
        printf("%.1f ", temperature[i]);
    }
    printf("\n");
    printf("Average temperature: %.1f\n", avg_temp);
    printf("Minimum temperature: %.1f\n", min_temp);
    printf("Maximum temperature: %.1f\n", max_temp);
    if(avg_temp < 20) {
        printf("Temperature is too low!\n");
    } else if(avg_temp > 30) {
        printf("Temperature is too high!\n");
    } else {
        printf("Temperature is normal.\n");
    }
    printf("Last 5 temperatures:\n");
    for(j=MAX_DATA_SIZE-5; j<MAX_DATA_SIZE; j++) {
        printf("%.1f ", temperature[j]);
    }
    printf("\n");
    
    return 0;
}