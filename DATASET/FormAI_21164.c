//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_METADATA_LEN 1000

typedef struct {
    char name[50];
    char content[500];
} Metadata;

int extract_metadata(FILE *file, Metadata *metadata_array) {
    char line[MAX_METADATA_LEN];
    int metadata_count = 0;
    
    while (fgets(line, MAX_METADATA_LEN, file) != NULL) {
        if (strncmp(line, "##", 2) == 0) {
            // Found metadata
            char *colon_pos = strchr(line, ':');
            if (colon_pos != NULL) {
                // Extract metadata name and content
                int name_len = colon_pos - line - 2;
                int content_len = strlen(line) - (name_len + 3);
                strncpy(metadata_array[metadata_count].name, line + 2, name_len);
                strncpy(metadata_array[metadata_count].content, colon_pos + 2, content_len);
                metadata_count++;
            }
        }
    }
    
    return metadata_count;
}

int main() {
    FILE *file = fopen("example.md", "r");
    Metadata metadata_array[50];
    
    if (file != NULL) {
        int metadata_count = extract_metadata(file, metadata_array);
        
        printf("Found %d metadata items:\n", metadata_count);
        for (int i = 0; i < metadata_count; i++) {
            printf("%s: %s\n", metadata_array[i].name, metadata_array[i].content);
        }
        
        fclose(file);
    } else {
        printf("Unable to open file\n");
    }
    
    return 0;
}