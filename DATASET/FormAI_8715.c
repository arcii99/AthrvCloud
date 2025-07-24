//FormAI DATASET v1.0 Category: HTML beautifier ; Style: ephemeral
#include <stdio.h>
#include <string.h>

int main() {
    // First, ask the user for the HTML code to beautify
    printf("Please enter the HTML code to beautify:\n");
    char html[10000];
    fgets(html, 10000, stdin);

    // Now, let's beautify the code!
    int indent_level = 0;
    char indent[1000] = "";
    char output[10000] = "";
    char* token = strtok(html, "<");
    while (token != NULL) {
        if (token[0] == '/') {
            // End tag, decrease indent level
            indent_level--;
        }
        for (int i = 0; i < indent_level; i++) {
            strcat(output, "    ");
        }
        strcat(output, "<");
        strcat(output, token);
        if (token[strlen(token) - 2] == '/') {
            // Self closing tag, no need to increase indent level
            strcat(output, ">\n");
        } else if (token[0] != '/') {
            // Start tag, increase indent level
            strcat(output, ">\n");
            indent_level++;
        } else {
            // End tag, no need to add new line
            strcat(output, ">");
        }
        token = strtok(NULL, "<");
    }

    // Finally, print the beautified code
    printf("Beautified HTML code:\n");
    printf("%s", output);

    return 0;
}