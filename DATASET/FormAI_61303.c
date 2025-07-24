//FormAI DATASET v1.0 Category: Unit converter ; Style: happy
#include <stdio.h>

int main() {
    printf("Welcome to the Unit Converter! Let's get started!\n");
    printf("What unit would you like to convert from?\n");
    printf("1. Feet to meters\n");
    printf("2. Pounds to kilograms\n");

    int choice;
    scanf("%d", &choice);

    if(choice == 1) {
        printf("Enter the value in feet:\n");
        float feet;
        scanf("%f", &feet);
        
        float meters = feet * 0.3048;
        printf("%.2f feet is equal to %.2f meters!\n", feet, meters);
    } 
    else if(choice == 2) {
        printf("Enter the value in pounds:\n");
        float pounds;
        scanf("%f", &pounds);

        float kilograms = pounds * 0.453592;
        printf("%.2f pounds is equal to %.2f kilograms!\n", pounds, kilograms);
    } 
    else {
        printf("Invalid choice. Please try again!\n");
    }

    printf("Thank you for using the Unit Converter. Have a happy day!\n");

    return 0;
}