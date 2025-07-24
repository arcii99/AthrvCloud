//FormAI DATASET v1.0 Category: Temperature Converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char choice;
    float celsius, fahrenheit, kelvin;
    printf("<------------------------------------------>\n");
    printf("|        Welcome to the Retro Converter!   |\n");
    printf("<------------------------------------------>\n");
    do
    {
        printf("[1] Celsius to Fahrenheit\n");
        printf("[2] Celsius to Kelvin\n");
        printf("[3] Fahrenheit to Celsius\n");
        printf("[4] Fahrenheit to Kelvin\n");
        printf("[5] Kelvin to Celsius\n");
        printf("[6] Kelvin to Fahrenheit\n");
        printf("[7] Quit\n");

        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch(choice)
        {
            case '1':
                printf("\nEnter temperature in Celsius: ");
                scanf("%f", &celsius);
                fahrenheit = (celsius * 9 / 5) + 32;
                printf("%.2fC = %.2fF\n\n", celsius, fahrenheit);
                break;
            case '2':
                printf("\nEnter temperature in Celsius: ");
                scanf("%f", &celsius);
                kelvin = celsius + 273.15;
                printf("%.2fC = %.2fK\n\n", celsius, kelvin);
                break;
            case '3':
                printf("\nEnter temperature in Fahrenheit: ");
                scanf("%f", &fahrenheit);
                celsius = (fahrenheit - 32) * 5 / 9;
                printf("%.2fF = %.2fC\n\n", fahrenheit, celsius);
                break;
            case '4':
                printf("\nEnter temperature in Fahrenheit: ");
                scanf("%f", &fahrenheit);
                kelvin = (fahrenheit + 459.67) * 5 / 9;
                printf("%.2fF = %.2fK\n\n", fahrenheit, kelvin);
                break;
            case '5':
                printf("\nEnter temperature in Kelvin: ");
                scanf("%f", &kelvin);
                celsius = kelvin - 273.15;
                printf("%.2fK = %.2fC\n\n", kelvin, celsius);
                break;
            case '6':
                printf("\nEnter temperature in Kelvin: ");
                scanf("%f", &kelvin);
                fahrenheit = (kelvin * 9 / 5) - 459.67;
                printf("%.2fK = %.2fF\n\n", kelvin, fahrenheit);
                break;
            case '7':
                printf("\nThank you for using the Retro Converter!\n\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n\n");
                break;
        }
    }while(choice != '7');
    return 0;
}