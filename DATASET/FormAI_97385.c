//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: interoperable
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE  1024

/* Determine metadata type based on prefix of metadata string */
enum metadata_type {
    AUTHOR,
    TITLE,
    DATE,
    SOURCE,
    DESCRIPTION
};

/* Extract metadata from input string */
void extract_metadata(char *input_string, char *output[], int *num_metadata) {
    char *prefix;
    char *suffix;
    char buffer[BUFFER_SIZE];
    int i = 0;

    /* Loop through input string and extract metadata */
    while (*input_string != '\0') {
        /* Determine type of metadata by checking prefix */
        if (strncmp(input_string, "Author:", 7) == 0) {
            prefix = "Author:";
            input_string += 7;
        } else if (strncmp(input_string, "Title:", 6) == 0) {
            prefix = "Title:";
            input_string += 6;
        } else if (strncmp(input_string, "Date:", 5) == 0) {
            prefix = "Date:";
            input_string += 5;
        } else if (strncmp(input_string, "Source:", 7) == 0) {
            prefix = "Source:";
            input_string += 7;
        } else if (strncmp(input_string, "Description:", 12) == 0) {
            prefix = "Description:";
            input_string += 12;
        } else {
            input_string++;
            continue;
        }

        /* Extract suffix of metadata */
        suffix = strchr(input_string, '\n');
        if (suffix == NULL) {
            break;
        }
        *suffix = '\0';

        /* Copy metadata to output buffer */
        sprintf(buffer, "%s %s", prefix, input_string);
        output[i] = strdup(buffer);
        i++;

        /* Move input_string pointer to next metadata field */
        input_string = suffix + 1;
    }

    *num_metadata = i;
}

/* Print metadata to console */
void print_metadata(char *metadata[], int num_metadata) {
    int i;

    printf("Metadata Found:\n");
    for (i = 0; i < num_metadata; i++) {
        printf("%s\n", metadata[i]);
    }
}

int main() {
    char input_string[] = "Author: Jane Doe\n"
        "Title: The Importance of Metadata\n"
        "Date: 2021-05-25\n"
        "Source: https://example.com/metadata\n"
        "Description: This article explains the importance of metadata.\n"
        "Content:\n"
        "This is the content of the article.\n"
        "It is important to include metadata in all documents.";

    char *metadata[BUFFER_SIZE];
    int num_metadata;

    extract_metadata(input_string, metadata, &num_metadata);
    print_metadata(metadata, num_metadata);

    return 0;
}