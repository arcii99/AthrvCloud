//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Alan Touring
#include <stdio.h>

int main() {
    float celsius, fahrenheit;
    int select;

    printf("[1] Celsius to Fahrenheit\n");
    printf("[2] Fahrenheit to Celsius\n");
    printf("Please select an option: ");
    scanf("%d", &select);

    if (select == 1) {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &celsius);

        fahrenheit = (celsius * 9/5) + 32;

        printf("%.2f°C is equal to %.2f°F\n", celsius, fahrenheit);
    } else if (select == 2) {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &fahrenheit);

        celsius = (fahrenheit - 32) * 5/9;

        printf("%.2f°F is equal to %.2f°C\n", fahrenheit, celsius);
    } else {
        printf("Invalid option selected. Please select again.\n");
        main();
    }

    return 0;
}