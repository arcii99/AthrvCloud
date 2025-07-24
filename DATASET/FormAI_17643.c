//FormAI DATASET v1.0 Category: HTML beautifier ; Style: scientific
// C HTML Beautifier
// Written by [Your Name]

#include <stdio.h>
#include <string.h>

#define MAX_LINE_SIZE 1000
#define TAB_SIZE 4

void printTabs(int numTabs) {
    for (int i = 0; i < numTabs; i++) {
        printf("\t");
    }
}

int main() {
    char line[MAX_LINE_SIZE];
    int numTabs = 0;

    printf("Enter HTML code:\n");

    while (fgets(line, MAX_LINE_SIZE, stdin)) {
        line[strcspn(line, "\r\n")] = 0; // Remove newline character

        if (strcmp(line, "") == 0) { // Ignore blank lines
            continue;
        }

        if (strstr(line, "</") != NULL) { // Closing tag
            numTabs--;
        }

        printTabs(numTabs);
        printf("%s\n", line);

        if (strstr(line, "<") != NULL && strstr(line, "</") == NULL) { // Opening tag
            numTabs++;
        }
    }

    return 0;
}