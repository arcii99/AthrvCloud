//FormAI DATASET v1.0 Category: Text processing ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LINE_LEN 100

char* read_line();
void write_lines(char* lines[], int num);

int main()
{
    char* lines[MAX_LINES];
    int num_lines = 0;

    printf("Enter up to %d lines of text:\n", MAX_LINES);

    // Read lines of text from user input
    while (num_lines < MAX_LINES) {
        char* line = read_line();
        if (!line || strcmp(line, "quit") == 0) {
            break;
        }
        lines[num_lines++] = line;
    }

    // Sort lines in alphabetical order
    for (int i = 0; i < num_lines-1; i++) {
        for (int j = i+1; j < num_lines; j++) {
            if (strcmp(lines[i], lines[j]) > 0) {
                char* temp = lines[i];
                lines[i] = lines[j];
                lines[j] = temp;
            }
        }
    }

    printf("\nSorted lines:\n");

    // Write sorted lines to stdout
    write_lines(lines, num_lines);

    // Free allocated memory
    for (int i = 0; i < num_lines; i++) {
        free(lines[i]);
    }

    return 0;
}

char* read_line()
{
    char* line = (char*)malloc(MAX_LINE_LEN * sizeof(char));
    if (!line) {
        return NULL;
    }

    int i = 0;
    char c;
    do {
        c = getchar();
        if (c == EOF || c == '\n') {
            break;
        }
        line[i++] = c;
    } while (i < MAX_LINE_LEN-1);
    line[i] = '\0';

    if (strlen(line) == 0) {
        free(line);
        return NULL;
    }

    return line;
}

void write_lines(char* lines[], int num)
{
    for (int i = 0; i < num; i++) {
        printf("%s\n", lines[i]);
    }
}