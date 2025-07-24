//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Dennis Ritchie
/* This is a program that monitors temperature in Celsius. 
 * The program prompts the user to enter temperature in Celsius
 * and converts it to Fahrenheit. If the temperature exceeds the 
 * given limit, then an error is displayed. */

#include <stdio.h>

#define MAX_TEMP 100 // Maximum allowed temperature in Celsius

int main() {
    int celsius, fahrenheit;

    printf("Enter temperature in Celsius: ");
    scanf("%d", &celsius);

    fahrenheit = (celsius * 1.8) + 32; // Conversion formula

    if (celsius > MAX_TEMP) {
        printf("Error: Temperature exceeds the maximum limit of %d Celsius\n", MAX_TEMP);
    } else {
        printf("Temperature in Celsius: %d\n", celsius);
        printf("Temperature in Fahrenheit: %d\n", fahrenheit);
    }

    return 0;
}