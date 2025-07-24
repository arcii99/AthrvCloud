//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAXLEN];

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Cannot open file %s\n", argv[1]);
        exit(1);
    }

    while (fgets(line, MAXLEN, fp) != NULL) {
        // Check for metadata tags
        if (strstr(line, "// @") != NULL) {
            printf("%s", line);
        }
    }

    fclose(fp);
    return 0;
}