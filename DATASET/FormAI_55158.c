//FormAI DATASET v1.0 Category: Temperature Converter ; Style: automated
#include <stdio.h>

int main() {
    float celsius, farenheit;

    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    // conversion formula
    farenheit = (celsius * 9 / 5) + 32;

    printf("%.2f Celsius is equal to %.2f Farenheit\n", celsius, farenheit);

    return 0;
}