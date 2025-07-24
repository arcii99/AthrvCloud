//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_METADATA_SIZE 1000
#define MAX_TOKEN_SIZE 50

// Struct to hold metadata token and its length
typedef struct {
    char token[MAX_TOKEN_SIZE];
    int length;
} metadata_token;

// Function to extract metadata tokens from a given string
void extract_metadata(char metadata[], metadata_token metadata_tokens[], int *num_tokens) {
    char *token;
    const char delimiters[] = ",;: ";
    token = strtok(metadata, delimiters);
    while (token != NULL) {
        metadata_tokens[*num_tokens].length = strlen(token);
        strcpy(metadata_tokens[*num_tokens].token, token);
        (*num_tokens)++;
        token = strtok(NULL, delimiters);
    }
}

int main() {
    char metadata[MAX_METADATA_SIZE];
    metadata_token metadata_tokens[MAX_METADATA_SIZE / 2];
    int num_tokens = 0;
    printf("Enter metadata string: ");
    fgets(metadata, MAX_METADATA_SIZE, stdin);
    if (metadata[strlen(metadata) - 1] == '\n') {
        metadata[strlen(metadata) - 1] = 0;
    }
    extract_metadata(metadata, metadata_tokens, &num_tokens);
    printf("Metadata tokens extracted:\n");
    for (int i = 0; i < num_tokens; i++) {
        printf("%s (Length: %d)\n", metadata_tokens[i].token, metadata_tokens[i].length);
    }
    return 0;
}