//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_METADATA_SIZE 1000
#define MAX_FILE_NAME_SIZE 256

typedef struct {
    char author[50];
    char created[20];
    char modified[20];
    char file_name[MAX_FILE_NAME_SIZE];
} metadata;

int extract_metadata(char *file_path, metadata *data) {
    FILE *file;
    char metadata_str[MAX_METADATA_SIZE];
    char *token;
    const char delims[] = " ";
    int i = 0;

    file = fopen(file_path, "r");
    if (file == NULL)
        return -1;

    // Read metadata into string
    fgets(metadata_str, MAX_METADATA_SIZE, file);

    // Close the file
    fclose(file);

    // Clear out the structure
    memset(data, 0, sizeof(metadata));

    // Tokenize the metadata string
    token = strtok(metadata_str, delims);
    while (token != NULL) {
        switch (i) {
            case 0:
                strcpy(data->author, token);
                break;
            case 1:
                strcpy(data->created, token);
                break;
            case 2:
                strcpy(data->modified, token);
                break;
            default:
                if (i == 3 && strlen(token) > MAX_FILE_NAME_SIZE - 1)
                    return -1;
                strcpy(data->file_name, token);
                break;
        }
        token = strtok(NULL, delims);
        i++;
    }

    return 0;
}

int main() {
    char file_path[] = "example.txt";
    metadata data;

    if (extract_metadata(file_path, &data) == -1) {
        printf("Error: could not extract metadata\n");
        return -1;
    }

    printf("File name: %s\n", data.file_name);
    printf("Author: %s\n", data.author);
    printf("Created: %s\n", data.created);
    printf("Modified: %s\n", data.modified);

    return 0;
}