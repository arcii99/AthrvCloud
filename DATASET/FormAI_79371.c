//FormAI DATASET v1.0 Category: Text processing ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

int read_lines(char** lines) {
    char buffer[MAX_LINE_LENGTH];
    int i = 0;

    do {
        printf("Enter a line of text (or empty line to stop): ");
        fgets(buffer, MAX_LINE_LENGTH, stdin);

        // replace newline character with null terminator
        char* newline = strchr(buffer, '\n');
        if (newline) {
            *newline = '\0';
        }

        // check if line is not empty
        if (strlen(buffer) > 0) {
            // allocate memory for the line
            lines[i] = malloc(MAX_LINE_LENGTH * sizeof(char));
            // copy the line to the allocated memory
            strcpy(lines[i], buffer);
            i++;
        }
        // limit number of lines to 10
        if (i == 10) {
            break;
        }
    } while (strlen(buffer) > 0);

    return i;
}

void remove_spaces(char* line) {
    int i = 0, j = 0;
    while (line[i]) {
        if (line[i] != ' ') {
            line[j++] = line[i];
        }
        i++;
    }
    line[j] = '\0';
}

int main() {
    char* lines[10];
    int num_lines = read_lines(lines);

    printf("\nOriginal text:\n");
    for (int i = 0; i < num_lines; i++) {
        printf("%s\n", lines[i]);
    }

    printf("\nText without spaces:\n");
    for (int i = 0; i < num_lines; i++) {
        remove_spaces(lines[i]);
        printf("%s\n", lines[i]);
    }

    // free memory allocated for lines
    for (int i = 0; i < num_lines; i++) {
        free(lines[i]);
    }

    return 0;
}