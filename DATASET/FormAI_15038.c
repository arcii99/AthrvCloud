//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Dennis Ritchie
#include<stdio.h>

int main()
{
    float cel_temp, far_temp;
    int option;
    printf("Welcome to Temperature Converter, Please select an option:\n");
    printf("1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\n");
    scanf("%d", &option);
    
    switch(option)
    {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &cel_temp);
            far_temp = ((9.0/5.0) * cel_temp) + 32; //converting Celsius to Fahrenheit
            printf("Temperature in Fahrenheit: %.2f", far_temp);
            break;
        
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &far_temp);
            cel_temp = (5.0/9.0) * (far_temp - 32); //converting Fahrenheit to Celsius
            printf("Temperature in Celsius: %.2f", cel_temp);
            break;
            
        default:
            printf("Invalid option selected. Please choose a valid option.\n");
    }
    
    return 0;
}