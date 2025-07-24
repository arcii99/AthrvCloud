//FormAI DATASET v1.0 Category: Text processing ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_CHARS 100

int main() {
    char input[MAX_LINES][MAX_CHARS];
    int line_count = 0;

    // read input from user
    printf("Enter text (max %d lines, %d characters per line):\n", MAX_LINES, MAX_CHARS);
    while (fgets(input[line_count], MAX_CHARS, stdin)) {
        input[line_count][strlen(input[line_count]) - 1] = '\0'; // remove trailing newline
        line_count++;
        if (line_count >= MAX_LINES) break;
    }

    // process each line of input
    for (int i = 0; i < line_count; i++) {
        char *token = strtok(input[i], " "); // get first word
        while (token != NULL) {
            // replace any occurrence of "example" with "demo"
            if (strcmp(token, "example") == 0) {
                printf("demo ");
            } else {
                printf("%s ", token);
            }
            token = strtok(NULL, " "); // get next word
        }
        printf("\n"); // end the line of output
    }

    return 0;
}