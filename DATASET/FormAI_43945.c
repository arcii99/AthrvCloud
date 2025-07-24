//FormAI DATASET v1.0 Category: Unit converter ; Style: minimalist
#include <stdio.h>

int main() {
    float input;
    char from_unit[3], to_unit[3];

    printf("Enter the value to be converted: ");
    scanf("%f", &input);
    printf("Enter the unit to convert from: ");
    scanf("%s", from_unit);
    printf("Enter the unit to convert to: ");
    scanf("%s", to_unit);

    // Temperature Conversion
    if (from_unit[0] == 'C' && to_unit[0] == 'F') {
        printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", input, (input * (9/5.0) + 32));
    }
    else if (from_unit[0] == 'F' && to_unit[0] == 'C') {
        printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", input, ((input - 32) * 5/9.0));
    }
    // Distance Conversion
    else if (from_unit[0] == 'M' && from_unit[1] == 'I' && to_unit[0] == 'K' && to_unit[1] == 'M') {
        printf("%.2f miles is equal to %.2f kilometers.\n", input, (input * 1.60934));
    }
    else if (from_unit[0] == 'K' && from_unit[1] == 'M' && to_unit[0] == 'M' && to_unit[1] == 'I') {
        printf("%.2f kilometers is equal to %.2f miles.\n", input, (input * 0.621371));
    }
    // Weight Conversion
    else if (from_unit[0] == 'L' && from_unit[1] == 'B' && to_unit[0] == 'K' && to_unit[1] == 'G') {
        printf("%.2f pounds is equal to %.2f kilograms.\n", input, (input * 0.453592));
    }
    else if (from_unit[0] == 'K' && from_unit[1] == 'G' && to_unit[0] == 'L' && to_unit[1] == 'B') {
        printf("%.2f kilograms is equal to %.2f pounds.\n", input, (input * 2.20462));
    }
    else {
        printf("Invalid conversion. Please try again with valid units.\n");
    }

    return 0;
}