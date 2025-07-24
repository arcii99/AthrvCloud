//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the Temperature Converter!\n");

    float fahr, celsius;

    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &fahr);

    celsius = (fahr - 32) * 5 / 9;

    printf("%.2f Fahrenheit is equal to %.2f Celsius\n", fahr, celsius);

    return 0;
}