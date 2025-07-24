//FormAI DATASET v1.0 Category: Unit converter ; Style: rigorous
#include <stdio.h>

int main() {

    int choice, converted_value; 
    float input_value;

    printf("Welcome to the Unit Converter Program!\n");
    printf("Please select an option:\n");
    printf("1. Convert miles to kilometers\n");
    printf("2. Convert kilometers to miles\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter number of miles: ");
            scanf("%f", &input_value);
            converted_value = input_value * 1.60934;
            printf("%.2f miles is equal to %d kilometers.\n", input_value, converted_value);
            break;

        case 2:
            printf("Enter number of kilometers: ");
            scanf("%f", &input_value);
            converted_value = input_value * 0.621371;
            printf("%.2f kilometers is equal to %d miles.\n", input_value, converted_value);
            break;

        default:
            printf("Invalid choice! Please select option 1 or 2.\n");
            break;
    }

    return 0;
}