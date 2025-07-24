//FormAI DATASET v1.0 Category: Unit converter ; Style: sophisticated
#include <stdio.h>

char* input_unit();
char* output_unit();
double input_value();
double convert(double, char*, char*);

int main() {
    char* input_unit_label;
    char* output_unit_label;
    double input;
    double output;

    printf("Welcome to the Unit Converter!\n");
    printf("Select the input unit:\n");
    input_unit_label = input_unit();
    printf("Select the output unit:\n");
    output_unit_label = output_unit();
    printf("Enter the input value:\n");
    input = input_value();
    output = convert(input, input_unit_label, output_unit_label);
    printf("%f %s = %f %s\n", input, input_unit_label, output, output_unit_label);
    return 0;
}

char* input_unit() {
    int choice;
    printf("1. Meter\n");
    printf("2. Kilometer\n");
    printf("3. Centimeter\n");
    printf("4. Millimeter\n");
    printf("5. Micrometer\n");
    printf("6. Yard\n");
    printf("7. Mile\n");
    printf("8. Foot\n");
    printf("9. Inch\n");
    printf("Enter choice (1-9):\n");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            return "Meters";
        case 2:
            return "Kilometers";
        case 3:
            return "Centimeters";
        case 4:
            return "Millimeters";
        case 5:
            return "Micrometers";
        case 6:
            return "Yards";
        case 7:
            return "Miles";
        case 8:
            return "Feet";
        case 9:
            return "Inches";
        default:
            printf("Invalid choice, please try again.\n");
            return input_unit();
    }
}

char* output_unit() {
    int choice;
    printf("1. Meter\n");
    printf("2. Kilometer\n");
    printf("3. Centimeter\n");
    printf("4. Millimeter\n");
    printf("5. Micrometer\n");
    printf("6. Yard\n");
    printf("7. Mile\n");
    printf("8. Foot\n");
    printf("9. Inch\n");
    printf("Enter choice (1-9):\n");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            return "Meters";
        case 2:
            return "Kilometers";
        case 3:
            return "Centimeters";
        case 4:
            return "Millimeters";
        case 5:
            return "Micrometers";
        case 6:
            return "Yards";
        case 7:
            return "Miles";
        case 8:
            return "Feet";
        case 9:
            return "Inches";
        default:
            printf("Invalid choice, please try again.\n");
            return output_unit();
    }
}

double input_value() {
    double value;
    scanf("%lf", &value);
    return value;
}

