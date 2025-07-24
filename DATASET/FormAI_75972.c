//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 1024
#define MAX_INPUT 1024

int main() {
    char input[MAX_INPUT];
    char line[MAX_LINE];
    char *filename = "./log.txt";
    int line_number = 0;

    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("File not found or couldn't open: %s\n", filename);
        return 1;
    }

    printf("Enter a keyword to search for: ");
    fgets(input, MAX_INPUT, stdin);
    strtok(input, "\n");

    printf("Analyzing log file for keyword \"%s\"...\n", input);

    while (fgets(line, MAX_LINE, file)) {
        line_number++;

        char *match = strstr(line, input);

        if (match != NULL) {
            printf("Intrusion detected on line %d\n", line_number);
            printf("%s", line);
        }
    }

    printf("Analysis complete\n");

    fclose(file);
    return 0;
}