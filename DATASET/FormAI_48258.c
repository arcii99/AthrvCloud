//FormAI DATASET v1.0 Category: Unit converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    float value_to_convert, converted_value;
    
    printf("Welcome to the futuristic unit converter!\n");
    printf("Please choose the type of conversion you want to perform:\n");
    printf("1. Length\n");
    printf("2. Temperature\n");
    printf("3. Weight\n");
    printf("4. Speed\n");
    printf("5. Area\n");
    printf("6. Volume\n");
    printf("7. Quit\n");
    printf("Enter your choice (1-7): ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            printf("Enter the length value to convert: ");
            scanf("%f", &value_to_convert);
            converted_value = value_to_convert * 0.3048; // convert feet to meters
            printf("%f feet is equal to %f meters\n", value_to_convert, converted_value);
            break;
        case 2:
            printf("Enter the temperature value to convert: ");
            scanf("%f", &value_to_convert);
            converted_value = ((value_to_convert - 32) * 5) / 9; // convert Fahrenheit to Celsius
            printf("%f Fahrenheit is equal to %f Celsius\n", value_to_convert, converted_value);
            break;
        case 3:
            printf("Enter the weight value to convert: ");
            scanf("%f", &value_to_convert);
            converted_value = value_to_convert * 0.453592; // convert pounds to kilograms
            printf("%f pounds is equal to %f kilograms\n", value_to_convert, converted_value);
            break;
        case 4:
            printf("Enter the speed value to convert: ");
            scanf("%f", &value_to_convert);
            converted_value = value_to_convert * 1.60934; // convert miles per hour to kilometers per hour
            printf("%f miles per hour is equal to %f kilometers per hour\n", value_to_convert, converted_value);
            break;
        case 5:
            printf("Enter the area value to convert: ");
            scanf("%f", &value_to_convert);
            converted_value = value_to_convert * 0.092903; // convert square feet to square meters
            printf("%f square feet is equal to %f square meters\n", value_to_convert, converted_value);
            break;
        case 6:
            printf("Enter the volume value to convert: ");
            scanf("%f", &value_to_convert);
            converted_value = value_to_convert * 0.0283168; // convert cubic feet to cubic meters
            printf("%f cubic feet is equal to %f cubic meters\n", value_to_convert, converted_value);
            break;
        case 7:
            printf("Quitting the program. Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please enter a number from 1-7.\n");
            break;
    }
    
    return 0;
}