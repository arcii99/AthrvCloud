//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    double Celsius, Fahrenheit;
    
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &Celsius);

    Fahrenheit = (Celsius * 9.0 / 5.0) + 32.0;

    printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit\n", Celsius, Fahrenheit);

    return 0;
}