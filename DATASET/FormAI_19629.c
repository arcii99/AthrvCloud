//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to parse metadata string */
void parseMetadata(char *metadata) {
    char *token;
    char *delim = ",";
    token = strtok(metadata, delim);
    while(token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, delim);
    }
}

/* Main function */
int main() {
    char metadata[1000];
    printf("Enter metadata string: ");
    fgets(metadata, sizeof(metadata), stdin);
    if(strlen(metadata) > 0 && metadata[strlen(metadata)-1] == '\n') {
        metadata[strlen(metadata)-1] = '\0'; // Remove newline character from input
    }
    parseMetadata(metadata);
    return 0;
}