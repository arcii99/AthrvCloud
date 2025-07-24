//FormAI DATASET v1.0 Category: Temperature Converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

int main() {
    char choice;
    float celsius, fahrenheit;

    do {
        printf("\nEnter temperature in Celsius: ");
        scanf("%f", &celsius);

        fahrenheit = (9 / 5.0) * celsius + 32;

        printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", celsius, fahrenheit);
        printf("\nDo another conversion? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y');

    printf("\nThank you for using the temperature converter!\n");

    return 0;
}