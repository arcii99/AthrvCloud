//FormAI DATASET v1.0 Category: Unit converter ; Style: configurable
#include <stdio.h>

double convert(double value, int from_unit, int to_unit);

int main() {
    double value;
    int from_unit, to_unit;

    // Prompt user for input
    printf("Enter the value to be converted: ");
    scanf("%lf", &value);

    printf("Enter the unit to convert from: \n");
    printf("1. Inches\n");
    printf("2. Feet\n");
    printf("3. Yards\n");
    printf("4. Miles\n");
    scanf("%d", &from_unit);

    printf("Enter the unit to convert to: \n");
    printf("1. Inches\n");
    printf("2. Feet\n");
    printf("3. Yards\n");
    printf("4. Miles\n");
    scanf("%d", &to_unit);

    // Call conversion function and display result
    double result = convert(value, from_unit, to_unit);
    printf("%lf unit %d = %lf unit %d\n", value, from_unit, result, to_unit);

    return 0;
}

double convert(double value, int from_unit, int to_unit) {
    const double ratios[4][4] = {{1.0, 0.0833333, 0.0277778, 1.57828e-5},
                                 {12.0, 1.0, 0.333333, 0.000189394},
                                 {36.0, 3.0, 1.0, 0.000568182},
                                 {63360.0, 5280.0, 1760.0, 1.0}};
    double ratio = ratios[from_unit-1][to_unit-1];
    return value * ratio;
}