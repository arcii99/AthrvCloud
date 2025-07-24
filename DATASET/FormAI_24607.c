//FormAI DATASET v1.0 Category: Temperature Converter ; Style: medieval
#include <stdio.h>
int main()
{
    float celsius, fahrenheit;
    printf("Greetings, my lord! I have been commanded to convert temperatures for you.\nPlease enter a temperature in Celsius: ");
    scanf("%f", &celsius);
    fahrenheit = (celsius * 9 / 5) + 32;
    printf("%f degrees Celsius is equal to %f degrees Fahrenheit.\nThy request has been fulfilled, my lord.", celsius, fahrenheit);
    return 0;
}