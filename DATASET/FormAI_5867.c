//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_METADATA_SIZE 1000

typedef struct {
    char key[50];
    char value[200];
} metadata_t;

void extract_metadata(const char* filepath, metadata_t metadata[], int max_metadata_size) {
    FILE* file = fopen(filepath, "rb");
    if (!file) {
        printf("Error: could not open file %s", filepath);
        return;
    }

    char buffer[1024];
    int metadata_count = 0;
    while (fgets(buffer, sizeof(buffer), file)) {
        if (strncmp(buffer, "##", 2) == 0) {
            if (metadata_count < max_metadata_size) {
                char* key = strtok(buffer+2, ":");
                char* value = strtok(NULL, "\n");
                if (key && value) {
                    strncpy(metadata[metadata_count].key, key, sizeof(metadata[metadata_count].key));
                    strncpy(metadata[metadata_count].value, value+1, sizeof(metadata[metadata_count].value));
                    metadata_count++;
                }
            } else {
                printf("Warning: max metadata size exceeded, some metadata may have been skipped");
                break;
            }
        }
    }
    fclose(file);

    printf("Extracted %d metadata items from file %s:\n", metadata_count, filepath);
    for (int i = 0; i < metadata_count; i++) {
        printf("%s: %s\n", metadata[i].key, metadata[i].value);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: metadata_extractor <filename>");
        return 1;
    }

    metadata_t metadata[MAX_METADATA_SIZE];
    extract_metadata(argv[1], metadata, MAX_METADATA_SIZE);

    return 0;
}