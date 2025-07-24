//FormAI DATASET v1.0 Category: Temperature monitor ; Style: funny
#include <stdio.h>

int main() {

    printf("Welcome to the Temperature Monitor Program!\n\n");

    float tempReading;
    int numReadings = 0;
    float avgTemp = 0.0;

    printf("Please enter the temperature reading in Celsius (type '999' to exit):\n");

    while (tempReading != 999) {
        scanf("%f", &tempReading);
        
        if (tempReading == 999) {
            break;
        }

        numReadings++;
        avgTemp = ((avgTemp * (numReadings - 1)) + tempReading) / numReadings;
        printf("Temperature reading recorded: %.2fC\n", tempReading);
        printf("Current Average Temperature: %.2fC\n\n", avgTemp);
    }

    printf("Thank you for using the Temperature Monitor Program!\n");

    return 0;
}