//FormAI DATASET v1.0 Category: Unit converter ; Style: Cryptic
#include <stdio.h>

int main() {
    int cels;
    float far;

    printf("Enter the temperature in Celsius: ");
    scanf("%d", &cels);

    far = (cels * 9 / 5.0) + 32;

    printf("The temperature in Fahrenheit: %.2fF\n", far);

    return 0;
}