//FormAI DATASET v1.0 Category: Scientific ; Style: creative
#include <stdio.h>

int main() {

    printf("Welcome to the Science Center!\n");
    printf("What experiment would you like to perform today? (1 or 2)\n");
    printf("1: Test the boiling point of water\n");
    printf("2: Test the density of different materials\n");

    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        // Testing boiling point of water

        float temperature = 0;

        printf("Please input the temperature in Celsius: ");
        scanf("%f", &temperature);

        if (temperature < 100) {
            printf("The water is not boiling yet!\n");
        } else if (temperature == 100) {
            printf("The water is boiling at exactly 100 degrees Celsius!\n");
        } else {
            printf("The water is boiling above 100 degrees Celsius!\n");
        }

    } else if (choice == 2) {
        // Testing density of different materials

        float mass, volume, density;

        printf("Please input mass in grams: ");
        scanf("%f", &mass);

        printf("Please input volume in cubic centimeters: ");
        scanf("%f", &volume);

        density = mass / volume;

        printf("The Density is %f g/cm^3\n", density);

    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}