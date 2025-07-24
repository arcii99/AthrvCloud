//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

typedef struct {
    char key[50];
    char value[500];
} Metadata;

void extract_metadata(char *filename) {
    char line[MAX_LENGTH];
    FILE *file = fopen(filename, "r");
    Metadata metadata[50];
    int i = 0;

    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    while (fgets(line, MAX_LENGTH, file)) {
        if (strstr(line, "Metadata:") != NULL) {
            char *key = strtok(line, ":");
            char *value = strtok(NULL, "\n");
            strcpy(metadata[i].key, key);
            strcpy(metadata[i].value, value);
            i++;
        }
    }

    fclose(file);

    for (int j = 0; j < i; j++) {
        printf("%s: %s\n", metadata[j].key, metadata[j].value);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Please provide the filename as an argument.\n");
        exit(1);
    }

    extract_metadata(argv[1]);

    return 0;
}