//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: real-life
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Function to convert month name to its corresponding numerical value
int month_to_number(char *month) {
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August",
                      "September", "October", "November", "December"};
    int i;
    for (i = 0; i < 12; i++) {
        if (strcmp(month, months[i]) == 0)
            return i + 1;
    }
    return -1;
}

// Function to convert date in natural language format to YYYYMMDD format
void natural_to_numeric(char *input, char *output) {
    char *day, *month, *year;
    int month_number;

    // Split input string into separate day, month, and year variables
    day = strtok(input, " ");
    month = strtok(NULL, " ");
    year = strtok(NULL, " ");

    // Convert month name to its corresponding numerical value
    month_number = month_to_number(month);

    // Build output string in YYYYMMDD format
    sprintf(output, "%s%02d%s", year, month_number, day);
}

int main() {
    char input[100], output[100];

    // Prompt user for input in natural language format
    printf("Please enter a date in natural language format (e.g. January 1st, 2022): ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = 0;  // Remove trailing newline character

    // Convert input to YYYYMMDD format and display output
    natural_to_numeric(input, output);
    printf("The date in YYYYMMDD format is: %s\n", output);

    return 0;
}