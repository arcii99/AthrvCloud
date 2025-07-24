//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

#define MAX_FILE_SIZE 100000

void getMetadata(char *path) {
    FILE *fp;
    char fileContent[MAX_FILE_SIZE];
    char buffer[100];
    char *line;
    int i = 0;

    fp = fopen(path, "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fread(fileContent, MAX_FILE_SIZE, 1, fp);

    for(i = 0; i < strlen(fileContent); i++) {
        if (fileContent[i] == '/' && fileContent[i+1] == '/') {
            line = strtok(&fileContent[i], "\n");

            if (strstr(line, "Author:") != NULL) {
                strcpy(buffer, line);
                printf("%s\n", buffer);
            } else if (strstr(line, "Description:") != NULL) {
                strcpy(buffer, line);
                printf("%s\n", buffer);
            } else if (strstr(line, "Created:") != NULL) {
                strcpy(buffer, line);
                printf("%s\n", buffer);
            } else if (strstr(line, "Modified:") != NULL) {
                strcpy(buffer, line);
                printf("%s\n", buffer);
            }
        } 
    }

    fclose(fp);
}

int main() {
    char *path = "example.c";
    printf("Retrieving metadata from %s...\n\n", path);
    getMetadata(path);
    return 0;
}