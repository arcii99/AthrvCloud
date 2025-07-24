//FormAI DATASET v1.0 Category: Temperature Converter ; Style: cheerful
//Woohoo! Let's convert Celsius to Fahrenheit in a jiffy!
#include <stdio.h>

// Function declarations
float celToFah(float celsius);

// Main Function
int main()
{
    float celsius, fahrenheit;

    // Input temperature in Celsius from user
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    // Convert the given temperature in Celsius to Fahrenheit
    fahrenheit = celToFah(celsius);

    // Display the conversion result
    printf("%.2f Celsius = %.2f Fahrenheit", celsius, fahrenheit);

    return 0;
}

// Function to convert Celsius to Fahrenheit
float celToFah(float celsius)
{
    float fahrenheit;
    fahrenheit = (celsius * 9 / 5) + 32;
    return fahrenheit;
}