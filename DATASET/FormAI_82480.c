//FormAI DATASET v1.0 Category: Unit converter ; Style: minimalist
#include <stdio.h>

void main() {
    float input, output;
    int choice;
    
    printf("Please enter the quantity: ");
    scanf("%f", &input);
    
    printf("Please select an option: \n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Convert Kilometers to Miles\n");
    printf("4. Convert Miles to Kilometers\n");
    printf("5. Convert Pounds to Kilograms\n");
    printf("6. Convert Kilograms to Pounds\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            output = (input * 1.8) + 32;
            printf("%.2f degrees Celsius is equivalent to %.2f degrees Fahrenheit", input, output);
            break;
        case 2:
            output = (input - 32) / 1.8;
            printf("%.2f degrees Fahrenheit is equivalent to %.2f degrees Celsius", input, output);
            break;
        case 3:
            output = input / 1.609;
            printf("%.2f kilometers is equivalent to %.2f miles", input, output);
            break;
        case 4:
            output = input * 1.609;
            printf("%.2f miles is equivalent to %.2f kilometers", input, output);
            break;
        case 5:
            output = input / 2.2046;
            printf("%.2f pounds is equivalent to %.2f kilograms", input, output);
            break;
        case 6:
            output = input * 2.2046;
            printf("%.2f kilograms is equivalent to %.2f pounds", input, output);
            break;
        default:
            printf("Invalid choice");
    }
}