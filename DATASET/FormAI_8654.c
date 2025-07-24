//FormAI DATASET v1.0 Category: File system simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LEN 20
#define MAX_FILE_SIZE 100
#define MAX_NUM_FILES 10

typedef struct {
    char name[MAX_FILE_NAME_LEN];
    int size;
    char data[MAX_FILE_SIZE];
} File;

typedef struct {
    File files[MAX_NUM_FILES];
    int num_files;
    int total_size;
} FileSystem;

void init_file_system(FileSystem *fs) {
    fs->num_files = 0;
    fs->total_size = 0;
}

int add_file(FileSystem *fs, const char *name, const char *data, int size) {
    if (fs->num_files >= MAX_NUM_FILES) {
        return 0;
    }
    File *file = &fs->files[fs->num_files];
    strncpy(file->name, name, MAX_FILE_NAME_LEN);
    file->name[MAX_FILE_NAME_LEN - 1] = '\0';  // Ensure null byte termination
    strncpy(file->data, data, MAX_FILE_SIZE);
    file->data[MAX_FILE_SIZE - 1] = '\0';  // Ensure null byte termination
    file->size = size;
    fs->num_files++;
    fs->total_size += size;
    return 1;
}

void list_files(FileSystem fs) {
    if (fs.num_files == 0) {
        printf("No files found.\n");
    } else {
        for (int i = 0; i < fs.num_files; i++) {
            File file = fs.files[i];
            printf("%s (%d bytes)\n", file.name, file.size);
        }
    }
}

int main() {
    FileSystem fs;
    init_file_system(&fs);
    
    add_file(&fs, "file1.txt", "Hello", 5);
    add_file(&fs, "file2.txt", "world!", 6);
    
    list_files(fs);
    
    return 0;
}