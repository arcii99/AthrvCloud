//FormAI DATASET v1.0 Category: Unit converter ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>

int main()
{
    printf("O Romeo, Romeo! Wherefore art thou Romeo? \n");
    printf("I am here, my fair maiden. What can I do for thee?\n");
    printf("Oh Romeo, my heart longs for thee. Can you convert fahrenheit to celsius for me?\n");
    printf("Aye, fair Juliet. I can do that with ease. Let me show thee the way:\n\n");

    float fahrenheit, celsius;

    printf("Enter the temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);

    // Convert Fahrenheit to Celsius
    celsius = (fahrenheit - 32) * 5 / 9;

    printf("\nRomeo: My dearest Juliet, the temperature in Celsius is: %0.2f", celsius);

    printf("\n\nBut wait, my love. What if thou needs to convert Celsius to Kelvin?\n");
    printf("Romeo: Fear not, my Juliet. I shall show thee how to do it:\n");

    float celsius_in_kelvin;

    printf("Enter the temperature in Celsius: ");
    scanf("%f", &celsius);

    // Convert Celsius to Kelvin
    celsius_in_kelvin = celsius + 273.15;

    printf("\nRomeo: Sweet Juliet, behold! The temperature in Kelvin is: %0.2f", celsius_in_kelvin);
    printf("\n\nNow, my fair Juliet, I must take my leave. Farewell, until we meet again!\n");

    return 0;
}