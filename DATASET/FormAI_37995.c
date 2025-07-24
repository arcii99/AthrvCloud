//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Alan Touring
#include <stdio.h>

int main() {
    float celsius, fahrenheit;

    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    // Conversion formula
    fahrenheit = (celsius * 9 / 5) + 32;

    // Output
    printf("%.2f°C = %.2f°F\n", celsius, fahrenheit);

    return 0;
}