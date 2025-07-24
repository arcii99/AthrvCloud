//FormAI DATASET v1.0 Category: File system simulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024
#define MAX_FILE_COUNT 10
#define MAX_FILE_NAME_SIZE 20

typedef struct {
    char name[MAX_FILE_NAME_SIZE];
    char contents[MAX_FILE_SIZE];
    int size;
} file_t;

typedef struct {
    file_t files[MAX_FILE_COUNT];
    int count;
} file_system_t;

void initialize(file_system_t *fs) {
    fs->count = 0;
}

void add_file(file_system_t *fs, char *name, char *contents, int size) {
    if (fs->count >= MAX_FILE_COUNT) {
        printf("Error: Maximum file count reached\n");
        return;
    }
    file_t file;
    strncpy(file.name, name, MAX_FILE_NAME_SIZE - 1);
    strncpy(file.contents, contents, MAX_FILE_SIZE - 1);
    file.size = size;
    fs->files[fs->count++] = file;
}

void delete_file(file_system_t *fs, char *name) {
    int index = -1;
    for (int i = 0; i < fs->count; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Error: File not found\n");
        return;
    }
    for (int i = index; i < fs->count - 1; i++) {
        fs->files[i] = fs->files[i + 1];
    }
    fs->count--;
}

void list_files(file_system_t *fs) {
    if (fs->count == 0) {
        printf("No files\n");
        return;
    }
    for (int i = 0; i < fs->count; i++) {
        printf("%s (%d bytes)\n", fs->files[i].name, fs->files[i].size);
    }
}

int main(int argc, char *argv[]) {
    file_system_t fs;
    initialize(&fs);
    add_file(&fs, "file1.txt", "contents of file1", 17);
    add_file(&fs, "file2.txt", "contents of file2", 17);
    list_files(&fs);
    delete_file(&fs, "file1.txt");
    list_files(&fs);
    return 0;
}