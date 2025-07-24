//FormAI DATASET v1.0 Category: Temperature monitor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_TEMP 100 // maximum temperature value

// Function that checks if a string is numeric or not
bool isNumeric(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

// Function that prompts the user for input and returns as an integer
int getIntegerInput() {
    char input[10];
    int numInput;

    // Get user input as a string
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // remove newline character 

    // Check if string is numeric
    while (!isNumeric(input)) {
        printf("Invalid input. Please enter a numeric value: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0'; // remove newline character
    }

    // Convert string to integer and return
    numInput = atoi(input);
    return numInput;
}

int main() {
    int temperature;
    char input[10];

    printf("Temperature Monitor Program\n");
    printf("------------------------------\n");

    // Get temperature input from user
    printf("Enter current temperature (in Celsius): ");
    temperature = getIntegerInput();

    // Check temperature value is within acceptable range
    while (temperature > MAX_TEMP) {
        printf("Temperature is too high. Please enter a lower value than %d: ", MAX_TEMP);
        temperature = getIntegerInput();
    }

    // Display temperature
    printf("Current temperature: %d°C\n", temperature);

    return 0;
}