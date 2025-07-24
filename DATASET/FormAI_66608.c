//FormAI DATASET v1.0 Category: Temperature Converter ; Style: minimalist
#include <stdio.h>

int main() {
    float celsius, fahrenheit;
    printf("Enter the temperature in Celsius: ");
    scanf("%f", &celsius);
    fahrenheit = (celsius * 9/5) + 32; //formula for converting celsius to fahrenheit
    printf("%.2f Celsius is equivalent to %.2f Fahrenheit\n", celsius, fahrenheit);
    return 0;
}