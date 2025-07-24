//FormAI DATASET v1.0 Category: Temperature Converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>

/*Below program will convert Celsius temperature input to Fahrenheit.*/

int main()
{
    float celsius, fahrenheit;
    printf("Hey there! Let's have some fun and convert Celsius to Fahrenheit!\nPlease enter the temperature in Celsius: ");
    scanf("%f", &celsius);
    printf("\nConverting Celsius to Fahrenheit...Please wait...\n");

    /* Hocus Pocus Temperature Conversion Formula!*/
    fahrenheit = (celsius * 9 / 5) + 32;
    
    printf("\nVoila! Here is your temperature in Fahrenheit: %.2f\n", fahrenheit);
    printf("\nWant to convert another temperature? Yes or No?\n");

    char repeat[10]; // This variable stores user's response i.e Yes or No
    scanf("%s", repeat);

    while (strcmp(repeat, "Yes") == 0 || strcmp(repeat, "yes") == 0) {
        printf("\nGreat! Please enter the temperature in Celsius: ");
        scanf("%f", &celsius);
        printf("\nConverting Celsius to Fahrenheit...Please wait...\n");

        /* More Hocus Pocus..Temperature Conversion Formula Again!!*/
        fahrenheit = (celsius * 9 / 5) + 32;

        printf("\nVoila! Here is your temperature in Fahrenheit: %.2f\n", fahrenheit);
        printf("\nWant to convert another temperature? Yes or No?\n");

        scanf("%s", repeat);
    }

    printf("\nAwww...Okay BYE BYE. Have a great day ahead! :)");

    return 0;
}