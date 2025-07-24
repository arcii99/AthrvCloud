//FormAI DATASET v1.0 Category: Unit converter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

int main() {
    float input;
    int choice;

    printf("Welcome to the Unit Converter!\n");
    printf("Select the unit you would like to convert from: \n");
    printf("1. Feet to Meters\n");
    printf("2. Miles to Kilometers\n");

    // Take user's choice of conversion
    scanf("%d", &choice);
    while (choice != 1 && choice != 2) {
        printf("Please enter either 1 or 2: ");
        scanf("%d", &choice);
    }

    // Take user's input value to convert
    printf("Enter the value you would like to convert: ");
    scanf("%f", &input);

    // Perform the selected conversion and output converted result
    if (choice == 1) {
        float meters = input * 0.3048;
        printf("%.2f feet is equal to %.2f meters.\n", input, meters);
    } else {
        float kilometers = input * 1.6093;
        printf("%.2f miles is equal to %.2f kilometers.\n", input, kilometers);
    }

    return 0;
}