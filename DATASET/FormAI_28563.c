//FormAI DATASET v1.0 Category: Unit converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    // Welcome message
    printf("Welcome to the Curious Unit Converter Program!\n");
    printf("Enter the unit and value to convert, followed by the desired unit:\n");

    char input[50];
    fgets(input, sizeof(input), stdin);
    strtok(input, "\n");
    printf("\n");

    char unit_from[20];
    int value;
    char unit_to[20];

    // Parse input string
    sscanf(input, "%d %s to %s", &value, unit_from, unit_to);

    // Convert units based on user input
    if (strcmp(unit_from, "cm") == 0 && strcmp(unit_to, "in") == 0) {
        printf("%d %s = %.2f %s\n", value, unit_from, value * 0.393701, unit_to);
    } else if (strcmp(unit_from, "in") == 0 && strcmp(unit_to, "cm") == 0) {
        printf("%d %s = %.2f %s\n", value, unit_from, value * 2.54, unit_to);
    } else if (strcmp(unit_from, "kg") == 0 && strcmp(unit_to, "lb") == 0) {
        printf("%d %s = %.2f %s\n", value, unit_from, value * 2.20462, unit_to);
    } else if (strcmp(unit_from, "lb") == 0 && strcmp(unit_to, "kg") == 0) {
        printf("%d %s = %.2f %s\n", value, unit_from, value * 0.453592, unit_to);
    } else {
        printf("Sorry, I didn't understand your input. Please try again with valid units.\n");
    }

    return 0;
}