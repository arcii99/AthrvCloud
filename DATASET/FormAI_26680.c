//FormAI DATASET v1.0 Category: Temperature Converter ; Style: ultraprecise
#include <stdio.h>

int main() {

    float celsius, fahrenheit;

    //prompting user to enter temperature in Celsius
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    //converting Celsius to Fahrenheit
    fahrenheit = (celsius * 9 / 5) + 32;

    //displaying the result
    printf("%.2f Celsius = %.2f Fahrenheit\n", celsius, fahrenheit);

    return 0;
}