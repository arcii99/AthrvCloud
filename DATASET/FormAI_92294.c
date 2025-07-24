//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INDENT_SIZE 4

int main() {
    char *filename = "index.html";
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: Unable to open file %s", filename);
        return 1;
    }

    char line[1024];
    int depth = 0;
    int i, j;

    while (fgets(line, sizeof(line), file)) {
        char *trimmed = strtok(line, "\n\r");

        for (i = 0; i < depth * INDENT_SIZE; i++) {
            printf(" ");
        }

        printf("%s", trimmed);

        if (strstr(trimmed, "</") != NULL) {
            depth--;
        }

        if (strstr(trimmed, "/>") == NULL && strstr(trimmed, "</") == NULL && trimmed[strlen(trimmed) - 1] != '>') {
            printf("\n");
            depth++;
        }
    }

    fclose(file);
    return 0;
}