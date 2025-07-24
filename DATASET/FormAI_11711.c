//FormAI DATASET v1.0 Category: Temperature Converter ; Style: relaxed
#include <stdio.h>

int main() {
    float celsius, fahrenheit;

    printf("Enter the temperature in Celsius: ");
    scanf("%f", &celsius);

    // Convert Celsius to Fahrenheit.
    fahrenheit = (celsius * 9 / 5) + 32;

    printf("%.2fC equals to %.2fF\n", celsius, fahrenheit);

    return 0;
}