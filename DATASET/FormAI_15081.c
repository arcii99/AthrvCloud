//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Metadata {
    char* key;
    char* value;
};

void extractMetadata(char* fileContents, struct Metadata* metadata, int* metadataCount) {
    char* currentKey = NULL;
    char* currentValue = NULL;

    char* pch = strtok(fileContents, "\n");
    while(pch != NULL) {
        if (strlen(pch) == 0) { // empty line signifies end of metadata
            break;
        }
        if (pch[0] == ' ') { // continuation of previous value
            if (currentKey == NULL) {
                printf("Invalid metadata format: value before key\n");
                return;
            }
            currentValue = realloc(currentValue, strlen(currentValue) + strlen(pch) + 1); // append to current value
            strcat(currentValue, pch);
        }
        else { // new key-value pair
            if (currentKey != NULL) { // save previous key-value pair
                metadata[*metadataCount].key = currentKey;
                metadata[*metadataCount].value = currentValue;
                (*metadataCount)++;
                currentKey = NULL;
                currentValue = NULL;
            }
            if (strchr(pch, ':') == NULL) { // invalid metadata format
                printf("Invalid metadata format: no colon delimiter\n");
                return;
            }
            currentKey = malloc(strlen(pch) + 1);
            strncpy(currentKey, pch, strchr(pch, ':') - pch); // extract key
            currentKey[strlen(currentKey)] = '\0';
            currentValue = malloc(strlen(pch) + 1);
            strcpy(currentValue, strchr(pch, ':') + 2); // extract value (skip colon and space)
        }
        pch = strtok(NULL, "\n");
    }

    if (currentKey != NULL) { // save last key-value pair
        metadata[*metadataCount].key = currentKey;
        metadata[*metadataCount].value = currentValue;
        (*metadataCount)++;
    }
}

int main() {
    char fileContents[] =
        "Title: The Great Gatsby\n"
        "Author: F. Scott Fitzgerald\n"
        "Publisher: Scribner\n"
        "\n"
        "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nunc ligula odio, vestibulum nec felis feugiat, malesuada molestie justo. Duis volutpat efficitur lectus ut accumsan. Etiam suscipit massa quis risus elementum consequat. Sed hendrerit, sem ac dapibus sagittis, nisi turpis accumsan lorem, ut vehicula ante justo quis urna. Praesent imperdiet libero eget tempor tincidunt.\n";

    struct Metadata metadata[10];
    int metadataCount = 0;

    extractMetadata(fileContents, metadata, &metadataCount);

    for (int i = 0; i < metadataCount; i++) {
        printf("%s: %s\n", metadata[i].key, metadata[i].value);
    }

    return 0;
}