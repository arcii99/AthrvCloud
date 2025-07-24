//FormAI DATASET v1.0 Category: Temperature monitor ; Style: sophisticated
// C Temperature Monitor Example Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEMP 100 // Maximum temperature for the monitor
#define MIN_TEMP 0 // Minimum temperature for the monitor
#define MAX_LENGTH 50 // Maximum length of the input string
#define ERROR_VALUE -999 // Value to return in case of error
#define ERROR_MSG "Error" // Error message to display

typedef struct {
    float temperature; // The temperature value
    char unit; // C or F for Celsius or Fahrenheit
} Temperature;

Temperature read_temperature() {
    Temperature t; // Create a new temperature object
    char input[MAX_LENGTH] = ""; // Create a new input string
    printf("Enter temperature (e.g. 20C or 68F): ");
    fgets(input, MAX_LENGTH, stdin); // Get user input

    // Remove newline character from input string
    if ((strlen(input) > 0) && (input[strlen(input) - 1] == '\n'))
        input[strlen(input) - 1] = '\0';

    // Check for invalid input
    if ((strlen(input) < 2) || (strlen(input) > 3) || (input[strlen(input)-1] != 'C' && input[strlen(input)-1] != 'F') || (atof(input) > MAX_TEMP) || (atof(input) < MIN_TEMP)) {
        printf("%s: Invalid input\n", ERROR_MSG);
        t.temperature = ERROR_VALUE; // Set temperature value to error value
        return t;
    }

    // If input is valid, assign values to temperature object
    t.temperature = atof(input);
    t.unit = input[strlen(input)-1];

    return t;
}

void print_temperature(Temperature t) {
    if (t.temperature == ERROR_VALUE) { // Check for error value
        printf("%s: Invalid Temperature\n", ERROR_MSG);
        return;
    }

    printf("Temperature: %.2f%c\n", t.temperature, t.unit);
}

int main() {
    Temperature t = read_temperature(); // Read temperature from user input
    print_temperature(t); // Print temperature

    return 0;
}