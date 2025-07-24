//FormAI DATASET v1.0 Category: File system simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000
#define MAX_FILENAME_LENGTH 50
#define MAX_FILES 100

struct file {
    char name[MAX_FILENAME_LENGTH];
    int size;
    char content[MAX_FILE_SIZE];
};

struct file_system {
    struct file files[MAX_FILES];
    int num_files;
    int total_size;
};

void add_file(struct file_system* fs, char* name, char* content, int size) {
    if (fs->num_files >= MAX_FILES) {
        printf("Maximum number of files reached\n");
        return;
    }
    struct file new_file;
    strcpy(new_file.name, name);
    new_file.size = size;
    strcpy(new_file.content, content);
    fs->files[fs->num_files++] = new_file;
    fs->total_size += size;
}

void delete_file(struct file_system* fs, char* name) {
    int i;
    for (i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            fs->total_size -= fs->files[i].size;
            for (; i < fs->num_files-1; i++) {
                fs->files[i] = fs->files[i+1];
            }
            fs->num_files--;
            return;
        }
    }
    printf("File not found\n");
}

void print_file_system(struct file_system* fs) {
    printf("File system contains %d files with total size %d\n", fs->num_files, fs->total_size);
    for (int i = 0; i < fs->num_files; i++) {
        printf("File %d - Name: %s, Size: %d, Content: %s\n", i+1, fs->files[i].name, fs->files[i].size, fs->files[i].content);
    }
}

int main() {
    struct file_system fs = {.num_files = 0, .total_size = 0};
    add_file(&fs, "file1.txt", "Hello, world!", 13);
    add_file(&fs, "file2.txt", "This is a file", 15);
    print_file_system(&fs);
    delete_file(&fs, "file1.txt");
    print_file_system(&fs);
    return 0;
}