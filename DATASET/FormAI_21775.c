//FormAI DATASET v1.0 Category: Temperature monitor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float temp_c;       // Variable to store temperature in Celsius

    printf("Please enter the current temperature in Celsius: ");
    scanf("%f", &temp_c);   // User input for temperature

    printf("\n\n");

    if(temp_c < 0)      // If temperature is below freezing point of water
        printf("The temperature is sub-zero, please be careful.\n\n");

    if(temp_c >= 0 && temp_c < 10)     // If temperature is between 0 and 10 degrees Celsius
        printf("It's quite chilly, make sure to wrap up warm!\n\n");

    if(temp_c >= 10 && temp_c < 20)    // If temperature is between 10 and 20 degrees Celsius
        printf("It's a bit cold, but not too bad. Bring a light jacket with you.\n\n");

    if(temp_c >= 20 && temp_c < 30)    // If temperature is between 20 and 30 degrees Celsius
        printf("It's getting warmer, remember to drink plenty of water.\n\n");

    if(temp_c >= 30 && temp_c < 40)    // If temperature is between 30 and 40 degrees Celsius
        printf("It's very hot, stay hydrated and try to stay in the shade.\n\n");

    if(temp_c >= 40)        // If temperature is above 40 degrees Celsius
        printf("It's dangerously hot, avoid being outside if possible.\n\n");

    return 0;
}