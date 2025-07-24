//FormAI DATASET v1.0 Category: HTML beautifier ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A function to remove all the white spaces from a given string.
void removeWhiteSpace(char str[]) {
    int i, j;
    for (i = 0; str[i] != '\0'; i++) {
        while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
            for (j = i; str[j] != '\0'; j++) {
                str[j] = str[j + 1];
            }
            str[j] = '\0';
        }
    }
}

// A function to add indent to a given line based on the given number.
// The indent character used here is a tab ('\t').
void addIndent(char str[], int level) {
    int i;
    for (i = 0; i < level; i++) {
        strcat(str, "\t");
    }
}

// A function to beautify a given HTML code.
void beautifyHTML(char input[], char output[]) {
    int i, level = 0;
    char currLine[1000];

    for (i = 0; input[i] != '\0';) {
        // Extract the current line from the input.
        int j = i;
        while (input[j] != '\n' && input[j] != '\0') {
            currLine[j - i] = input[j];
            j++;
        }
        currLine[j - i] = '\0';

        // Calculate the number of spaces needed for indent.
        int indent = level;
        if (strstr(currLine, "</") != NULL) {
            indent--;
        }
        if (strcmp(currLine, "</html>") == 0) {
            // Reset the indent level if the end tag for <html> is found.
            level = 0;
        }

        // Add indent to the output before adding the current line.
        addIndent(output, indent);

        // Add the current line to the output.
        strcat(output, currLine);
        strcat(output, "\n");

        if (strstr(currLine, "<") != NULL && strstr(currLine, "</") == NULL) {
            // Increase the indent level if a start tag is found.
            level++;
        }

        i = j + 1;
    }
}

int main() {
    char input[] = "<html><head><title>Example HTML page</title></head><body><h1>Example</h1><p>This is an example HTML page.</p><ul><li>Item 1</li><li>Item 2</li><li>Item 3</li></ul></body></html>";
    char output[1000];

    // Remove all the white spaces from the input.
    removeWhiteSpace(input);

    // Beautify the input and store the result in the output.
    beautifyHTML(input, output);

    printf("%s\n", output);

    return 0;
}