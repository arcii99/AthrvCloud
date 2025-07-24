//FormAI DATASET v1.0 Category: HTML beautifier ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void indent_line(int num_indents) {
    for (int i = 0; i < num_indents; i++) {
        printf("    ");
    }
}

int main() {
    const int MAX_LEN = 500;
    char line[MAX_LEN];
    int num_indents = 0;

    printf("Enter the HTML code to beautify:\n");
    while (fgets(line, MAX_LEN, stdin) != NULL) {
        // Remove trailing newline
        line[strcspn(line, "\n")] = 0;

        // Check for end tag
        int len = strlen(line);
        if (len > 0 && line[0] == '<' && line[1] == '/') {
            num_indents--;
        }

        // Indent line
        indent_line(num_indents);

        // Print line
        printf("%s\n", line);

        // Check for start tag
        if (len > 0 && line[0] == '<' && line[len - 1] == '>') {
            num_indents++;
        }
    }

    return 0;
}