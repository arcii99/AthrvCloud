//FormAI DATASET v1.0 Category: File system simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 20
#define MAX_FILE_COUNT 10

typedef struct {
    char name[MAX_FILENAME_LEN];
    int size;
} File;

typedef struct {
    char name[MAX_FILENAME_LEN];
    File files[MAX_FILE_COUNT];
    int file_count;
    int used_space;
} Directory;

Directory root;

void initialize() {
    strcpy(root.name, "/");
    root.file_count = 0;
    root.used_space = 0;
}

void create_file(Directory *dir, char *name, int size) {
    if (dir->file_count >= MAX_FILE_COUNT) {
        printf("Error: Maximum file count reached\n");
        return;
    }

    if (dir->used_space + size > MAX_FILE_COUNT) {
        printf("Error: Insufficient space\n");
        return;
    }

    File new_file;
    strcpy(new_file.name, name);
    new_file.size = size;

    dir->files[dir->file_count] = new_file;
    dir->file_count++;
    dir->used_space += size;

    printf("File created successfully!\n");
}

void list_files(Directory *dir) {
    printf("Files in %s:\n", dir->name);

    for (int i = 0; i < dir->file_count; i++) {
        printf("- %s (%d bytes)\n", dir->files[i].name, dir->files[i].size);
    }
}

int main() {
    initialize();

    create_file(&root, "file1.txt", 100);
    create_file(&root, "file2.txt", 200);
    create_file(&root, "file3.txt", 300);

    list_files(&root);

    return 0;
}