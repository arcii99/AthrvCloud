//FormAI DATASET v1.0 Category: Temperature monitor ; Style: excited
#include <stdio.h>

int main() {
    printf("Welcome to the C Temperature Monitor Program!\n");
    
    float currentTemperature = 0.0, minTemperature = 999.0, maxTemperature = -999.0, total = 0.0;
    int readings = 0; 
    
    while (1) {
        printf("Please enter current temperature (enter -999 to exit and display summary): ");
        scanf("%f", &currentTemperature);
        if (currentTemperature == -999) {
            printf("Exiting program\n");
            break;
        }
        if (currentTemperature < -273.15) {
            printf("Are you alive?? That is below absolute zero!\n");
            continue;
        }
        if (currentTemperature < minTemperature) {
            minTemperature = currentTemperature;
        }
        if (currentTemperature > maxTemperature) {
            maxTemperature = currentTemperature;
        }
        readings++;
        total += currentTemperature;
    }
    
    if (readings > 0) {
        float averageTemperature = total / readings;
        printf("\nTemperature Summary:\n");
        printf("Minimum temperature: %.2f\n", minTemperature);
        printf("Maximum temperature: %.2f\n", maxTemperature);
        printf("Average temperature: %.2f\n", averageTemperature);
        printf("Total number of readings: %d\n", readings);
        printf("Thank you for using the C Temperature Monitor Program!\n");
    } else {
        printf("No temperature readings provided, exiting program\n");
    }
    
    return 0;
}