//FormAI DATASET v1.0 Category: Temperature Converter ; Style: visionary
#include <stdio.h>

int main() {
    float celsius, fahrenheit;

    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    // Convert celsius to fahrenheit
    fahrenheit = ((celsius * 9) / 5) + 32;

    printf("%.2f Celsius is equivalent to %.2f Fahrenheit.\n", celsius, fahrenheit);

    return 0;
}