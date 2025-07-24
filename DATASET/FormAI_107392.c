//FormAI DATASET v1.0 Category: Temperature Converter ; Style: minimalist
#include <stdio.h>

int main() {

    double celsius, fahrenheit;

    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);

    fahrenheit = (celsius * 9/5) + 32;

    printf("%.2lf Celsius is equal to %.2lf Fahrenheit", celsius, fahrenheit);

    return 0;
}