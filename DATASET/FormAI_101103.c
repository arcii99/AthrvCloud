//FormAI DATASET v1.0 Category: Unit converter ; Style: Claude Shannon
#include <stdio.h>

float convertUnit(char fromUnit[], char toUnit[], float value);

int main() {
    float value;
    
    printf("Enter a value: ");
    scanf("%f", &value);
    
    char fromUnit[15];
    char toUnit[15];
    
    printf("Enter the unit you wish to convert from: ");
    scanf("%s", &fromUnit);
    
    printf("Enter the unit you wish to convert to: ");
    scanf("%s", &toUnit);
    
    float result = convertUnit(fromUnit, toUnit, value);
    
    printf("%f %s = %f %s\n", value, fromUnit, result, toUnit);
    
    return 0;
}

float convertUnit(char fromUnit[], char toUnit[], float value) {
    if (strcmp(fromUnit, "cm") == 0 && strcmp(toUnit, "m") == 0) {
        return value / 100;
    } else if (strcmp(fromUnit, "m") == 0 && strcmp(toUnit, "cm") == 0) {
        return value * 100;
    } else if (strcmp(fromUnit, "in") == 0 && strcmp(toUnit, "cm") == 0) {
        return value * 2.54;
    } else if (strcmp(fromUnit, "cm") == 0 && strcmp(toUnit, "in") == 0) {
        return value / 2.54;
    } else if (strcmp(fromUnit, "ft") == 0 && strcmp(toUnit, "m") == 0) {
        return value * 0.3048;
    } else if (strcmp(fromUnit, "m") == 0 && strcmp(toUnit, "ft") == 0) {
        return value / 0.3048;
    } else {
        printf("Invalid conversion\n");
        return 0;
    }
}