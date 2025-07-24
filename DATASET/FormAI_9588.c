//FormAI DATASET v1.0 Category: Unit converter ; Style: high level of detail
#include <stdio.h>

int main() {
    float miles, kilometer, pounds, kilograms;
    int choice;

    printf("Welcome to the Unit Converter!\n\n");

    while (1) {
        printf("What would you like to convert?\n");
        printf("1. Miles to Kilometer\n");
        printf("2. Kilograms to Pounds\n");
        printf("3. Quit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter Miles: ");
                scanf("%f", &miles);
                kilometer = miles * 1.60934;
                printf("%.2f Miles is equal to %.2f Kilometer.\n\n", miles, kilometer);
                break;

            case 2:
                printf("\nEnter Kilograms: ");
                scanf("%f", &kilograms);
                pounds = kilograms / 0.453592;
                printf("%.2f Kilograms is equal to %.2f Pounds.\n\n", kilograms, pounds);
                break;

            case 3:
                printf("Thanks for using our program. Goodbye!");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    }
    return 0;
}