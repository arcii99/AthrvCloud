//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Cryptic
#include<stdio.h>

int main(void) {
    printf("Please enter a temperature in Celsius: ");
    double celsius, fahrenheit;
    scanf("%lf", &celsius);
    printf("\nConverting temperature to Fahrenheit...\n");
    fahrenheit = (celsius * 9.0 / 5.0) + 32;
    printf("\nThe temperature in Fahrenheit is: %.2lf.\n", fahrenheit);
    return 0;
}