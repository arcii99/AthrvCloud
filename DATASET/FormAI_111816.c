//FormAI DATASET v1.0 Category: Temperature Converter ; Style: medieval
#include <stdio.h>

int main() {

    int temperature;
    char choice;

    printf("Welcome to the Medieval Temperature Converter\n\n");

    do {
        printf("Please enter a temperature in Celsius: ");
        scanf("%d", &temperature);

        // Conversion formula
        int fahrenheit = (temperature * 9 / 5) + 32;

        printf("The temperature in Fahrenheit is %d\n\n", fahrenheit);

        printf("Would you like to convert another temperature? (Y/N)");
        scanf(" %c", &choice);

    } while (choice == 'Y' || choice == 'y');

    printf("Fare thee well!\n");

    return 0;
}