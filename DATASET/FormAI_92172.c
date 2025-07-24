//FormAI DATASET v1.0 Category: File system simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FILES 10
#define MAX_FILE_SIZE 1024

typedef struct file {
    char* name;
    int size;
    char* content;
} File;

typedef struct CFilesystem {
    File files[MAX_FILES];
    int num_files;
    int total_size;
} CFilesystem;

bool contains_file(CFilesystem* fs, char* name) {
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            return true;
        }
    }
    return false;
}

void add_file(CFilesystem* fs, char* name, char* content) {
    if (contains_file(fs, name)) {
        printf("Error: File %s already exists\n", name);
        return;
    }
    if (fs->num_files == MAX_FILES) {
        printf("Error: Filesystem is full\n");
        return;
    }
    File new_file;
    new_file.name = strdup(name);
    new_file.size = strlen(content);
    new_file.content = malloc(new_file.size + 1);
    strcpy(new_file.content, content);
    fs->files[fs->num_files] = new_file;
    fs->num_files++;
    fs->total_size += new_file.size;
}

void delete_file(CFilesystem* fs, char* name) {
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            fs->total_size -= fs->files[i].size;
            free(fs->files[i].name);
            free(fs->files[i].content);
            for (int j = i; j < fs->num_files - 1; j++) {
                fs->files[j] = fs->files[j + 1];
            }
            fs->num_files--;
            printf("File %s deleted\n", name);
            return;
        }
    }
    printf("Error: File %s does not exist\n", name);
}

void list_files(CFilesystem* fs) {
    printf("Total files: %d\n", fs->num_files);
    printf("Total size: %d bytes\n", fs->total_size);
    for (int i = 0; i < fs->num_files; i++) {
        printf("%s: %d bytes\n", fs->files[i].name, fs->files[i].size);
    }
}

void read_file(CFilesystem* fs, char* name) {
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            printf("%s\n", fs->files[i].content);
            return;
        }
    }
    printf("Error: File %s does not exist\n", name);
}

int main() {
    CFilesystem fs;
    fs.num_files = 0;
    fs.total_size = 0;

    add_file(&fs, "hello.txt", "Hello, world!");
    add_file(&fs, "foo.txt", "This is a test file.");
    list_files(&fs);

    read_file(&fs, "hello.txt");
    read_file(&fs, "bar.txt");

    delete_file(&fs, "foo.txt");
    list_files(&fs);

    return 0;
}