//FormAI DATASET v1.0 Category: Temperature Converter ; Style: futuristic
#include <stdio.h>

int main() {
    float celsius, fahrenheit;

    printf("\n--- Welcome to the Futuristic Temperature Converter ---\n");

    do {
        printf("\nEnter the temperature in Celsius (between -273.15°C and 10,000°C): ");
        scanf("%f", &celsius);

        if (celsius >= -273.15 && celsius <= 10000) {
            fahrenheit = (celsius * 1.8) + 32;
            printf("The temperature in Fahrenheit is %.2f°F\n", fahrenheit);
        } else {
            printf("\nInvalid input! Temperature should be between -273.15°C and 10,000°C.\n");
        }

        char response;
        printf("\nWould you like to convert another temperature? (Y/N) ");
        scanf(" %c", &response);

        if (response == 'N' || response == 'n') {
            break;
        }

    } while (1);

    printf("\nThank you for using the Futuristic Temperature Converter! Goodbye.\n");

    return 0;
}