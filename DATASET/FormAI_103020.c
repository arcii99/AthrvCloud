//FormAI DATASET v1.0 Category: Unit converter ; Style: Alan Touring
#include <stdio.h>

int main() {
    double length, converted_length;
    char from_unit[10], to_unit[10];
    
    printf("Welcome to the Unit Converter!\n");
    printf("Enter a length: ");
    scanf("%lf", &length);

    printf("Enter the unit of the length (in or cm): ");
    scanf("%s", from_unit);

    printf("Enter the unit to convert to (in or cm): ");
    scanf("%s", to_unit);
    
    if (strcmp(from_unit, "in") == 0 && strcmp(to_unit, "cm") == 0) {
        //convert inches to centimeters
        converted_length = length * 2.54;
        printf("%lf inches is equal to %lf centimeters.\n", length, converted_length);
    }
    else if (strcmp(from_unit, "cm") == 0 && strcmp(to_unit, "in") == 0) {
        //convert centimeters to inches
        converted_length = length / 2.54;
        printf("%lf centimeters is equal to %lf inches.\n", length, converted_length);
    }
    else {
        printf("Invalid units entered. Please enter either 'in' or 'cm'.\n");
    }
    
    return 0;
}