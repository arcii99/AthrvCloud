//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_METADATA_LENGTH 100

void extract_metadata(char *line, char *metadata) {
    // Function to extract metadata from the given line
    char *ptr1, *ptr2;
    ptr1 = strstr(line, "/*");
    ptr2 = strstr(line, "*/");
    if (ptr1 && ptr2) {
        // Extract metadata between the start and end of the comment block
        strncpy(metadata, ptr1 + 2, ptr2 - ptr1 - 2);
        metadata[ptr2 - ptr1 - 2] = '\0';
    }
}

int main() {
    FILE *fp;
    fp = fopen("example.c", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    char metadata[MAX_METADATA_LENGTH];
    int line_num = 1;

    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        extract_metadata(line, metadata);
        if (strlen(metadata) > 0) {
            // Print metadata along with the line number
            printf("Line %d: %s\n", line_num, metadata);
        }
        line_num++;
    }

    fclose(fp);
    return 0;
}