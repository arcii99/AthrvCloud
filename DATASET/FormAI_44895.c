//FormAI DATASET v1.0 Category: Unit converter ; Style: rigorous
#include <stdio.h>

int main() {
    float value;
    char from[10], to[10];

    printf("Enter the value to convert: ");
    scanf("%f", &value);
    printf("Enter the unit to convert from (e.g., m, ft, kg, lb): ");
    scanf("%s", from);
    printf("Enter the unit to convert to (e.g., ft, m, lb, kg): ");
    scanf("%s", to);

    if (strcmp(from, "m") == 0 && strcmp(to, "ft") == 0) {
        float converted = value * 3.2808;
        printf("%.2f %s is equal to %.2f %s\n", value, from, converted, to);
    }
    else if (strcmp(from, "ft") == 0 && strcmp(to, "m") == 0) {
        float converted = value * 0.3048;
        printf("%.2f %s is equal to %.2f %s\n", value, from, converted, to);
    }
    else if (strcmp(from, "kg") == 0 && strcmp(to, "lb") == 0) {
        float converted = value * 2.2046;
        printf("%.2f %s is equal to %.2f %s\n", value, from, converted, to);
    }
    else if (strcmp(from, "lb") == 0 && strcmp(to, "kg") == 0) {
        float converted = value * 0.4536;
        printf("%.2f %s is equal to %.2f %s\n", value, from, converted, to);
    }
    else {
        printf("Invalid or unsupported unit conversion\n");
    }

    return 0;
}