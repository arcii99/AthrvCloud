//FormAI DATASET v1.0 Category: Unit converter ; Style: creative
#include <stdio.h>

int main() {

    int option;
    float input, output;
    
    printf("\nWelcome to the Unit Converter!\n");
    printf("\nPlease select an option from the menu below:\n");
    printf("1. Convert Celsius to Fahrenheit\n2. Convert Fahrenheit to Celsius\n");
    printf("3. Convert Kilometers to Miles\n4. Convert Miles to Kilometers\n5. Exit the program\n");
    scanf("%d", &option);
    
    switch(option) {
        
        case 1:
            printf("\nEnter the temperature in Celsius: ");
            scanf("%f", &input);
            output = (input * 9 / 5) + 32;
            printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", input, output);
            break;
        
        case 2:
            printf("\nEnter the temperature in Fahrenheit: ");
            scanf("%f", &input);
            output = (input - 32) * 5 / 9;
            printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", input, output);
            break;
        
        case 3:
            printf("\nEnter the distance in Kilometers: ");
            scanf("%f", &input);
            output = input / 1.609;
            printf("%.2f Kilometers is equal to %.2f Miles.\n", input, output);
            break;
        
        case 4:
            printf("\nEnter the distance in Miles: ");
            scanf("%f", &input);
            output = input * 1.609;
            printf("%.2f Miles is equal to %.2f Kilometers.\n", input, output);
            break;
        
        case 5:
            printf("\nThank you for using the Unit Converter!\n");
            break;
            
        default:
            printf("\nInvalid input. Please try again.");
            break;
    }
    
    return 0;
}