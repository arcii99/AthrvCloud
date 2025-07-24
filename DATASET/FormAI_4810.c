//FormAI DATASET v1.0 Category: Temperature Converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the Totally Accurate Temperature Converter!\n\n");

    printf("Please enter the temperature in Celsius (°C): ");
    float celsius;
    scanf("%f", &celsius);

    printf("Converting temperature...stand by...\n\n");

    printf("Hey, did you hear the one about Fahrenheit and Celsius?\n");
    printf("They were having a heated argument about who was hotter...\n\n");

    printf("Anyway, back to the task at hand...\n");

    float fahrenheit = (celsius * 9 / 5) + 32;
    printf("%.2f°C is equivalent to %.2f°F!\n\n", celsius, fahrenheit);

    printf("Now, let's convert that temperature to Kelvin!\n");
    printf("Hold on...let me check my notes...\n\n");

    float kelvin = celsius + 273.15;
    printf("%.2f°C is also equal to %.2fK!\n\n", celsius, kelvin);

    printf("Thanks for using the Totally Accurate Temperature Converter!\n");
    printf("If you need to convert temperatures again in the future, just remember the acronym...\n\n");

    printf("T\n");
    printf("A\n");
    printf("T\n");
    printf("C\n");

    return 0;
}