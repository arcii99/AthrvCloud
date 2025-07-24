//FormAI DATASET v1.0 Category: Temperature Converter ; Style: happy
#include <stdio.h>

int main() {
    printf("Hey there! Let's convert some temperatures shall we? \n");

    float fahrenheit, celsius;

    printf("Enter temperature in Celsius: \n");
    scanf("%f", &celsius);

    // Conversion formula: Fahrenheit = (9/5) * Celsius + 32
    fahrenheit = (9.0/5.0) * celsius + 32;

    printf("Temperature in Fahrenheit: %.2f F\n", fahrenheit);

    printf("Now let's convert a temperature in Fahrenheit to Celsius!\n");

    printf("Enter temperature in Fahrenheit: \n");
    scanf("%f", &fahrenheit);

    // Conversion formula: Celsius = (Fahrenheit - 32) * 5/9
    celsius = (fahrenheit - 32) * 5.0/9.0;

    printf("Temperature in Celsius : %.2f C\n", celsius);

    printf("Wow, isn't that cool? I love converting temperatures, it makes me so happy! :D\n");
    
    return 0;
}