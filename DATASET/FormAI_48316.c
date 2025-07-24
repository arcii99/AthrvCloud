//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    char *filename = argv[1];

    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        exit(1);
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "//", 2)) {
            continue;
        }

        char *metadata = line + 2;
        char *key = strtok(metadata, ":");
        char *value = strtok(NULL, "\n");

        printf("%s=%s\n", key, value);
    }

    fclose(file);

    return 0;
}