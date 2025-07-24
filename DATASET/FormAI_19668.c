//FormAI DATASET v1.0 Category: Unit converter ; Style: multiplayer
#include <stdio.h>

int main() {
    float input_unit, output_unit, unit_quantity;
    char input_type, output_type;
    printf("Enter unit quantity: ");
    scanf("%f", &unit_quantity);

    printf("Enter input unit type (k/m/cm): ");
    scanf(" %c", &input_type);

    printf("Enter output unit type (k/m/cm): ");
    scanf(" %c", &output_type);

    if(input_type == 'k' && output_type == 'm') {
        output_unit = unit_quantity * 1000;
    } else if (input_type == 'k' && output_type == 'cm') {
        output_unit = unit_quantity * 100000;
    } else if (input_type == 'm' && output_type == 'k') {
        output_unit = unit_quantity / 1000;
    } else if (input_type == 'm' && output_type == 'cm') {
        output_unit = unit_quantity * 100;
    } else if (input_type == 'cm' && output_type == 'k') {
        output_unit = unit_quantity / 100000;
    } else if (input_type == 'cm' && output_type == 'm') {
        output_unit = unit_quantity / 100;
    } else {
        printf("Invalid unit type!\n");
        return 0;
    }

    printf("%f %c converts to %f %c\n", unit_quantity, input_type, output_unit, output_type);
    return 0;
}