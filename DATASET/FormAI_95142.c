//FormAI DATASET v1.0 Category: Unit converter ; Style: unmistakable
#include <stdio.h>

int main() {

    float value;
    char from[20], to[20];

    printf("\nEnter value: ");
    scanf("%f", &value);

    printf("Convert from (ex: mile): ");
    scanf("%s", from);

    printf("Convert to (ex: km): ");
    scanf("%s", to);

    if (strcmp(from, "mile") == 0 && strcmp(to, "km") == 0) {
        printf("\n%.2f miles = %.2f kilometers\n", value, value * 1.60934);
    } else if (strcmp(from, "km") == 0 && strcmp(to, "mile") == 0) {
        printf("\n%.2f kilometers = %.2f miles\n", value, value / 1.60934);
    } else if (strcmp(from, "gallon") == 0 && strcmp(to, "liter") == 0) {
        printf("\n%.2f gallons = %.2f liters\n", value, value * 3.78541);
    } else if (strcmp(from, "liter") == 0 && strcmp(to, "gallon") == 0) {
        printf("\n%.2f liters = %.2f gallons\n", value, value / 3.78541);
    } else if (strcmp(from, "ounce") == 0 && strcmp(to, "gram") == 0) {
        printf("\n%.2f ounces = %.2f grams\n", value, value * 28.3495);
    } else if (strcmp(from, "gram") == 0 && strcmp(to, "ounce") == 0) {
        printf("\n%.2f grams = %.2f ounces\n", value, value / 28.3495);
    } else {
        printf("\nConversion not supported, please try again.\n");
    }

    return 0;
}