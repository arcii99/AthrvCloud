//FormAI DATASET v1.0 Category: File system simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_FILE_SIZE 1024
#define MAX_NUM_FILES 100

struct file {
    char name[MAX_FILENAME_LENGTH];
    char data[MAX_FILE_SIZE];
    int size;
    int allocated;
};

struct file_system {
    struct file files[MAX_NUM_FILES];
    int num_files;
    int total_space;
    int free_space;
};

void init_file_system(struct file_system* fs, int total_space) {
    fs->num_files = 0;
    fs->total_space = total_space;
    fs->free_space = total_space;
}

struct file* create_file(struct file_system* fs, char* name) {
    if (fs->num_files >= MAX_NUM_FILES) {
        printf("Error: file system is full\n");
        return NULL;
    }
    if (fs->free_space < MAX_FILE_SIZE) {
        printf("Error: not enough space in file system\n");
        return NULL;
    }
    struct file* new_file = &(fs->files[fs->num_files]);
    strncpy(new_file->name, name, MAX_FILENAME_LENGTH);
    new_file->size = 0;
    new_file->allocated = 0;
    fs->num_files++;
    fs->free_space -= MAX_FILE_SIZE;
    return new_file;
}

int write_to_file(struct file* f, char* data, int length) {
    if (f == NULL) {
        printf("Error: file not found\n");
        return 0;
    }
    if (f->size + length > MAX_FILE_SIZE) {
        printf("Error: not enough space in file\n");
        return 0;
    }
    strncpy(f->data + f->size, data, length);
    f->size += length;
    f->allocated = 1;
    return length;
}

void delete_file(struct file_system* fs, struct file* f) {
    if (f == NULL) {
        printf("Error: file not found\n");
        return;
    }
    if (f->allocated == 0) {
        printf("Error: file not allocated\n");
        return;
    }
    fs->free_space += MAX_FILE_SIZE;
    f->allocated = 0;
}

void print_file(struct file* f) {
    if (f == NULL) {
        printf("Error: file not found\n");
        return;
    }
    if (f->allocated == 0) {
        printf("Error: file not allocated\n");
        return;
    }
    printf("File Name: %s\nFile Size: %d\nFile Data: %s\n", f->name, f->size, f->data);
}

int main() {
    struct file_system fs;
    init_file_system(&fs, MAX_NUM_FILES * MAX_FILE_SIZE);
    
    struct file* f1 = create_file(&fs, "file1.txt");
    write_to_file(f1, "This is the data for file 1", strlen("This is the data for file 1"));
    print_file(f1);
    
    struct file* f2 = create_file(&fs, "file2.txt");
    write_to_file(f2, "This is the data for file 2", strlen("This is the data for file 2"));
    print_file(f2);
    
    delete_file(&fs, f1);
    print_file(f1);
    
    return 0;
}