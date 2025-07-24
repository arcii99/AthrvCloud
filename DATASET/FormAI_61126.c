//FormAI DATASET v1.0 Category: Temperature monitor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float celsius, fahrenheit;
    
    printf("Enter the temperature in Celsius: ");
    scanf("%f", &celsius);
    
    fahrenheit = (celsius * 9 / 5) + 32;
    
    printf("The temperature in Fahrenheit is: %.2f\n", fahrenheit);
    
    if (fahrenheit <= 32)
    {
        printf("It's freezing cold!\n");
    }
    else if (fahrenheit > 32 && fahrenheit <= 60)
    {
        printf("It's chilly!\n");
    }
    else if (fahrenheit > 60 && fahrenheit <= 80)
    {
        printf("It's nice and warm!\n");
    }
    else
    {
        printf("It's hot outside!\n");
    }
    
    return 0;
}