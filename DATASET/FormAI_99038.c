//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: ephemeral
// Ephemeral C Metadata Extractor

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Usage: %s [file]\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char line[100];
    char *metadata = (char *)malloc(sizeof(char) * 1000);
    metadata[0] = '\0';

    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "//META", 6) == 0) {
            strcat(metadata, line + 6);
        }
    }

    fclose(file);

    printf("Metadata:\n%s\n", metadata);

    free(metadata);

    return 0;
}