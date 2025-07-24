//FormAI DATASET v1.0 Category: HTML beautifier ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char filename[100];
    char line[1000];
    int indent = 0;

    printf("Enter the file name: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("File does not exist.");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), fp)) {
        line[strcspn(line, "\n")] = 0; // Remove newline character at the end of the line
        for (int i = 0; i < indent; i++) { // Add indentation
            printf("  ");
        }
        printf("%s\n", line);

        if (strstr(line, "<html>") || strstr(line, "<head>") || strstr(line, "<body>")) { // Increase indentation
            indent++;
        }

        if (strstr(line, "</html>") || strstr(line, "</head>") || strstr(line, "</body>")) { // Decrease indentation
            indent--;
        }
    }

    fclose(fp);

    return 0;
}