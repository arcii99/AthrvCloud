//FormAI DATASET v1.0 Category: File system simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_COUNT 100 // Maximum number of files that can be created
#define MAX_FILE_SIZE 1000 // Maximum size of a file

struct File {
    char* name;
    char* data;
    int size;
};

struct FileSystem {
    struct File files[MAX_FILE_COUNT];
    int total_files;
    int total_size;
};

void create_file(struct FileSystem* fs, char* name, char* data, int size) {
    if (fs->total_files >= MAX_FILE_COUNT) {
        printf("Cannot create file, maximum file limit reached!\n");
        return;
    }
    
    if (fs->total_size + size > MAX_FILE_SIZE) {
        printf("Cannot create file, maximum file size reached!\n");
        return;
    }
    
    struct File new_file = {
        .name = name,
        .data = data,
        .size = size
    };
    
    fs->files[fs->total_files++] = new_file;
    fs->total_size += size;
    printf("File %s created successfully!\n", name);
}

void list_files(struct FileSystem* fs) {
    printf("Total Files: %d\n", fs->total_files);
    
    for (int i = 0; i < fs->total_files; i++) {
        printf("File Name: %s, Size: %d\n", fs->files[i].name, fs->files[i].size);
    }
}

void delete_file(struct FileSystem* fs, char* name) {
    int index = -1;
    for (int i = 0; i < fs->total_files; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("File not found!\n");
        return;
    }
    
    fs->total_size -= fs->files[index].size;
    for (int i = index; i < fs->total_files - 1; i++) {
        fs->files[i] = fs->files[i+1];
    }
    fs->total_files--;
    printf("File %s deleted successfully!\n", name);
}

int main() {
    struct FileSystem fs = {
        .total_files = 0,
        .total_size = 0
    };
    
    create_file(&fs, "file1.txt", "Hello World!", 12);
    create_file(&fs, "file2.txt", "This is a test file.", 21);
    list_files(&fs);
    delete_file(&fs, "file1.txt");
    list_files(&fs);
    
    return 0;
}