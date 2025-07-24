//FormAI DATASET v1.0 Category: Unit converter ; Style: systematic
#include <stdio.h>

int main() {
    float value;
    char from[20], to[20];
    printf("Welcome to the unit converter program!\n");
    printf("Enter the value to convert: ");
    scanf("%f", &value);
    printf("Enter the unit of measurement to convert from: ");
    scanf("%s", from);
    printf("Enter the unit of measurement to convert to: ");
    scanf("%s", to);

    if (strcmp(from, "km") == 0 && strcmp(to, "mi") == 0) {
        printf("%.2f km is equal to %.2f mi\n", value, value / 1.609);
    } else if (strcmp(from, "mi") == 0 && strcmp(to, "km") == 0) {
        printf("%.2f mi is equal to %.2f km\n", value, value * 1.609);
    } else if (strcmp(from, "kg") == 0 && strcmp(to, "lb") == 0) {
        printf("%.2f kg is equal to %.2f lb\n", value, value * 2.205);
    } else if (strcmp(from, "lb") == 0 && strcmp(to, "kg") == 0) {
        printf("%.2f lb is equal to %.2f kg\n", value, value / 2.205);
    } else if (strcmp(from, "m") == 0 && strcmp(to, "ft") == 0) {
        printf("%.2f m is equal to %.2f ft\n", value, value * 3.281);
    } else if (strcmp(from, "ft") == 0 && strcmp(to, "m") == 0) {
        printf("%.2f ft is equal to %.2f m\n", value, value / 3.281);
    } else {
        printf("Invalid units or conversion not implemented.\n");
    }

    return 0;
}