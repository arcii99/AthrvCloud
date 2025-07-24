//FormAI DATASET v1.0 Category: Unit converter ; Style: unmistakable
#include <stdio.h>

int main() {
    int choice;
    float unit;
    printf("Welcome to Unit Converter!\n\n");

    printf("Please select an option:\n");
    printf("1. Convert meters to feet\n");
    printf("2. Convert feet to meters\n");
    printf("3. Convert kilometers to miles\n");
    printf("4. Convert miles to kilometers\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter length in meters: ");
        scanf("%f", &unit);
        printf("%.2f meters = %.2f feet", unit, unit * 3.281);
    } else if (choice == 2) {
        printf("Enter length in feet: ");
        scanf("%f", &unit);
        printf("%.2f feet = %.2f meters", unit, unit / 3.281);
    } else if (choice == 3) {
        printf("Enter length in kilometers: ");
        scanf("%f", &unit);
        printf("%.2f kilometers = %.2f miles", unit, unit * 0.621);
    } else if (choice == 4) {
        printf("Enter length in miles: ");
        scanf("%f", &unit);
        printf("%.2f miles = %.2f kilometers", unit, unit / 0.621);
    } else {
        printf("Invalid option selected.");
    }

    return 0;
}