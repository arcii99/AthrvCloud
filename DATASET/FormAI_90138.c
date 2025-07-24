//FormAI DATASET v1.0 Category: Unit converter ; Style: invasive
// Unique C Unit Converter Example Program

#include <stdio.h>

void main() {
    char choice;
    float value;

    printf("Choose an option:\n");
    printf("a. Convert Fahrenheit to Celsius\n");
    printf("b. Convert Miles to Kilometers\n");
    printf("c. Convert Pounds to Kilograms\n");
    printf("Enter option: ");
    scanf("%c", &choice);

    switch(choice) {
        case 'a':
            printf("Enter Fahrenheit value: ");
            scanf("%f", &value);
            float celsius = (value - 32) * 5 / 9;
            printf("%.2f Fahrenheit is %.2f Celsius", value, celsius);
            break;
        case 'b':
            printf("Enter Miles value: ");
            scanf("%f", &value);
            float kilometers = value * 1.60934;
            printf("%.2f Miles is %.2f Kilometers", value, kilometers);
            break;
        case 'c':
            printf("Enter Pounds value: ");
            scanf("%f", &value);
            float kilograms = value * 0.453592;
            printf("%.2f Pounds is %.2f Kilograms", value, kilograms);
            break;
        default:
            printf("Invalid choice!");
    }
}