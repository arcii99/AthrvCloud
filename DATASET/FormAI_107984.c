//FormAI DATASET v1.0 Category: Unit converter ; Style: sophisticated
#include <stdio.h>

int main() {
    int option;
    float value;

    // Display the list of conversion options
    printf("Enter the conversion option:\n");
    printf("1. Feet to Meters\n");
    printf("2. Celsius to Fahrenheit\n");
    printf("3. Kilograms to Pounds\n");

    // Take the user's option as input
    scanf("%d", &option);

    // Take the value to be converted as input
    printf("Enter the value to be converted:\n");
    scanf("%f", &value);

    // Perform the conversion based on the user's option
    if (option == 1) {
        float meters = value * 0.3048;
        printf("%.2f feet = %.2f meters\n", value, meters);
    } else if (option == 2) {
        float fahrenheit = (value * 9 / 5) + 32;
        printf("%.2f Celsius = %.2f Fahrenheit\n", value, fahrenheit);
    } else if (option == 3) {
        float pounds = value * 2.20462;
        printf("%.2f kilograms = %.2f pounds\n", value, pounds);
    } else {
        printf("Invalid option!");
    }

    return 0;
}