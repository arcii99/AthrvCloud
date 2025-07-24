//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LENGTH 256
#define MAX_METADATA_LENGTH 32

typedef struct {
    char key[MAX_STR_LENGTH];
    char value[MAX_STR_LENGTH];
} metadata_entry;

typedef struct {
    metadata_entry entries[MAX_METADATA_LENGTH];
    int num_entries;
} metadata;

metadata extract_metadata(const char *filename) {
    metadata md = {0};
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: file not found\n");
        return md;
    }

    char line[MAX_STR_LENGTH];
    int line_num = 1;

    while (fgets(line, MAX_STR_LENGTH, fp) != NULL && md.num_entries < MAX_METADATA_LENGTH) {
        if (line[0] == '#') {
            char *key = strtok(&line[1], ":");
            char *value = strtok(NULL, "\n");

            if (key != NULL && value != NULL) {
                metadata_entry entry = {0};
                strcpy(entry.key, key);
                strcpy(entry.value, value);
                md.entries[md.num_entries++] = entry;
            } else {
                printf("Warning: malformed metadata on line %d\n", line_num);
            }
        }

        line_num++;
    }

    fclose(fp);
    return md;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: metadata_extractor <filename>\n");
        return 1;
    }

    metadata md = extract_metadata(argv[1]);

    for (int i = 0; i < md.num_entries; i++) {
        printf("%s: %s\n", md.entries[i].key, md.entries[i].value);
    }

    return 0;
}