//FormAI DATASET v1.0 Category: HTML beautifier ; Style: expert-level
#include <stdio.h>
#include <stdbool.h>

// function to check if a character is a space, tab or newline
bool isWhitespace(char c) {
    return (c == ' ' || c == '\t' || c == '\n');
}

// function to remove leading whitespace from a line
void trimLeadingWhitespace(char line[]) {
    int i, j;
    for (i = 0; isWhitespace(line[i]); i++) {
        // do nothing, just keep moving forward
    }
    if (i > 0) {
        for (j = 0; line[j + i] != '\0'; j++) {
            line[j] = line[j + i];
        }
        line[j] = '\0';
    }
}

// function to beautify a single line of HTML
void beautifyLine(char line[]) {
    trimLeadingWhitespace(line);
    printf("%s\n", line);
}

int main() {
    char line[1000];
    FILE *htmlFile = fopen("example.html", "r");
    if (htmlFile == NULL) {
        printf("Error opening file!");
        return 1;
    }
    while (fgets(line, sizeof(line), htmlFile)) {
        beautifyLine(line);
    }
    fclose(htmlFile);
    return 0;
}