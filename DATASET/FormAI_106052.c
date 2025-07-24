//FormAI DATASET v1.0 Category: Unit converter ; Style: interoperable
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
double celsius_to_fahrenheit(double temp) {
    return (temp * 9/5) + 32;
}

// Function to convert Fahrenheit to Celsius
double fahrenheit_to_celsius(double temp) {
    return (temp - 32) * 5/9;
}

// Function to convert meters to feet
double meters_to_feet(double length) {
    return length * 3.281;
}

// Function to convert feet to meters
double feet_to_meters(double length) {
    return length / 3.281;
}

int main() {
    // User input variables
    double input_temp, output_temp, input_length, output_length;
    int choice;

    // Menu
    printf("Which conversion would you like to do?\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Meters to Feet\n");
    printf("4. Feet to Meters\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &input_temp);
            output_temp = celsius_to_fahrenheit(input_temp);
            printf("%lf degrees Celsius is %lf degrees Fahrenheit\n", input_temp, output_temp);
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%lf", &input_temp);
            output_temp = fahrenheit_to_celsius(input_temp);
            printf("%lf degrees Fahrenheit is %lf degrees Celsius\n", input_temp, output_temp);
            break;
        case 3:
            printf("Enter length in meters: ");
            scanf("%lf", &input_length);
            output_length = meters_to_feet(input_length);
            printf("%lf meters is %lf feet\n", input_length, output_length);
            break;
        case 4:
            printf("Enter length in feet: ");
            scanf("%lf", &input_length);
            output_length = feet_to_meters(input_length);
            printf("%lf feet is %lf meters\n", input_length, output_length);
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}