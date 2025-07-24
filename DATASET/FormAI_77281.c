//FormAI DATASET v1.0 Category: File system simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 20
#define MAX_FILE_SIZE 50
#define MAX_NUM_FILES 10

struct file {
    char filename[MAX_FILENAME_LENGTH];
    char data[MAX_FILE_SIZE];
    int size;
    int is_deleted;
};

struct file_system {
    struct file files[MAX_NUM_FILES];
    int num_files;
};

void init_file(struct file* f, char* filename, char* data, int size) {
    strcpy(f->filename, filename);
    f->size = size;
    strcpy(f->data, data);
    f->is_deleted = 0;
}

void init_file_system(struct file_system* fs) {
    fs->num_files = 0;
}

void add_file(struct file_system* fs, char* filename, char* data, int size) {
    if (fs->num_files == MAX_NUM_FILES) {
        printf("Error: file system is full\n");
        return;
    }
    struct file* new_file = &fs->files[fs->num_files++];
    init_file(new_file, filename, data, size);
}

void delete_file(struct file_system* fs, char* filename) {
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].filename, filename) == 0) {
            fs->files[i].is_deleted = 1;
            printf("File %s deleted\n", filename);
            return;
        }
    }
    printf("Error: file not found\n");
}

void print_file(struct file_system* fs, char* filename) {
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].filename, filename) == 0) {
            if (fs->files[i].is_deleted) {
                printf("Error: file has been deleted\n");
            } else {
                printf("%s: %s\n", filename, fs->files[i].data);
            }
            return;
        }
    }
    printf("Error: file not found\n");
}

int main() {
    struct file_system fs;
    init_file_system(&fs);

    add_file(&fs, "file1", "hello", 5);
    add_file(&fs, "file2", "world", 5);
    delete_file(&fs, "file1");
    add_file(&fs, "file3", "1234567890", 10);

    print_file(&fs, "file1");
    print_file(&fs, "file2");
    print_file(&fs, "file3");

    return 0;
}