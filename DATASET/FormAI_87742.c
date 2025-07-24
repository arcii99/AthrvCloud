//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void extractMetaData(char* input_string, char* output_string) {
    int start_index = -1;
    int end_index = -1;
    int length = strlen(input_string);

    // Loop through the input_string to find the start and end index of metadata
    for (int i = 0; i < length; i++) {
        if (input_string[i] == '<') {
            start_index = i;
        }
        else if (input_string[i] == '>') {
            end_index = i;
            break;  // Once the end index is found, break out of the loop
        }
    }

    // Return an error message if metadata is not found
    if (start_index == -1 || end_index == -1) {
        printf("Error: No metadata found in input string.\n");
        return;
    }

    // Copy the metadata from input_string to output_string
    strncpy(output_string, &input_string[start_index+1], end_index-start_index-1);
    output_string[end_index-start_index-1] = '\0';
}

int main() {
    char input_string[100] = "<title>This is a title</title>";
    char output_string[50];

    extractMetaData(input_string, output_string);

    printf("Input string: %s\n", input_string);
    printf("Output string: %s\n", output_string);

    return 0;
}