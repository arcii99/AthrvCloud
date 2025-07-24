//FormAI DATASET v1.0 Category: Temperature Converter ; Style: portable
#include <stdio.h>

int main() {
    float fahrenheit, celsius;

    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);

    celsius = (fahrenheit - 32) * 5/9;

    printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius", fahrenheit, celsius);

    return 0;
}