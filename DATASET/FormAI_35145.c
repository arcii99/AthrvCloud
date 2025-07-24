//FormAI DATASET v1.0 Category: Unit converter ; Style: complete
#include <stdio.h>
#include <stdlib.h>

int main() {
    int option; // variable to store user's choice of conversion type
    float input; // variable to store user's input value
    
    // display menu and ask for user's choice
    printf("Choose the conversion type:\n");
    printf("1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\n3. Miles to Kilometers\n4. Kilometers to Miles\n");
    scanf("%d", &option);
    
    // ask for user's input value
    printf("Enter the value to be converted: ");
    scanf("%f", &input);
    
    // perform the conversion based on user's choice
    switch(option) {
        case 1:
            printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.", input, (9.0/5.0)*input + 32);
            break;
        case 2:
            printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.", input, (5.0/9.0)*(input - 32));
            break;
        case 3:
            printf("%.2f miles is equal to %.2f kilometers.", input, input*1.609);
            break;
        case 4:
            printf("%.2f kilometers is equal to %.2f miles.", input, input/1.609);
            break;
        default:
            printf("Invalid choice. Please choose again.");
            break;
    }
    
    return 0;
}