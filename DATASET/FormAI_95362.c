//FormAI DATASET v1.0 Category: Temperature monitor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

    float celsius, minTemp, maxTemp, avgTemp, totalTemp = 0;
    int numReadings, i, j;

    srand(time(NULL)); // seed the random number generator
    
    printf("Welcome to the Temperature Monitor!\n\n");

    // Get the number of temperature readings
    printf("How many temperature readings would you like to take? ");
    scanf("%d", &numReadings);

    // Get the minimum and maximum temperature range for the readings
    printf("Enter the minimum temperature: ");
    scanf("%f", &minTemp);
    printf("Enter the maximum temperature: ");
    scanf("%f", &maxTemp);

    // Generate random temperature readings within the range
    float readings[numReadings];
    for (i = 0; i < numReadings; i++) {
        celsius = ((float)rand() / (float)RAND_MAX) * (maxTemp - minTemp) + minTemp;
        readings[i] = celsius;
        totalTemp += celsius; // track the total temperature for averaging later
    }

    // Display the temperature readings
    printf("\nTemperature Readings:\n");
    for (j = 0; j < numReadings; j++) {
        printf("%.2f C\n", readings[j]);
    }

    // Calculate and display the average temperature
    avgTemp = totalTemp / numReadings;
    printf("\nAverage temperature: %.2f C", avgTemp);

    return 0;
}