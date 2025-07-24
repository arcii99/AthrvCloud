//FormAI DATASET v1.0 Category: Unit converter ; Style: systematic
#include <stdio.h>

int main() {
    float input_value;
    int input_unit, output_unit;

    printf("Enter the input value: ");
    scanf("%f", &input_value);

    printf("Enter the input unit (1: meter, 2: centimeter, 3: millimeter): ");
    scanf("%d", &input_unit);

    printf("Enter the output unit (1: meter, 2: centimeter, 3: millimeter): ");
    scanf("%d", &output_unit);

    float output_value;
    switch (input_unit) {
        case 1:
            // converting from meter
            switch (output_unit) {
                case 1:
                    output_value = input_value; // meter to meter
                    break;
                case 2:
                    output_value = input_value * 100; // meter to centimeter
                    break;
                case 3:
                    output_value = input_value * 1000; // meter to millimeter
                    break;
                default:
                    printf("Invalid output unit.\n");
                    return 1;
            }
            break;
        case 2:
            // converting from centimeter
            switch (output_unit) {
                case 1:
                    output_value = input_value / 100; // centimeter to meter
                    break;
                case 2:
                    output_value = input_value; // centimeter to centimeter
                    break;
                case 3:
                    output_value = input_value * 10; // centimeter to millimeter
                    break;
                default:
                    printf("Invalid output unit.\n");
                    return 1;
            }
            break;
        case 3:
            // converting from millimeter
            switch (output_unit) {
                case 1:
                    output_value = input_value / 1000; // millimeter to meter
                    break;
                case 2:
                    output_value = input_value / 10; // millimeter to centimeter
                    break;
                case 3:
                    output_value = input_value; // millimeter to millimeter
                    break;
                default:
                    printf("Invalid output unit.\n");
                    return 1;
            }
            break;
        default:
            printf("Invalid input unit.\n");
            return 1;
    }

    printf("%.2f converted from unit %d to unit %d is %.2f.\n", input_value, input_unit, output_unit, output_value);
    return 0;
}