//FormAI DATASET v1.0 Category: Temperature Converter ; Style: immersive
#include <stdio.h>

int main() {
    float celsius, fahrenheit;

    printf("Temperature Transformer - Celsius to Fahrenheit\n");
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    fahrenheit = ((celsius * 9) / 5) + 32;

    printf("%.2f degree Celsius is equal to %.2f degree Fahrenheit\n", celsius, fahrenheit);

    return 0;
}