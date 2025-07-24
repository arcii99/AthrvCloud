//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct metadata {
    uint16_t key;
    char *value;
} metadata_t;

int main() {
    uint16_t metadata_count = 0;
    metadata_t *extracted_metadata = NULL;

    // Let's assume we have some metadata source, e.g. a byte array named metadata_source
    uint8_t metadata_source[] = {0xEA, 0x01, 'H', 'e', 'l', 'l', 'o', 0xEA, 0x02, 'W', 'o', 'r', 'l', 'd', 0xEA, 0x03, 'C', 'o', 'd', 'e', 'r', 0x00};

    // Let's determine the number of metadata entries by checking the key field
    for (size_t i = 0; i < sizeof(metadata_source); i++) {
        if (metadata_source[i] == 0xEA) {
            metadata_count++;
        }
    }

    // Allocate memory for the metadata entries
    extracted_metadata = calloc(metadata_count, sizeof(metadata_t));

    if (extracted_metadata == NULL) {
        printf("Failed to allocate memory for metadata\n");
        return 1;
    }

    // Extract the metadata entries
    uint16_t current_index = 0;
    uint16_t current_key = 0;
    char current_value[256];
    memset(current_value, 0, sizeof(current_value));

    for (size_t i = 0; i < sizeof(metadata_source); i++) {
        if (metadata_source[i] == 0xEA) {
            if (current_index != 0) {
                extracted_metadata[current_index - 1].key = current_key;
                extracted_metadata[current_index - 1].value = strdup(current_value);
                current_key = 0;
                memset(current_value, 0, sizeof(current_value));
            }
            current_index++;
        } else if (current_index != 0) {
            if (current_key == 0) {
                current_key = metadata_source[i] << 8;
            } else {
                current_key |= metadata_source[i];
            }
        } else {
            // Ignore any data before the first metadata entry
        }
    }

    // Print the extracted metadata
    for (size_t i = 0; i < metadata_count; i++) {
        printf("Metadata entry %zu has key: %d and value: %s\n", i+1, extracted_metadata[i].key, extracted_metadata[i].value);
    }

    // Free the allocated memory
    for (size_t i = 0; i < metadata_count; i++) {
        free(extracted_metadata[i].value);
    }
    free(extracted_metadata);

    return 0;
}