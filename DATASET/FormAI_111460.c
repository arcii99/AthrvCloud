//FormAI DATASET v1.0 Category: Unit converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare variables
    double input_value = 0.0;
    int input_unit = 0;
    int output_unit = 0;
    double conversion_factor = 0.0;
    double output_value = 0.0;

    // Display list of units
    printf("*** Unit Converter ***\n");
    printf("1. Kilometer\n");
    printf("2. Meter\n");
    printf("3. Centimeter\n");
    printf("4. Millimeter\n");
    printf("5. Micrometer\n");
    printf("6. Nanometer\n");
    printf("7. Mile\n");
    printf("8. Yard\n");
    printf("9. Foot\n");
    printf("10. Inch\n");

    // Get user input for input unit
    printf("Enter input unit: ");
    scanf("%d", &input_unit);

    // Get user input for output unit
    printf("Enter output unit: ");
    scanf("%d", &output_unit);

    // Get user input for input value
    printf("Enter input value: ");
    scanf("%lf", &input_value);
    
	// Set conversion factor
	switch (input_unit) {
		case 1: // Kilometer
			switch (output_unit) {
				case 2: // Meter
					conversion_factor = 1000.0;
					break;
				case 3: // Centimeter
					conversion_factor = 100000.0;
					break;
				case 4: // Millimeter
					conversion_factor = 1000000.0;
					break;
				case 5: // Micrometer
					conversion_factor = 1.0e+9;
					break;
				case 6: // Nanometer
					conversion_factor = 1.0e+12;
					break;
				case 7: // Mile
					conversion_factor = 0.621371;
					break;
				case 8: // Yard
					conversion_factor = 1093.61;
					break;
				case 9: // Foot
					conversion_factor = 3280.84;
					break;
				case 10: // Inch
					conversion_factor = 39370.1;
					break;
				default:
					printf("Invalid output unit.\n");
					exit(EXIT_FAILURE);
			}
			break;
		case 2: // Meter
			switch (output_unit) {
				case 1: // Kilometer
					conversion_factor = 0.001;
					break;
				case 3: // Centimeter
					conversion_factor = 100.0;
					break;
				case 4: // Millimeter
					conversion_factor = 1000.0;
					break;
				case 5: // Micrometer
					conversion_factor = 1.0e+6;
					break;
				case 6: // Nanometer
					conversion_factor = 1.0e+9;
					break;
				case 7: // Mile
					conversion_factor = 0.000621371;
					break;
				case 8: // Yard
					conversion_factor = 1.09361;
					break;
				case 9: // Foot
					conversion_factor = 3.28084;
					break;
				case 10: // Inch
					conversion_factor = 39.3701;
					break;
				default:
					printf("Invalid output unit.\n");
					exit(EXIT_FAILURE);
			}
			break;
		case 3: // Centimeter
			switch (output_unit) {
				case 1: // Kilometer
					conversion_factor = 0.00001;
					break;
				case 2: // Meter
					conversion_factor = 0.01;
					break;
				case 4: // Millimeter
					conversion_factor = 10.0;
					break;
				case 5: // Micrometer
					conversion_factor = 10000.0;
					break;
				case 6: // Nanometer
					conversion_factor = 1.0e+7;
					break;
				case 7: // Mile
					conversion_factor = 6.21371e-6;
					break;
				case 8: // Yard
					conversion_factor = 0.0109361;
					break;
				case 9: // Foot
					conversion_factor = 0.0328084;
					break;
				case 10: // Inch
					conversion_factor = 0.393701;
					break;
				default:
					printf("Invalid output unit.\n");
					exit(EXIT_FAILURE);
			}
			break;
		case 4: // Millimeter
			switch (output_unit) {
				case 1: // Kilometer
					conversion_factor = 1.0e-6;
					break;
				case 2: // Meter
					conversion_factor = 0.001;
					break;
				case 3: // Centimeter
					conversion_factor = 0.1;
					break;
				case 5: // Micrometer
					conversion_factor = 1000.0;
					break;
				case 6: // Nanometer
					conversion_factor = 1.0e+6;
					break;
				case 7: // Mile
					conversion_factor = 6.21371e-7;
					break;
				case 8: // Yard
					conversion_factor = 0.00109361;
					break;
				case 9: // Foot
					conversion_factor = 0.00328084;
					break;
				case 10: // Inch
					conversion_factor = 0.0393701;
					break;
				default:
					printf("Invalid output unit.\n");
					exit(EXIT_FAILURE);
			}
			break;
		case 5: // Micrometer
			switch (output_unit) {
				case 1: // Kilometer
					conversion_factor = 1.0e-9;
					break;
				case 2: // Meter
					conversion_factor = 1.0e-6;
					break;
				case 3: // Centimeter
					conversion_factor = 1.0e-4;
					break;
				case 4: // Millimeter
					conversion_factor = 0.001;
					break;
				case 6: // Nanometer
					conversion_factor = 1000.0;
					break;
				case 7: // Mile
					conversion_factor = 6.21371e-10;
					break;
				case 8: // Yard
					conversion_factor = 1.09361e-6;
					break;
				case 9: // Foot
					conversion_factor = 3.28084e-6;
					break;
				case 10: // Inch
					conversion_factor = 3.93701e-5;
					break;
				default:
					printf("Invalid output unit.\n");
					exit(EXIT_FAILURE);
			}
			break;
		case 6: // Nanometer
			switch (output_unit) {
				case 1: // Kilometer
					conversion_factor = 1.0e-12;
					break;
				case 2: // Meter
					conversion_factor = 1.0e-9;
					break;
				case 3: // Centimeter
					conversion_factor = 1.0e-7;
					break;
				case 4: // Millimeter
					conversion_factor = 1.0e-6;
					break;
				case 5: // Micrometer
					conversion_factor = 0.001;
					break;
				case 7: // Mile
					conversion_factor = 6.21371e-13;
					break;
				case 8: // Yard
					conversion_factor = 1.09361e-9;
					break;
				case 9: // Foot
					conversion_factor = 3.28084e-9;
					break;
				case 10: // Inch
					conversion_factor = 3.93701e-8;
					break;
				default:
					printf("Invalid output unit.\n");
					exit(EXIT_FAILURE);
			}
			break;
		case 7: // Mile
			switch (output_unit) {
				case 1: // Kilometer
					conversion_factor = 1.60934;
					break;
				case 2: // Meter
					conversion_factor = 1609.34;
					break;
				case 3: // Centimeter
					conversion_factor = 160934.0;
					break;
				case 4: // Millimeter
					conversion_factor = 1.60934e+6;
					break;
				case 5: // Micrometer
					conversion_factor = 1.60934e+9;
					break;
				case 6: // Nanometer
					conversion_factor = 1.60934e+12;
					break;
				case 8: // Yard
					conversion_factor = 1760.0;
					break;
				case 9: // Foot
					conversion_factor = 5280.0;
					break;
				case 10: // Inch
					conversion_factor = 63360.0;
					break;
				default:
					printf("Invalid output unit.\n");
					exit(EXIT_FAILURE);
			}
			break;
		case 8: // Yard
			switch (output_unit) {
				case 1: // Kilometer
					conversion_factor = 0.0009144;
					break;
				case 2: // Meter
					conversion_factor = 0.9144;
					break;
				case 3: // Centimeter
					conversion_factor = 91.44;
					break;
				case 4: // Millimeter
					conversion_factor = 914.4;
					break;
				case 5: // Micrometer
					conversion_factor = 914400.0;
					break;
				case 6: // Nanometer
					conversion_factor = 9.144e+8;
					break;
				case 7: // Mile
					conversion_factor = 0.000568182;
					break;
				case 9: // Foot
					conversion_factor = 3.0;
					break;
				case 10: // Inch
					conversion_factor = 36.0;
					break;
				default:
					printf("Invalid output unit.\n");
					exit(EXIT_FAILURE);
			}
			break;
		case 9: // Foot
			switch (output_unit) {
				case 1: // Kilometer
					conversion_factor = 0.0003048;
					break;
				case 2: // Meter
					conversion_factor = 0.3048;
					break;
				case 3: // Centimeter
					conversion_factor = 30.48;
					break;
				case 4: // Millimeter
					conversion_factor = 304.8;
					break;
				case 5: // Micrometer
					conversion_factor = 304800.0;
					break;
				case 6: // Nanometer
					conversion_factor = 3.048e+8;
					break;
				case 7: // Mile
					conversion_factor = 0.000189394;
					break;
				case 8: // Yard
					conversion_factor = 0.333333;
					break;
				case 10: // Inch
					conversion_factor = 12.0;
					break;
				default:
					printf("Invalid output unit.\n");
					exit(EXIT_FAILURE);
			}
			break;
		case 10: // Inch
			switch (output_unit) {
				case 1: // Kilometer
					conversion_factor = 2.54e-5;
					break;
				case 2: // Meter
					conversion_factor = 0.0254;
					break;
				case 3: // Centimeter
					conversion_factor = 2.54;
					break;
				case 4: // Millimeter
					conversion_factor = 25.4;
					break;
				case 5: // Micrometer
					conversion_factor = 25400.0;
					break;
				case 6: // Nanometer
					conversion_factor = 2.54e+7;
					break;
				case 7: // Mile
					conversion_factor = 1.57828e-5;
					break;
				case 8: // Yard
					conversion_factor = 0.0277778;
					break;
				case 9: // Foot
					conversion_factor = 0.0833333;
					break;
				default:
					printf("Invalid output unit.\n");
					exit(EXIT_FAILURE);
			}
			break;
		default:
			printf("Invalid input unit.\n");
			exit(EXIT_FAILURE);
	}

	// Calculate output value
	output_value = input_value * conversion_factor;

	// Display results
	printf("%lf %d(s) = %lf %d(s)\n", input_value, input_unit, output_value, output_unit);

    return 0;
}