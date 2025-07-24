//FormAI DATASET v1.0 Category: Temperature Converter ; Style: statistical
#include <stdio.h>

int main() {
    float celsius, fahrenheit;
    printf("--------------------------\n");
    printf("Celsius to Fahrenheit Converter\n");
    printf("--------------------------\n");
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    //Convert Celsius to Fahrenheit
    fahrenheit = (celsius * 1.8) + 32;
    printf("%.2f Celsius = %.2f Fahrenheit\n", celsius, fahrenheit);
    return 0;
}