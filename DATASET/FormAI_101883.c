//FormAI DATASET v1.0 Category: Temperature Converter ; Style: complete
#include <stdio.h>

int main() {
    char unit;
    float temperature, convertedTemp;
    
    printf("Enter the temperature: ");
    scanf("%f %c", &temperature, &unit);
    
    switch(unit) {
        case 'C':
        case 'c':
            convertedTemp = (temperature * 9/5) + 32;
            printf("Temperature in Fahrenheit: %.2f F\n", convertedTemp);
            break;
        case 'F':
        case 'f':
            convertedTemp = (temperature - 32) * 5/9;
            printf("Temperature in Celsius: %.2f C\n", convertedTemp);
            break;
        default:
            printf("Invalid unit. Please enter either C or F.\n");
            break;
    }
    
    return 0;
}