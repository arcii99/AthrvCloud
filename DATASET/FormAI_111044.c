//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 256

typedef struct metadata_{
    char *key;
    char *value;
}metadata_t;

int main(){
    char input[MAX_STR_LEN];
    metadata_t *metadata_list[MAX_STR_LEN];
    int metadata_count = 0;

    printf("Enter metadata in 'key=value' format (maximum %d):\n", MAX_STR_LEN);

    // Read user input
    fgets(input, MAX_STR_LEN, stdin);

    // Parse metadata
    char *token = strtok(input, " ");
    while(token != NULL){
        // Split key and value using '=' delimiter
        char *key = strtok(token, "=");
        char *value = strtok(NULL, "=");
        if(key != NULL && value != NULL){
            // Allocate memory for metadata struct and its contents
            metadata_t *metadata = (metadata_t*) malloc(sizeof(metadata_t));
            metadata->key = (char*) malloc(strlen(key) + 1);
            metadata->value = (char*) malloc(strlen(value) + 1);

            // Copy key and value into metadata struct
            strcpy(metadata->key, key);
            strcpy(metadata->value, value);

            // Add metadata to list
            metadata_list[metadata_count++] = metadata;
        }
        // Get next token
        token = strtok(NULL, " ");
    }

    // Print metadata
    printf("Metadata found:\n");
    for(int i = 0; i < metadata_count; i++){
        printf("%s=%s\n", metadata_list[i]->key, metadata_list[i]->value);
    }

    // Free allocated memory
    for(int i = 0; i < metadata_count; i++){
        free(metadata_list[i]->key);
        free(metadata_list[i]->value);
        free(metadata_list[i]);
    }

    return 0;
}