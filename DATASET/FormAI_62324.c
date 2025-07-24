//FormAI DATASET v1.0 Category: File Backup System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LEN 50
#define MAX_FILE_CONTENT_LEN 100

typedef struct file {
    char name[MAX_FILE_NAME_LEN];
    char content[MAX_FILE_CONTENT_LEN];
} File;

void writeToFile(FILE *file, File *data);
void readFromFile(FILE *file, File *data);

int main() {
    File myFile;
    strcpy(myFile.name, "example.txt");
    strcpy(myFile.content, "This is an example file.");

    FILE *fp;
    fp = fopen(myFile.name, "w");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    writeToFile(fp, &myFile);

    fclose(fp);

    fp = fopen(myFile.name, "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    File newFile;
    readFromFile(fp, &newFile);

    printf("Name: %s\nContent: %s\n", newFile.name, newFile.content);

    fclose(fp);

    return 0;
}

void writeToFile(FILE *file, File *data) {
    fwrite(data->name, sizeof(data->name), 1, file);
    fwrite(data->content, sizeof(data->content), 1, file);
}

void readFromFile(FILE *file, File *data) {
    fread(data->name, sizeof(data->name), 1, file);
    fread(data->content, sizeof(data->content), 1, file);
}