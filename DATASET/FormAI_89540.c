//FormAI DATASET v1.0 Category: File system simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024
#define MAX_FILENAME_SIZE 16
#define MAX_FILE_COUNT 10

typedef struct {
    char filename[MAX_FILENAME_SIZE];
    int size;
    char data[MAX_FILE_SIZE];
} file_t;

typedef struct {
    file_t files[MAX_FILE_COUNT];
    int file_count;
} file_system_t;

int add_file(file_system_t *fs, char *filename, char *data, int size) {
    if (fs->file_count >= MAX_FILE_COUNT) {
        return -1;
    }

    file_t new_file;
    strncpy(new_file.filename, filename, MAX_FILENAME_SIZE);
    strncpy(new_file.data, data, size);
    new_file.size = size;

    fs->files[fs->file_count++] = new_file;

    return 0;
}

int read_file(file_system_t *fs, char *filename, char *buf, int *size) {
    for (int i = 0; i < fs->file_count; i++) {
        if (strcmp(fs->files[i].filename, filename) == 0) {
            *size = fs->files[i].size;
            strncpy(buf, fs->files[i].data, *size);

            return 0;
        }
    }

    return -1;
}

int main() {
    file_system_t fs = {0};
    char buf[MAX_FILE_SIZE] = {0};
    int size = 0;

    add_file(&fs, "file1", "this is file 1", strlen("this is file 1"));
    add_file(&fs, "file2", "this is file 2", strlen("this is file 2"));

    if (read_file(&fs, "file1", buf, &size) == 0) {
        printf("File contents of file1: %s\n", buf);
    }

    if (read_file(&fs, "file2", buf, &size) == 0) {
        printf("File contents of file2: %s\n", buf);
    }

    return 0;
}