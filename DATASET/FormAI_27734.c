//FormAI DATASET v1.0 Category: Temperature Converter ; Style: medieval
#include <stdio.h>

int main()
{
    float celsius, fahrenheit;
    int choice;

    printf("Greetings, traveler! I am the temperature converter wizard. I can convert temperatures from Celsius to Fahrenheit, or from Fahrenheit to Celsius. Choose 1 for Celsius to Fahrenheit, or 2 for Fahrenheit to Celsius:\n");

    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Ah, a Celsius to Fahrenheit conversion! Please enter the temperature in Celsius:\n");
            scanf("%f", &celsius);
            fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
            printf("Your temperature in Fahrenheit is %.2f degrees!\n", fahrenheit);
            break;
        case 2:
            printf("A Fahrenheit to Celsius conversion, you say? Very well. Please enter the temperature in Fahrenheit:\n");
            scanf("%f", &fahrenheit);
            celsius = (fahrenheit - 32.0) * 5.0 / 9.0;
            printf("Your temperature in Celsius is %.2f degrees!\n", celsius);
            break;
        default:
            printf("I'm sorry, I do not understand what you mean. Please try again later.\n");
    }

    printf("Fare thee well on thy travels!");

    return 0;
}