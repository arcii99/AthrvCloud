//FormAI DATASET v1.0 Category: File system simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FILE_SIZE 1024
#define MAX_FILENAME_LENGTH 20
#define MAX_DIRECTORY_SIZE 100
#define MAX_FILE_COUNT 10

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    int size;
    time_t last_modified;
} File;

typedef struct {
    char dirname[MAX_FILENAME_LENGTH];
    int file_count;
    File files[MAX_FILE_COUNT];
} Directory;

Directory directories[MAX_DIRECTORY_SIZE];
int directory_count = 0;

int createFile(char filename[], int size) {
    int index = -1;
    for (int i = 0; i < directory_count; i++) {
        for (int j = 0; j < directories[i].file_count; j++) {
            if (strcmp(directories[i].files[j].filename, filename) == 0) {
                printf("Error: File already exists\n");
                return 0;
            }
        }
    }
    srand(time(NULL));
    int directory_index = rand() % directory_count;
    if (directories[directory_index].file_count >= MAX_FILE_COUNT) {
        printf("Error: Directory is full\n");
        return 0;
    }
    strcpy(directories[directory_index].files[directories[directory_index].file_count].filename, filename);
    directories[directory_index].files[directories[directory_index].file_count].size = size;
    directories[directory_index].files[directories[directory_index].file_count].last_modified = time(NULL);
    printf("File created successfully in directory %s\n", directories[directory_index].dirname);
    directories[directory_index].file_count++;
    return 1;
}

int main() {
    strcpy(directories[directory_count].dirname, "Documents");
    directory_count++;
    createFile("Homework.docx", 20);
    createFile("Resume.docx", 50);
    return 0;
}