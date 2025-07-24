//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Cyberpunk
#include <stdio.h>

int get_option() {
    int opt;
    printf("Choose conversion type:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    scanf("%d", &opt);
    return opt;
}

float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

void print_result(float result, char from_unit[], char to_unit[]) {
    printf("%.2f %s is equal to %.2f %s\n", result, from_unit, result, to_unit);
}

int main() {
    printf("Welcome to the Cyberpunk Temperature Converter!\n");
    int option = get_option();
    float input, result;
    char from_unit[10], to_unit[10];

    if (option == 1) {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &input);
        result = celsius_to_fahrenheit(input);
        sprintf(from_unit, "Celsius");
        sprintf(to_unit, "Fahrenheit");
    } else if (option == 2) {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &input);
        result = fahrenheit_to_celsius(input);
        sprintf(from_unit, "Fahrenheit");
        sprintf(to_unit, "Celsius");
    } else {
        printf("Invalid option selected!\n");
        return 1; // exit program with error code
    }

    print_result(input, from_unit, to_unit);
    return 0; // exit program
}