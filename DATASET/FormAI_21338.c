//FormAI DATASET v1.0 Category: HTML beautifier ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 1000 // Maximum allowed length of the input code

void addIndentation(char *str, int indentLevel);

int main() {
    char str[MAX_CHAR], formattedStr[MAX_CHAR];
    int indentLevel = 0, len, i, j;

    // Get code input from user
    printf("Enter input code below:\n");
    fgets(str, MAX_CHAR, stdin);

    // Calculate length of input
    len = strlen(str);

    // Loop through entire input code
    for(i = 0; i < len; i++) {
        // Current character is an opening angle bracket
        if(str[i] == '<') {
            // Check next character to see if it's closing angle bracket
            if(str[i+1] == '/') {
                // Decrease indentation level
                indentLevel--;
            }

            addIndentation(formattedStr, indentLevel);

            // Copy angle bracket to formatted string
            formattedStr[strlen(formattedStr)] = str[i];

            // Check if next character is closing angle bracket
            if(str[i+1] == '/') {
                addIndentation(formattedStr, indentLevel);
            }

            // Increase indentation level
            if(str[i+1] != '/') {
                indentLevel++;
            }
        }

        // Current character is a closing angle bracket
        else if(str[i] == '>') {
            formattedStr[strlen(formattedStr)] = str[i];

            // Add newline character after closing angle bracket
            formattedStr[strlen(formattedStr)] = '\n';
        }

        // Current character is not an angle bracket
        else {
            // Copy character to formatted string
            formattedStr[strlen(formattedStr)] = str[i];
        }
    }

    // Output formatted string
    printf("\nFormatted code below:\n%s", formattedStr);

    return 0;
}

// Function to add indentation to string
void addIndentation(char *str, int indentLevel) {
    int i;

    // Loop through desired indentation level
    for(i = 0; i < indentLevel; i++) {
        // Add four spaces for each indentation level
        strcat(str, "    ");
    }
}