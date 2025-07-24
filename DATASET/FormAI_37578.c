//FormAI DATASET v1.0 Category: Temperature Converter ; Style: thoughtful
#include<stdio.h> 

int main() 
{ 
    int choice;
    float tempC, tempF, tempK;

    printf("Welcome to the Temperature Converter!\n\n");
    printf("Choose an option:\n");
    printf("1. Convert Celsius to Fahrenheit and Kelvin\n");
    printf("2. Convert Fahrenheit to Celsius and Kelvin\n");
    printf("3. Convert Kelvin to Celsius and Fahrenheit\n");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            printf("\nEnter temperature in Celsius: ");
            scanf("%f", &tempC);
            tempF = (tempC * 9/5) + 32;
            tempK = tempC + 273.15;
            printf("\n%.2f Celsius is equal to %.2f Fahrenheit and %.2f Kelvin\n", tempC, tempF, tempK);
            break;

        case 2:
            printf("\nEnter temperature in Fahrenheit: ");
            scanf("%f", &tempF);
            tempC = (tempF - 32) * 5/9;
            tempK = (tempF - 32) * 5/9 + 273.15;
            printf("\n%.2f Fahrenheit is equal to %.2f Celsius and %.2f Kelvin\n", tempF, tempC, tempK);
            break;

        case 3:
            printf("\nEnter temperature in Kelvin: ");
            scanf("%f", &tempK);
            tempC = tempK - 273.15;
            tempF = (tempK - 273.15) * 9/5 + 32;
            printf("\n%.2f Kelvin is equal to %.2f Celsius and %.2f Fahrenheit\n", tempK, tempC, tempF);
            break;

        default:
            printf("\nInvalid choice! Please choose an option from 1 to 3.\n");
            break;
    }

    return 0; 
}