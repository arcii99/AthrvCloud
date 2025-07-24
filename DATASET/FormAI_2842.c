//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Romeo and Juliet
#include <stdio.h>

int main() {
    int choice;
    float temperature, convertedTemperature;

    printf("Oh, Romeo, what brings thee into this code?\n");
    printf("I seek to convert temperatures fair Juliet, wilt thou assist me?\n");
    
    printf("Press 1 to convert from Celsius to Fahrenheit\n");
    printf("Press 2 to convert from Fahrenheit to Celsius\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Ah, Celsius thou desire to convert to Fahrenheit? Mighty shall be thy desire\n");
        printf("Enter the Celsius temperature: ");
        scanf("%f", &temperature);

        convertedTemperature = (temperature * 9 / 5) + 32;
        printf("%.2f Celsius is equal to %.2f Fahrenheit", temperature, convertedTemperature);

    } else if (choice == 2) {
        printf("Thou must desire to convert from Fahrenheit to Celsius, correct?\n");
        printf("Enter the Fahrenheit temperature: ");
        scanf("%f", &temperature);

        convertedTemperature = (temperature - 32) * 5 / 9;
        printf("%.2f Fahrenheit is equal to %.2f Celsius", temperature, convertedTemperature);
    } else {
        printf("Confused, art thou? Choose 1 or 2 and try again, dear Romeo.");
    }

    return 0;
}