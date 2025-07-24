//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_METADATA_SIZE 1024

typedef struct {
    char *key;
    char *value;
} MetaData;

MetaData *extract_metadata(char *input_string, char *delimiter) {
    char *line;
    char *key, *value;
    static MetaData metadata[MAX_METADATA_SIZE];
    int num_metadata = 0;

    line = strtok(input_string, "\n");

    while(line != NULL && num_metadata < MAX_METADATA_SIZE) {
        key = strtok(line, delimiter);
        value = strtok(NULL, delimiter);

        if(key != NULL && value != NULL) {
            metadata[num_metadata].key = strdup(key);
            metadata[num_metadata].value = strdup(value);
            num_metadata++;
        }

        line = strtok(NULL, "\n");
    }

    return metadata;
}

int main() {
    char input_string[] = "name: John Doe\nage: 32\nlocation: New York\noccupation: Programmer\n";

    MetaData *metadata = extract_metadata(input_string, ": ");

    int i;
    for(i = 0; i < MAX_METADATA_SIZE && metadata[i].key != NULL && metadata[i].value != NULL; i++) {
        printf("%s: %s\n", metadata[i].key, metadata[i].value);
    }

    return 0;
}