//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1000

typedef struct Metadata {
    char author[MAX_STR_LEN];
    char title[MAX_STR_LEN];
    char date[MAX_STR_LEN];
    char description[MAX_STR_LEN];
} Metadata;

void extract_metadata(char* file_path, Metadata *meta_data);

int main() {
    Metadata meta_data;
    extract_metadata("example.txt", &meta_data);

    printf("Author: %s\n", meta_data.author);
    printf("Title: %s\n", meta_data.title);
    printf("Date: %s\n", meta_data.date);
    printf("Description: %s\n", meta_data.description);

    return 0;
}

void extract_metadata(char* file_path, Metadata *meta_data) {
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    } 

    char line[MAX_STR_LEN];

    while (fgets(line, MAX_STR_LEN, file) != NULL) {
        if (strstr(line, "Author: ") != NULL) {
            sscanf(line, "Author: %s", meta_data->author);
        } else if (strstr(line, "Title: ") != NULL) {
            sscanf(line, "Title: %s", meta_data->title);
        } else if (strstr(line, "Date: ") != NULL) {
            sscanf(line, "Date: %s", meta_data->date);
        } else if (strstr(line, "Description: ") != NULL) {
            sscanf(line, "Description: %s", meta_data->description);
        }
    }

    fclose(file);
}