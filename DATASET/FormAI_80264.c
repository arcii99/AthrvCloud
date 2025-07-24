//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure to store metadata */
struct metadata {
    char author[50];
    char date[20];
    char description[100];
};

/* Function to extract metadata */
struct metadata extract_metadata(const char *filename) {
    struct metadata meta = {"", "", ""};
    char buffer[256];
    char *line, *key, *value;
    FILE *file = fopen(filename, "r");

    if (file) {
        while (fgets(buffer, sizeof(buffer), file)) {
            line = strdup(buffer);
            key = strtok(line, ":");
            value = strtok(NULL, "\n");

            if (key && value) {
                if (strcmp(key, "Author") == 0) {
                    strcpy(meta.author, value);
                } else if (strcmp(key, "Date") == 0) {
                    strcpy(meta.date, value);
                } else if (strcmp(key, "Description") == 0) {
                    strcpy(meta.description, value);
                }
            }
        }
        fclose(file);
    }

    return meta;
}

/* Main function to test the metadata extractor */
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    struct metadata meta = extract_metadata(argv[1]);
    printf("Author: %s\nDate: %s\nDescription: %s\n", meta.author, meta.date, meta.description);

    return 0;
}