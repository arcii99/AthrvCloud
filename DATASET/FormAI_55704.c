//FormAI DATASET v1.0 Category: Syntax parsing ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Define maximum length of input string
#define MAX_STRING_LENGTH 100

// Define custom struct to hold syntax information
typedef struct {
    char type[MAX_STRING_LENGTH];
    char name[MAX_STRING_LENGTH];
    char value[MAX_STRING_LENGTH];
} Syntax;

int main() {
    // Initialize array to hold syntax information
    Syntax syntax[10];

    // Define input string and get user input
    char input[MAX_STRING_LENGTH];
    printf("Enter a C syntax statement: ");
    fgets(input, MAX_STRING_LENGTH, stdin);

    // Initialize variables for parsing loop
    int i = 0;
    int j = 0;
    int k = 0;
    int start = 0;
    int end = 0;

    // Parse input string and populate syntax struct
    while (input[i] != '\0') {
        // Check for whitespace or end of string
        if (input[i] == ' ' || input[i] == '\n' || input[i] == '\0') {
            // If not currently in a syntax section, skip whitespace
            if (!start) {
                i++;
                continue;
            }
            // Set end index and copy syntax section to syntax struct
            end = i;
            char section[MAX_STRING_LENGTH];
            for (j = start; j < end; j++) {
                section[k] = input[j];
                k++;
            }
            section[k] = '\0';
            if (strncmp(section, "int", 3) == 0 || strncmp(section, "char", 4) == 0 || strncmp(section, "float", 5) == 0) {
                strncpy(syntax[0].type, section, MAX_STRING_LENGTH);
            } else if (strncmp(section, "=", 1) == 0) {
                strncpy(syntax[1].value, section + 1, MAX_STRING_LENGTH);
            } else {
                strncpy(syntax[2].name, section, MAX_STRING_LENGTH);
            }
            // Reset variables for next syntax section
            k = 0;
            start = 0;
        } else {
            // If currently in a syntax section, skip non-whitespace characters
            if (!start) {
                start = i;
            }
        }
        i++;
    }

    // Print syntax information
    printf("\nSyntax Information:\n");
    printf("Type: %s\n", syntax[0].type);
    printf("Name: %s\n", syntax[2].name);
    printf("Value: %s\n", syntax[1].value);

    return 0;
}