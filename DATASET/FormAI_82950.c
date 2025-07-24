//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    char *value;
} Metadata;

Metadata *extractMetadata(char *source) {
    char *startToken = "<meta name=\"";
    char *endToken = "\">";
    int bufferLength = strlen(source);
    int tokensFound = 0;
    char **buffer = (char **) malloc(sizeof(char *) * bufferLength);
    Metadata *metadata = (Metadata *) malloc(sizeof(Metadata) * bufferLength);
    memset(metadata, 0, sizeof(Metadata) * bufferLength);

    // Find all meta tags in the source
    char *found = source;
    while ((found = strstr(found, startToken)) != NULL) {
        tokensFound++;

        // Move to the content
        found += strlen(startToken);

        // Find the closing tag
        char *endFound = strstr(found, endToken);

        // Identify the content of the tag
        int length = endFound - found;
        char *content = (char *) malloc(sizeof(char) * length);
        memcpy(content, found, length);
        content[length] = '\0';

        // Extract the key and value from the content
        char *key = strtok(content, "=");
        char *value = strtok(NULL, "=");

        // Remove any quotes from the value
        value[strlen(value) - 1] = '\0';
        value++;
        key[strlen(key) - 1] = '\0';

        // Add the metadata to the list
        metadata[tokensFound - 1].key = key;
        metadata[tokensFound - 1].value = value;

        // Keep track of the buffer
        buffer[tokensFound - 1] = content;

        // Move to the next block
        found = endFound;
    }

    // Free the buffer
    int i = 0;
    for (i = 0; i < tokensFound; i++) {
        free(buffer[i]);
    }

    free(buffer);

    return metadata;
}

int main() {
    char *html = "<html>\n<head>\n<meta name=\"author\" content=\"Jane Doe\">\n<meta name=\"description\" content=\"This is an example\">\n</head>\n<body>\n<h1>Hello World</h1>\n<p>This is an example of a Metadata Extractor program written in C.</p>\n</body>\n</html>";
    Metadata *metadata = extractMetadata(html);

    printf("Metadata found: %d\n", sizeof(metadata) / sizeof(Metadata));

    int i;
    for (i = 0; metadata[i].key != NULL; i++) {
        printf("key: %s, value: %s\n", metadata[i].key, metadata[i].value);
    }

    // Free the metadata
    free(metadata);

    return 0;
}