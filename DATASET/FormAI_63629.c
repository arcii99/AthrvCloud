//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 1000

// Function to extract metadata
void extractMetadata(char *data, char *metadata) {
    int i = 0;
    char temp[MAX_CHARS];

    while (data[i] != '\0') {
        if (data[i] == '<') {
            if (data[i+1] == '!') {
                i++;
                while (data[i] != '>') {
                    i++;
                }
            } else if (data[i+1] == '/') {
                i++;
                while (data[i] != '>') {
                    i++;
                }
            } else {
                i++;
                int j = 0;
                while (data[i] != '>') {
                    temp[j++] = data[i++];
                }
                temp[j] = '\0';
                strcat(metadata, temp);
            }
        }
        i++;
    }
}

// Pad a string with a given character
void padString(char *str, int size, char pad_char) {
    int str_len = strlen(str);
    if (str_len > size) {
        str[size] = '\0';
    } else {
        int pad_len = size - str_len;
        int i;
        for (i = 0; i < pad_len; i++) {
            str[str_len + i] = pad_char;
        }
        str[str_len + i] = '\0';
    }
}

int main() {
    char data[MAX_CHARS] = "<html><head><title>Test Page</title><meta name=\"author\" content=\"John Doe\"><meta name=\"description\" content=\"This is a test page.\"></head><body><h1>Welcome to my page</h1><p>This is a test page.</p></body></html>";
    char metadata[MAX_CHARS] = "";

    // Extract metadata
    extractMetadata(data, metadata);

    // Print metadata
    printf("Metadata:\n");
    printf("----------------------------\n");

    char metadata_line[MAX_CHARS];
    char *token = strtok(metadata, " ");
    while (token != NULL) {
        memset(metadata_line, 0, MAX_CHARS);
        int len = strlen(token);
        padString(token, 20, ' ');
        sprintf(metadata_line, "%s| %d\n", token, len);
        printf("%s", metadata_line);
        
        token = strtok(NULL, " ");
    }

    return 0;
}