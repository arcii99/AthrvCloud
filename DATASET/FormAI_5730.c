//FormAI DATASET v1.0 Category: Temperature Converter ; Style: invasive
#include <stdio.h>

int main() {
    char choice;
    float temp, convertedTemp;

    printf("Welcome to the temperature converter!\n");

    printf("Please enter C for converting Celsius to Fahrenheit, or F for converting Fahrenheit to Celsius: ");
    scanf("%c", &choice);

    if(choice == 'C' || choice == 'c'){
        printf("Please enter the temperature in Celsius: ");
        scanf("%f", &temp);
        convertedTemp = (temp * 9 / 5) + 32;
        printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", temp, convertedTemp);
    } else if(choice == 'F' || choice == 'f') {
        printf("Please enter the temperature in Fahrenheit: ");
        scanf("%f", &temp);
        convertedTemp = (temp - 32) * 5 / 9;
        printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", temp, convertedTemp);
    } else {
        printf("Invalid choice! Please choose C or F.\n");
    }

    printf("Thank you for using the temperature converter!\n");
    return 0;
}