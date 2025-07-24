//FormAI DATASET v1.0 Category: Temperature Converter ; Style: complete
#include <stdio.h>

int main() {
    float fahrenheit, celsius;

    printf("Enter the temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);

    // Conversion formula for Fahrenheit to Celsius
    celsius = (fahrenheit - 32) * 5 / 9;

    printf("%f °F is equal to %f °C\n", fahrenheit, celsius);

    return 0;
}

/* Sample Output:
Enter the temperature in Fahrenheit: 98.6
98.600000 °F is equal to 37.000000 °C
*/