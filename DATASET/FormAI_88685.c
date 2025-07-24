//FormAI DATASET v1.0 Category: Weather simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL)); // seed random number generator
    
    int temperature[24]; // temperature array for 24 hours
    int i, j, max_temp, min_temp, temp_sum = 0;
    float avg_temp;
    
    printf("Welcome to Weather Simulation\n");
    
    // Generating random temperature values for 24 hours
    for (i = 0; i < 24; i++) {
        temperature[i] = rand() % 40; 
    }
    
    // Finding maximum, minimum and average temperature values
    max_temp = temperature[0];
    min_temp = temperature[0];
    for (i = 0; i < 24; i++) {
        if (temperature[i] > max_temp) {
            max_temp = temperature[i];
        }
        if (temperature[i] < min_temp) {
            min_temp = temperature[i];
        }
        temp_sum += temperature[i];
    }
    avg_temp = (float)temp_sum / 24;
    
    // Displaying temperature values for 24 hours
    printf("Hour   Temperature\n");
    for (i = 0; i < 24; i++) {
        printf("%02d:00   %02d°C\n", i, temperature[i]);
    }
    
    // Displaying maximum, minimum and average temperature values
    printf("\nMaximum temperature: %d°C\n", max_temp);
    printf("Minimum temperature: %d°C\n", min_temp);
    printf("Average temperature: %.2f°C\n", avg_temp);
    
    // Generating weather report
    printf("\nToday's Weather Report:\n");
    if (avg_temp <= 10) {
        printf("Cold weather.\n");
    } else if (avg_temp > 10 && avg_temp <=20) {
        printf("Mild weather.\n");
    } else if (avg_temp > 20 && avg_temp <= 30) {
        printf("Warm weather.\n");
    } else {
        printf("Hot weather.\n");
    }
    if (max_temp >= 35) {
        printf("Heat wave alert!\n");
    }
    if (min_temp <= 0) {
        printf("Frost alert!\n");
    }
    
    return 0; 
}