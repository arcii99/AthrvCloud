//FormAI DATASET v1.0 Category: Temperature Converter ; Style: decentralized
#include<stdio.h>

int main()
{
    float celcius, fahrenheit;
    int choice;

    printf("Temperature Conversion Menu:\n");
    printf("[1] Convert from Celsius to Fahrenheit\n");
    printf("[2] Convert from Fahrenheit to Celsius\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    if(choice == 1)
    {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &celcius);

        fahrenheit = (celcius * 9/5) + 32;

        printf("%.2f Celsius is equal to %.2f Fahrenheit", celcius, fahrenheit);
    }
    else if(choice == 2)
    {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &fahrenheit);

        celcius = (fahrenheit - 32) * 5/9;

        printf("%.2f Fahrenheit is equal to %.2f Celsius", fahrenheit, celcius);
    }
    else
    {
        printf("Invalid choice.");
    }

    return 0;
}