//FormAI DATASET v1.0 Category: Temperature Converter ; Style: satisfied
/* This is a program that converts the temperature from Celsius to Fahrenheit and vice versa. 
   The user will be prompted to select the conversion type and enter the temperature to be converted. 
   The program will display the converted temperature and prompt the user to convert another temperature.
   Enjoy using my program. */

#include <stdio.h>

int main() {
    int choice;
    float temperature, convertedTemperature;

    do { //Repeat until the user chooses to quit
        printf("\nTemperature Conversion Menu:\n");
        printf("1. Convert Celsius to Fahrenheit\n");
        printf("2. Convert Fahrenheit to Celsius\n");
        printf("3. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: //Convert Celsius to Fahrenheit
                printf("\nEnter temperature in Celsius: ");
                scanf("%f", &temperature);
                convertedTemperature = (9/5.0) * temperature + 32; //Formula to convert Celsius to Fahrenheit
                printf("%.2f degrees Celsius = %.2f degrees Fahrenheit\n", temperature, convertedTemperature);
                break;
            case 2: //Convert Fahrenheit to Celsius
                printf("\nEnter temperature in Fahrenheit: ");
                scanf("%f", &temperature);
                convertedTemperature = (5/9.0) * (temperature - 32); //Formula to convert Fahrenheit to Celsius
                printf("%.2f degrees Fahrenheit = %.2f degrees Celsius\n", temperature, convertedTemperature);
                break;
            case 3: //Quit program
                printf("\nThank you for using my program!\n");
                break;
            default: //Invalid choice
                printf("\nInvalid choice, please enter a number from 1-3\n");
        }
    } while(choice != 3);

    return 0;
}