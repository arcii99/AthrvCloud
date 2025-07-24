//FormAI DATASET v1.0 Category: HTML beautifier ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 2000

char input[MAX_LINE_LENGTH];
char output[MAX_LINE_LENGTH];
int indent = 0;

void outputIndentation() {
    for (int i = 0; i < indent; i++) {
        strcat(output, "    ");
    }
}

void processLine(char *line) {
    int i = 0;
    while (line[i] == ' ' || line[i] == '\t') {
        i++;
    }

    if (line[i] == '}') {
        indent--;
        outputIndentation();
        strcat(output, "}\n");
        return;
    } else {
        outputIndentation();
        strcat(output, line);
        if (strstr(line, "{") != NULL) {
            indent++;
        }
    }
}

int main() {
    printf("Enter HTML code to beautify:\n");

    int lineNo = 1;
    while (fgets(input, MAX_LINE_LENGTH, stdin) != NULL) {
        processLine(input);
        lineNo++;
    }

    output[strlen(output) - 1] = '\0'; // remove trailing newline

    printf("\nHere is your beautified HTML:\n\n%s", output);

    return 0;
}