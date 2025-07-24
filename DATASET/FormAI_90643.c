//FormAI DATASET v1.0 Category: Temperature monitor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

int main() {
    float temperature;
    printf("Welcome to the Temperature Monitor!\n");

    while(1) {
        printf("Please enter a temperature in Celsius (-273.15 to 1000 degrees): ");
        scanf("%f", &temperature);

        if(temperature >= -273.15 && temperature <= 1000) {
            float fahrenheit = (temperature * 9/5) + 32;
            float kelvin = temperature + 273.15;
            
            printf("Temperature in Fahrenheit: %0.2f F\n", fahrenheit);
            printf("Temperature in Kelvin: %0.2f K\n", kelvin);
        } 
        else {
            printf("Invalid temperature entered. Please try again.\n");
        }

        printf("Would you like to enter another temperature? (y/n): ");
        char answer;
        scanf(" %c", &answer);

        if(answer == 'n') {
            break;
        }
    }
    printf("Thank you for using Temperature Monitor!\n");
    return 0;
}