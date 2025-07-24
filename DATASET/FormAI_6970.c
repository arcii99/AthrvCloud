//FormAI DATASET v1.0 Category: Unit converter ; Style: minimalist
#include <stdio.h>

int main() {
    int choice;
    float value;

    printf("Choose an option:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    scanf("%d", &choice);

    printf("Enter a value: ");
    scanf("%f", &value);

    if (choice == 1) {
        float fah = (value * 1.8) + 32;
        printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", value, fah);
    } else if (choice == 2) {
        float cel = (value - 32) / 1.8;
        printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", value, cel);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}