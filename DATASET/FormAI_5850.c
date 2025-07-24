//FormAI DATASET v1.0 Category: Temperature monitor ; Style: high level of detail
#include <stdio.h>

int main() {
    // variable declaration
    float temperature;

    // asking user to input temperature
    printf("Enter the temperature in Celsius: ");
    scanf("%f", &temperature);

    // checking if the temperature is below freezing (0 degrees Celsius)
    if (temperature < 0) {
        printf("It's freezing!\n");
    }

    // checking if the temperature is within the comfortable range (20-25 degrees Celsius)
    else if (temperature >= 20 && temperature <= 25) {
        printf("It's a comfortable temperature.\n");
    }

    // if the temperature doesn't fall within the above conditions, display a general message
    else {
        printf("The temperature is currently %.2f degrees Celsius.\n", temperature);
    }

    return 0;
}