double convert(double input, char* input_unit, char* output_unit) {
    double result;
    if (strcmp(input_unit, "Meters") == 0) {
        if (strcmp(output_unit, "Kilometers") == 0) {
            result = input * 0.001;
        } else if (strcmp(output_unit, "Centimeters") == 0) {
            result = input * 100;
        } else if (strcmp(output_unit, "Millimeters") == 0) {
            result = input * 1000;
        } else if (strcmp(output_unit, "Micrometers") == 0) {
            result = input * 1000000;
        } else if (strcmp(output_unit, "Yards") == 0) {
            result = input * 1.09361;
        } else if (strcmp(output_unit, "Miles") == 0) {
            result = input * 0.000621371;
        } else if (strcmp(output_unit, "Feet") == 0) {
            result = input * 3.28084;
        } else if (strcmp(output_unit, "Inches") == 0) {
            result = input * 39.3701;
        } else {
            result = input;
        }
    } else if (strcmp(input_unit, "Kilometers") == 0) {
        if (strcmp(output_unit, "Meters") == 0) {
            result = input * 1000;
        } else if (strcmp(output_unit, "Centimeters") == 0) {
            result = input * 100000;
        } else if (strcmp(output_unit, "Millimeters") == 0) {
            result = input * 1000000;
        } else if (strcmp(output_unit, "Micrometers") == 0) {
            result = input * 1000000000;
        } else if (strcmp(output_unit, "Yards") == 0) {
            result = input * 1093.61;
        } else if (strcmp(output_unit, "Miles") == 0) {
            result = input * 0.621371;
        } else if (strcmp(output_unit, "Feet") == 0) {
            result = input * 3280.84;
        } else if (strcmp(output_unit, "Inches") == 0) {
            result = input * 39370.1;
        } else {
            result = input;
        }
    } else if (strcmp(input_unit, "Centimeters") == 0) {
        if (strcmp(output_unit, "Meters") == 0) {
            result = input * 0.01;
        } else if (strcmp(output_unit, "Kilometers") == 0) {
            result = input * 0.00001;
        } else if (strcmp(output_unit, "Millimeters") == 0) {
            result = input * 10;
        } else if (strcmp(output_unit, "Micrometers") == 0) {
            result = input * 10000;
        } else if (strcmp(output_unit, "Yards") == 0) {
            result = input * 0.0109361;
        } else if (strcmp(output_unit, "Miles") == 0) {
            result = input * 0.00000621371;
        } else if (strcmp(output_unit, "Feet") == 0) {
            result = input * 0.0328084;
        } else if (strcmp(output_unit, "Inches") == 0) {
            result = input * 0.393701;
        } else {
            result = input;
        }
    } else if (strcmp(input_unit, "Millimeters") == 0) {
        if (strcmp(output_unit, "Meters") == 0) {
            result = input * 0.001;
        } else if (strcmp(output_unit, "Kilometers") == 0) {
            result = input * 0.000001;
        } else if (strcmp(output_unit, "Centimeters") == 0) {
            result = input * 0.1;
        } else if (strcmp(output_unit, "Micrometers") == 0) {
            result = input * 1000;
        } else if (strcmp(output_unit, "Yards") == 0) {
            result = input * 0.00109361;
        } else if (strcmp(output_unit, "Miles") == 0) {
            result = input * 0.000000621371;
        } else if (strcmp(output_unit, "Feet") == 0) {
            result = input * 0.00328084;
        } else if (strcmp(output_unit, "Inches") == 0) {
            result = input * 0.0393701;
        } else {
            result = input;
        }
    } else if (strcmp(input_unit, "Micrometers") == 0) {
        if (strcmp(output_unit, "Meters") == 0) {
            result = input * 0.000001;
        } else if (strcmp(output_unit, "Kilometers") == 0) {
            result = input * 0.000000001;
        } else if (strcmp(output_unit, "Centimeters") == 0) {
            result = input * 0.0001;
        } else if (strcmp(output_unit, "Millimeters") == 0) {
            result = input * 0.001;
        } else if (strcmp(output_unit, "Yards") == 0) {
            result = input * 0.00000109361;
        } else if (strcmp(output_unit, "Miles") == 0) {
            result = input * 0.000000000621371;
        } else if (strcmp(output_unit, "Feet") == 0) {
            result = input * 0.00000328084;
        } else if (strcmp(output_unit, "Inches") == 0) {
            result = input * 0.0000393701;
        } else {
            result = input;
        }
    } else if (strcmp(input_unit, "Yards") == 0) {
        if (strcmp(output_unit, "Meters") == 0) {
            result = input * 0.9144;
        } else if (strcmp(output_unit, "Kilometers") == 0) {
            result = input * 0.0009144;
        } else if (strcmp(output_unit, "Centimeters") == 0) {
            result = input * 91.44;
        } else if (strcmp(output_unit, "Millimeters") == 0) {
            result = input * 914.4;
        } else if (strcmp(output_unit, "Micrometers") == 0) {
            result = input * 914400;
        } else if (strcmp(output_unit, "Miles") == 0) {
            result = input * 0.000568182;
        } else if (strcmp(output_unit, "Feet") == 0) {
            result = input * 3;
        } else if (strcmp(output_unit, "Inches") == 0) {
            result = input * 36;
        } else {
            result = input;
        }
    } else if (strcmp(input_unit, "Miles") == 0) {
        if (strcmp(output_unit, "Meters") == 0) {
            result = input * 1609.34;
        } else if (strcmp(output_unit, "Kilometers") == 0) {
            result = input * 1.60934;
        } else if (strcmp(output_unit, "Centimeters") == 0) {
            result = input * 160934;
        } else if (strcmp(output_unit, "Millimeters") == 0) {
            result = input * 1609344;
        } else if (strcmp(output_unit, "Micrometers") == 0) {
            result = input * 1609344000;
        } else if (strcmp(output_unit, "Yards") == 0) {
            result = input * 1760;
        } else if (strcmp(output_unit, "Feet") == 0) {
            result = input * 5280;
        } else if (strcmp(output_unit, "Inches") == 0) {
            result = input * 63360;
        } else {
            result = input;
        }
    } else if (strcmp(input_unit, "Feet") == 0) {
        if (strcmp(output_unit, "Meters") == 0) {
            result = input * 0.3048;
        } else if (strcmp(output_unit, "Kilometers") == 0) {
            result = input * 0.0003048;
        } else if (strcmp(output_unit, "Centimeters") == 0) {
            result = input * 30.48;
        } else if (strcmp(output_unit, "Millimeters") == 0) {
            result = input * 304.8;
        } else if (strcmp(output_unit, "Micrometers") == 0) {
            result = input * 304800;
        } else if (strcmp(output_unit, "Yards") == 0) {
            result = input * 0.333333;
        } else if (strcmp(output_unit, "Miles") == 0) {
            result = input * 0.000189394;
        } else if (strcmp(output_unit, "Inches") == 0) {
            result = input * 12;
        } else {
            result = input;
        }
    } else if (strcmp(input_unit, "Inches") == 0) {
        if (strcmp(output_unit, "Meters") == 0) {
            result = input * 0.0254;
        } else if (strcmp(output_unit, "Kilometers") == 0) {
            result = input * 0.0000254;
        } else if (strcmp(output_unit, "Centimeters") == 0) {
            result = input * 2.54;
        } else if (strcmp(output_unit, "Millimeters") == 0) {
            result = input * 25.4;
        } else if (strcmp(output_unit, "Micrometers") == 0) {
            result = input * 25400;
        } else if (strcmp(output_unit, "Yards") == 0) {
            result = input * 0.0277778;
        } else if (strcmp(output_unit, "Miles") == 0) {
            result = input * 0.0000157828;
        } else if (strcmp(output_unit, "Feet") == 0) {
            result = input * 0.0833333;
        } else {
            result = input;
        }
    } else {
        result = input;
    }
    return result;
}