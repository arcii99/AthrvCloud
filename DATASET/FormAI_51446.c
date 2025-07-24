//FormAI DATASET v1.0 Category: Unit converter ; Style: mathematical
#include <stdio.h>

int main() {
    int option;
    float value;
    printf("Welcome to my unit converter program!\n");
    printf("Select an option:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Meter to Feet\n");
    printf("4. Feet to Meter\n");
    printf("5. Kilogram to Pound\n");
    printf("6. Pound to Kilogram\n");
    scanf("%d", &option);
    printf("Enter the value you want to convert:\n");
    scanf("%f", &value);
    switch(option) {
        case 1: //Celsius to Fahrenheit
            printf("%.2f Celsius is equivalent to %.2f Fahrenheit.\n", value, (value*9/5)+32);
            break;
        case 2: //Fahrenheit to Celsius
            printf("%.2f Fahrenheit is equivalent to %.2f Celsius.\n", value, (value-32)*5/9);
            break;
        case 3: //Meter to Feet
            printf("%.2f Meter is equivalent to %.2f Feet.\n", value, value*3.28084);
            break;
        case 4: //Feet to Meter
            printf("%.2f Feet is equivalent to %.2f Meter.\n", value, value/3.28084);
            break;
        case 5: //Kilogram to Pound
            printf("%.2f Kilogram is equivalent to %.2f Pound.\n", value, value*2.20462);
            break;
        case 6: //Pound to Kilogram
            printf("%.2f Pound is equivalent to %.2f Kilogram.\n", value, value/2.20462);
            break;
        default:
            printf("Invalid option. Please enter a valid option.\n");
    }
    return 0;
}