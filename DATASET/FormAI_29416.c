//FormAI DATASET v1.0 Category: Temperature monitor ; Style: inquisitive
#include <stdio.h>
#define TEMP_THRESHOLD 25 // adjust this value to set the temperature threshold

int main() {
    float temp_celsius; // temperature variable in Celsius

    // prompt user to input temperature in Celsius
    printf("Enter the temperature in Celsius: ");
    scanf("%f", &temp_celsius);

    // check if temperature exceeds the threshold and print corresponding message
    if (temp_celsius >= TEMP_THRESHOLD) {
        printf("Alert! Temperature exceeds the threshold of %d degrees Celsius.\n", TEMP_THRESHOLD);
    } else {
        printf("Temperature is within normal range.\n");
    }

    // ask user if they want to convert temperature to Fahrenheit
    printf("Do you want to convert the temperature to Fahrenheit? (y/n): ");
    char response;
    scanf("\n%c", &response);

    // if user wants to convert, print temperature in Fahrenheit
    if (response == 'y') {
        float temp_fahrenheit = (temp_celsius * 9 / 5) + 32; //convert to fahrenheit by formula
        printf("Temperature in Fahrenheit: %.2f\n", temp_fahrenheit);
    } else {
        printf("Okay, exiting program.\n");
    }

    return 0;
}