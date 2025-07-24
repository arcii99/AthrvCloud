//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: modular
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_METADATA_LENGTH 1000

bool is_valid_character(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}

int metadata_index(char* metadata, int start) {
    int i;
    for (i = start; i < strlen(metadata); i++) {
        if (!is_valid_character(metadata[i])) {
            return i;
        }
    }
    return i;
}

void extract_metadata(char* metadata) {
    int start_index = 0;
    int end_index;

    while (start_index < strlen(metadata)) {
        while (start_index < strlen(metadata) && !is_valid_character(metadata[start_index])) {
            start_index++;
        }

        if (start_index >= strlen(metadata)) {
            break;
        }

        end_index = metadata_index(metadata, start_index);
        printf("Metadata: ");
        for (int i = start_index; i < end_index; i++) {
            printf("%c", metadata[i]);
        }
        printf("\n");

        start_index = end_index;
    }
}

int main() {
    char metadata[MAX_METADATA_LENGTH];
    printf("Enter metadata: ");
    fgets(metadata, MAX_METADATA_LENGTH, stdin);
    extract_metadata(metadata);
    return 0;
}