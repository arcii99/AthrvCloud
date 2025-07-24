//FormAI DATASET v1.0 Category: Temperature monitor ; Style: innovative
#include <stdio.h>

int main() {
    float temperature;
    printf("Enter the current temperature in Celsius: ");
    scanf("%f", &temperature);
    if (temperature < -273.15) {
        printf("This temperature cannot exist!\n");
        return 1;
    }
    printf("The current temperature is %.2f Celsius.\n", temperature);
    float fahrenheit = temperature * 1.8 + 32;
    float kelvin = temperature + 273.15;
    printf("In Fahrenheit, the temperature is %.2f degrees.\n", fahrenheit);
    printf("In Kelvin, the temperature is %.2f degrees.\n", kelvin);
    if (temperature > 37) {
        printf("You have a fever.\n");
    } else if (temperature < 36) {
        printf("You may have hypothermia.\n");
    } else {
        printf("You have a normal body temperature.\n");
    }
    return 0;
}