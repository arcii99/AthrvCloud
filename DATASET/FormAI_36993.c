//FormAI DATASET v1.0 Category: Unit converter ; Style: relaxed
#include <stdio.h>

int main() {
    float input_value; 
    char first_unit[10], second_unit[10];

    printf("Welcome to the Unit Converter Program!\n");
    printf("Please enter the value you would like to convert: ");
    scanf("%f", &input_value);

    printf("Great! Now enter the unit of the value you just entered: ");
    scanf("%s", first_unit);

    printf("Finally, please enter the unit you would like to convert to: ");
    scanf("%s", second_unit);

    printf("\n");

    // Temperature conversion
    if (strcmp(first_unit, "Fahrenheit") == 0 && strcmp(second_unit, "Celsius") == 0) {
        printf("%.2f Fahrenheit is equal to %.2f Celsius", input_value, (input_value - 32) * 5 / 9);
    } else if (strcmp(first_unit, "Celsius") == 0 && strcmp(second_unit, "Fahrenheit") == 0) {
        printf("%.2f Celsius is equal to %.2f Fahrenheit", input_value, (input_value * 9 / 5) + 32);
    }

    // Distance conversion
    if (strcmp(first_unit, "Miles") == 0 && strcmp(second_unit, "Kilometers") == 0) {
        printf("%.2f Miles is equal to %.2f Kilometers", input_value, input_value * 1.60934);
    } else if (strcmp(first_unit, "Kilometers") == 0 && strcmp(second_unit, "Miles") == 0) {
        printf("%.2f Kilometers is equal to %.2f Miles", input_value, input_value / 1.60934);
    }

    // Weight conversion
    if (strcmp(first_unit, "Pounds") == 0 && strcmp(second_unit, "Kilograms") == 0) {
        printf("%.2f Pounds is equal to %.2f Kilograms", input_value, input_value / 2.20462);
    } else if (strcmp(first_unit, "Kilograms") == 0 && strcmp(second_unit, "Pounds") == 0) {
        printf("%.2f Kilograms is equal to %.2f Pounds", input_value, input_value * 2.20462);
    }

    // Volume conversion
    if (strcmp(first_unit, "Gallons") == 0 && strcmp(second_unit, "Liters") == 0) {
        printf("%.2f Gallons is equal to %.2f Liters", input_value, input_value * 3.78541);
    } else if (strcmp(first_unit, "Liters") == 0 && strcmp(second_unit, "Gallons") == 0) {
        printf("%.2f Liters is equal to %.2f Gallons", input_value, input_value / 3.78541);
    }

    return 0;
}