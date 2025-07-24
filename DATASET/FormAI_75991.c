//FormAI DATASET v1.0 Category: Temperature Converter ; Style: peaceful
#include <stdio.h>

int main(void) {

    float celsius, fahrenheit;

    printf("---------------------------------\n");
    printf("| C to F Temperature Converter |\n");
    printf("---------------------------------\n");

    printf("Enter Temperature in Celsius: ");
    scanf("%f", &celsius);

    fahrenheit = (1.8 * celsius) + 32.0;

    printf("Temperature in Fahrenheit: %.2f\n", fahrenheit);

    return 0;
}