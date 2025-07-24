//FormAI DATASET v1.0 Category: Temperature monitor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMP 100
#define MIN_TEMP 0

int main()
{
    time_t t;
    srand((unsigned) time(&t));
    float currentTemp = (float)(rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP); // generate random initial temperature between MIN_TEMP and MAX_TEMP
    float targetTemp;
    char choice;

    printf("Current temperature: %.1f C\n", currentTemp);

    do {
        printf("Enter target temperature (in Celsius): ");
        scanf("%f", &targetTemp);

        // check if target temperature is within range
        if (targetTemp < MIN_TEMP || targetTemp > MAX_TEMP) {
            printf("Invalid input. Temperature must be between %.1f C and %.1f C\n", MIN_TEMP, MAX_TEMP);
        }
        else {
            // monitor temperature until it reaches target temperature
            while (currentTemp != targetTemp) {
                if (currentTemp > targetTemp) {
                    currentTemp -= 0.5;
                }
                else {
                    currentTemp += 0.5;
                }
                printf("Current temperature: %.1f C\n", currentTemp);
            }
            printf("Temperature has reached target value of %.1f C\n", targetTemp);
        }

        printf("Do you want to enter a new target temperature? (y/n): ");
        scanf(" %c", &choice);
    } while (choice != 'n');

    printf("Program terminated.\n");

    return 0;
}