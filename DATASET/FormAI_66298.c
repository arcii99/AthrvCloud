//FormAI DATASET v1.0 Category: Unit converter ; Style: happy
#include <stdio.h>

int main() {
    int choice1, choice2;
    float value, result;

    printf("Welcome to Happy Unit Converter!\n\n");

    printf("Please choose the input unit:\n");
    printf("1. Meter\n2. Kilometer\n3. Centimeter\n4. Millimeter\n5. Foot\n6. Inch\n7. Yard\n8. Mile\n");
    scanf("%d", &choice1);

    printf("\nPlease choose the output unit:\n");
    printf("1. Meter\n2. Kilometer\n3. Centimeter\n4. Millimeter\n5. Foot\n6. Inch\n7. Yard\n8. Mile\n");
    scanf("%d", &choice2);

    printf("\nEnter the value to be converted: ");
    scanf("%f", &value);

    switch(choice1) {
        case 1: // Meter
            switch(choice2) {
                case 1: // Meter
                    result = value;
                    break;
                case 2: // Kilometer
                    result = value * 0.001;
                    break;
                case 3: // Centimeter
                    result = value * 100;
                    break;
                case 4: // Millimeter
                    result = value * 1000;
                    break;
                case 5: // Foot
                    result = value * 3.28084;
                    break;
                case 6: // Inch
                    result = value * 39.3701;
                    break;
                case 7: // Yard
                    result = value * 1.09361;
                    break;
                case 8: // Mile
                    result = value * 0.000621371;
                    break;
                default:
                    printf("\nInvalid output unit selection. Please try again.\n");
                    return 0;
            }
            break;
        case 2: // Kilometer
            switch(choice2) {
                case 1: // Meter
                    result = value * 1000;
                    break;
                case 2: // Kilometer
                    result = value;
                    break;
                case 3: // Centimeter
                    result = value * 100000;
                    break;
                case 4: // Millimeter
                    result = value * 1000000;
                    break;
                case 5: // Foot
                    result = value * 3280.84;
                    break;
                case 6: // Inch
                    result = value * 39370.1;
                    break;
                case 7: // Yard
                    result = value * 1093.61;
                    break;
                case 8: // Mile
                    result = value * 0.621371;
                    break;
                default:
                    printf("\nInvalid output unit selection. Please try again.\n");
                    return 0;
            }
            break;
        case 3: // Centimeter
            switch(choice2) {
                case 1: // Meter
                    result = value * 0.01;
                    break;
                case 2: // Kilometer
                    result = value * 0.00001;
                    break;
                case 3: // Centimeter
                    result = value;
                    break;
                case 4: // Millimeter
                    result = value * 10;
                    break;
                case 5: // Foot
                    result = value * 0.0328084;
                    break;
                case 6: // Inch
                    result = value * 0.393701;
                    break;
                case 7: // Yard
                    result = value * 0.0109361;
                    break;
                case 8: // Mile
                    result = value * 0.00000621371;
                    break;
                default:
                    printf("\nInvalid output unit selection. Please try again.\n");
                    return 0;
            }
            break;
        case 4: // Millimeter
            switch(choice2) {
                case 1: // Meter
                    result = value * 0.001;
                    break;
                case 2: // Kilometer
                    result = value * 0.000001;
                    break;
                case 3: // Centimeter
                    result = value * 0.1;
                    break;
                case 4: // Millimeter
                    result = value;
                    break;
                case 5: // Foot
                    result = value * 0.00328084;
                    break;
                case 6: // Inch
                    result = value * 0.0393701;
                    break;
                case 7: // Yard
                    result = value * 0.00109361;
                    break;
                case 8: // Mile
                    result = value * 0.000000621371;
                    break;
                default:
                    printf("\nInvalid output unit selection. Please try again.\n");
                    return 0;
            }
            break;
        case 5: // Foot
            switch(choice2) {
                case 1: // Meter
                    result = value * 0.3048;
                    break;
                case 2: // Kilometer
                    result = value * 0.0003048;
                    break;
                case 3: // Centimeter
                    result = value * 30.48;
                    break;
                case 4: // Millimeter
                    result = value * 304.8;
                    break;
                case 5: // Foot
                    result = value;
                    break;
                case 6: // Inch
                    result = value * 12;
                    break;
                case 7: // Yard
                    result = value * 0.333333;
                    break;
                case 8: // Mile
                    result = value * 0.000189394;
                    break;
                default:
                    printf("\nInvalid output unit selection. Please try again.\n");
                    return 0;
            }
            break;
        case 6: // Inch
            switch(choice2) {
                case 1: // Meter
                    result = value * 0.0254;
                    break;
                case 2: // Kilometer
                    result = value * 0.0000254;
                    break;
                case 3: // Centimeter
                    result = value * 2.54;
                    break;
                case 4: // Millimeter
                    result = value * 25.4;
                    break;
                case 5: // Foot
                    result = value * 0.0833333;
                    break;
                case 6: // Inch
                    result = value;
                    break;
                case 7: // Yard
                    result = value * 0.0277778;
                    break;
                case 8: // Mile
                    result = value * 0.0000157828;
                    break;
                default:
                    printf("\nInvalid output unit selection. Please try again.\n");
                    return 0;
            }
            break;
        case 7: // Yard
            switch(choice2) {
                case 1: // Meter
                    result = value * 0.9144;
                    break;
                case 2: // Kilometer
                    result = value * 0.0009144;
                    break;
                case 3: // Centimeter
                    result = value * 91.44;
                    break;
                case 4: // Millimeter
                    result = value * 914.4;
                    break;
                case 5: // Foot
                    result = value * 3;
                    break;
                case 6: // Inch
                    result = value * 36;
                    break;
                case 7: // Yard
                    result = value;
                    break;
                case 8: // Mile
                    result = value * 0.000568182;
                    break;
                default:
                    printf("\nInvalid output unit selection. Please try again.\n");
                    return 0;
            }
            break;
        case 8: // Mile
            switch(choice2) {
                case 1: // Meter
                    result = value * 1609.34;
                    break;
                case 2: // Kilometer
                    result = value * 1.60934;
                    break;
                case 3: // Centimeter
                    result = value * 160934;
                    break;
                case 4: // Millimeter
                    result = value * 1609344;
                    break;
                case 5: // Foot
                    result = value * 5280;
                    break;
                case 6: // Inch
                    result = value * 63360;
                    break;
                case 7: // Yard
                    result = value * 1760;
                    break;
                case 8: // Mile
                    result = value;
                    break;
                default:
                    printf("\nInvalid output unit selection. Please try again.\n");
                    return 0;
            }
            break;
        default:
            printf("\nInvalid input unit selection. Please try again.\n");
            return 0;
    }

    printf("\n%.2f in unit %d is equal to %.2f in unit %d.\n", value, choice1, result, choice2);
    printf("\nThank you for using Happy Unit Converter!");
    return 0;
}