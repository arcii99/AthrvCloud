//FormAI DATASET v1.0 Category: Unit converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONVERTERS 10
#define MAX_NAME_LENGTH 20

// Declare the conversion function type
typedef double (*conversion_function)(double);

// Declare the converter struct
typedef struct {
    char name[MAX_NAME_LENGTH];
    char from_unit[MAX_NAME_LENGTH];
    char to_unit[MAX_NAME_LENGTH];
    conversion_function func;
} converter;

// Define the conversion functions
double feet_to_meters(double value) {
    return value * 0.3048;
}

double miles_to_kilometers(double value) {
    return value * 1.609344;
}

// Declare the converters array
converter converters[MAX_CONVERTERS];

// Add a new converter to the array
void add_converter(char *name, char *from_unit, char *to_unit, conversion_function func) {
    // Initialize a new converter
    converter conv;
    strcpy(conv.name, name);
    strcpy(conv.from_unit, from_unit);
    strcpy(conv.to_unit, to_unit);
    conv.func = func;
    
    // Find the first available slot in the array
    int i;
    for (i = 0; i < MAX_CONVERTERS; i++) {
        if (strcmp(converters[i].name, "") == 0) {
            converters[i] = conv;
            break;
        }
    }
    
    // If there is no available slot, print an error message
    if (i == MAX_CONVERTERS) {
        printf("Error: Maximum number of converters reached.\n");
    }
}

// Convert a value using the specified converter
double convert(double value, converter conv) {
    return conv.func(value);
}

int main() {
    // Add some converters
    add_converter("Feet to Meters", "ft", "m", feet_to_meters);
    add_converter("Miles to Kilometers", "mi", "km", miles_to_kilometers);
    
    // Choose a converter
    int choice;
    printf("Choose a converter:\n");
    int i;
    for (i = 0; i < MAX_CONVERTERS; i++) {
        if (strcmp(converters[i].name, "") != 0) {
            printf("%d. %s (%s to %s)\n", i + 1, converters[i].name, converters[i].from_unit, converters[i].to_unit);
        }
    }
    scanf("%d", &choice);
    
    // If the choice is invalid, print an error message and exit
    if (choice < 1 || choice > i) {
        printf("Error: Invalid choice.\n");
        return 0;
    }
    
    // Convert a value
    double value;
    printf("Enter a value in %s:\n", converters[choice - 1].from_unit);
    scanf("%lf", &value);
    double result = convert(value, converters[choice - 1]);
    printf("%f %s = %f %s\n", value, converters[choice - 1].from_unit, result, converters[choice - 1].to_unit);
    
    return 0;
}