//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// This program extracts metadata from a file and prints it to the console
// It searches for a specific string and outputs relevant information

int main() {
    FILE *file = fopen("example.txt", "r");
    char line[100];
    int lineNum = 0;
    int count = 0;

    if (file) {
        while(fgets(line, sizeof(line), file)) {
            lineNum++;
            if (strstr(line, "metadata")) {
                count++;
                printf("Metadata #%d found on line %d:\n", count, lineNum);
                printf("%s", line);
            }
        }
        fclose(file);
    }

    if (count == 0) {
        printf("No metadata found in file.\n");
    } else {
        printf("Metadata found: %d\n", count);
    }

    return 0;
}