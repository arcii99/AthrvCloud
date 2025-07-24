//FormAI DATASET v1.0 Category: Temperature Converter ; Style: complete
#include <stdio.h>

int main() {
    float tempC, tempF;

    printf("Enter temperature in Celsius: ");
    scanf("%f", &tempC);

    tempF = (tempC * 9 / 5) + 32;

    printf("%.2f Celsius = %.2f Fahrenheit\n", tempC, tempF);

    return 0;
}