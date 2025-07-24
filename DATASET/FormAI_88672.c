//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Dennis Ritchie
/* Temperature Converter Program */
#include <stdio.h>

int main() {
    char tempUnit;
    float tempValue, convertedValue;
    
    printf("Welcome to the Temperature Converter Program.\n");
    printf("Please enter the temperature unit (C/F): ");
    scanf("%c", &tempUnit);
    printf("Please enter the temperature value: ");
    scanf("%f", &tempValue);
    
    if (tempUnit == 'C' || tempUnit == 'c') {
        convertedValue = (tempValue * 1.8) + 32;
        printf("%.2fC is %.2fF\n", tempValue, convertedValue);
    }
    else if (tempUnit == 'F' || tempUnit == 'f') {
        convertedValue = (tempValue - 32) / 1.8;
        printf("%.2fF is %.2fC\n", tempValue, convertedValue);
    }
    else {
        printf("Invalid temperature unit entered. Please enter either C or F.\n");
    }
    
    printf("Thank you for using the Temperature Converter Program.\n");
    return 0;
}