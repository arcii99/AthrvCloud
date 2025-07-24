//FormAI DATASET v1.0 Category: File system simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 20
#define MAX_FILE_COUNT 10

struct File {
    char name[MAX_FILENAME_LENGTH];
    int size;
};

struct Directory {
    struct File files[MAX_FILE_COUNT];
    int file_count;
};

struct FileSystem {
    struct Directory root_dir;
};

void initialize_filesystem(struct FileSystem* fs) {
    struct Directory root_dir = {{}, 0};
    fs->root_dir = root_dir;
}

void create_file(struct Directory* dir, char* name, int size) {
    if (dir->file_count < MAX_FILE_COUNT) {
        struct File new_file = {0};
        strncpy(new_file.name, name, MAX_FILENAME_LENGTH);
        new_file.size = size;
        dir->files[dir->file_count++] = new_file;
        printf("File %s created in directory.\n", name);
    } else {
        printf("Error: Maximum file count reached in directory.\n");
    }
}

void delete_file(struct Directory* dir, char* name) {
    int i, index = -1;
    for (i = 0; i < dir->file_count; i++) {
        if (strcmp(dir->files[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (i = index; i < dir->file_count - 1; i++) {
            dir->files[i] = dir->files[i + 1];
        }
        dir->file_count--;
        printf("File %s deleted from directory.\n", name);
    } else {
        printf("Error: File %s not found in directory.\n", name);
    }
}

void list_files(struct Directory* dir) {
    int i;
    for (i = 0; i < dir->file_count; i++) {
        printf("File %d: %s (%d bytes)\n", i + 1, dir->files[i].name, dir->files[i].size);
    }
}

int main() {
    struct FileSystem fs = {0};
    initialize_filesystem(&fs);

    create_file(&fs.root_dir, "file1.txt", 500);
    create_file(&fs.root_dir, "file2.txt", 1000);
    create_file(&fs.root_dir, "file3.txt", 250);

    list_files(&fs.root_dir);

    delete_file(&fs.root_dir, "file2.txt");

    list_files(&fs.root_dir);

    return 0;
}