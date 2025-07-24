//FormAI DATASET v1.0 Category: Temperature Converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("******************\n");
    printf("***Temp Convert***\n");
    printf("******************\n\n");

    char choice;
    float f_temp, c_temp;

    printf("Which conversion do you want to perform?\n");
    printf("Fahrenheit to Celsius (Type f)\n");
    printf("Celsius to Fahrenheit (Type c)\n\n");
    printf("Your Choice: ");

    scanf("%c", &choice);

    if (choice == 'f' || choice == 'F')
    {
        printf("\nEnter the temperature in Fahrenheit: ");
        scanf("%f", &f_temp);

        c_temp = (f_temp - 32) * ((float)5/9);

        printf("\n%.2f Fahrenheit = %.2f Celsius\n", f_temp, c_temp);
    }
    else if (choice == 'c' || choice == 'C')
    {
        printf("Enter the temperature in Celsius: ");
        scanf("%f", &c_temp);

        f_temp = (c_temp * ((float)9/5)) + 32;

        printf("\n%.2f Celsius = %.2f Fahrenheit\n", c_temp, f_temp);
    }
    else
    {
        printf("\nInvalid choice. Please try again.\n\n");
        main();
    }

    return 0;
}