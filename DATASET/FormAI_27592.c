//FormAI DATASET v1.0 Category: Temperature monitor ; Style: beginner-friendly
#include <stdio.h>

int main() {
    float temp;
    int option;

    do {
        printf("Enter the temperature in Celsius: ");
        scanf("%f", &temp);

        printf("Choose an option:\n1. Convert to Fahrenheit\n2. Convert to Kelvin\n3. Exit\n");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("%.2fC is %.2fF\n\n", temp, (temp * 9 / 5) + 32);
                break;

            case 2:
                printf("%.2fC is %.2fK\n\n", temp, temp + 273.15);
                break;

            case 3:
                printf("Program terminated.");
                return 0;

            default:
                printf("Invalid option selected. Please try again.\n\n");
        }

    } while(option != 3);

    return 0;
}