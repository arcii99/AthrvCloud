//FormAI DATASET v1.0 Category: Unit converter ; Style: happy
#include <stdio.h>

int main() {
    float temp_f, temp_c, temp_k;

    printf("Welcome to the Happy Temperature Converter!\n");
    printf("Enter a temperature in Fahrenheit: ");
    scanf("%f", &temp_f);

    temp_c = (temp_f - 32.0) * 5.0 / 9.0; // Convert Fahrenheit to Celsius
    temp_k = temp_c + 273.15; // Convert Celsius to Kelvin

    printf("Your temperature in Celsius is: %.2f\n", temp_c);
    printf("Your temperature in Kelvin is: %.2f\n", temp_k);
    printf("Happy converting! :)\n");

    return 0;
}