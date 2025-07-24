//FormAI DATASET v1.0 Category: File system simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100 // maximum number of files the file system can contain
#define BLOCK_SIZE 512 // size of each block in bytes
#define MAX_BLOCKS 400 // maximum number of blocks in the file system
#define MAX_NAME_LENGTH 20 // maximum length of file name

typedef struct {
    char filename[MAX_NAME_LENGTH]; // file name
    int size; // file size
    int blocks[10]; // array of used blocks
} File;

typedef struct {
    File files[MAX_FILES];
    int num_files;
    char blocks[MAX_BLOCKS][BLOCK_SIZE];
    int num_blocks;
} FileSystem;

FileSystem fs;

void init_file_system() {
    fs.num_files = 0;
    fs.num_blocks = 0;
}

void create_file(char* filename, int size) {
    if (fs.num_files >= MAX_FILES) {
        printf("No more space in file system\n");
        return;
    }
    if (fs.num_blocks + (size / BLOCK_SIZE) > MAX_BLOCKS) {
        printf("No more space in file system\n");
        return;
    }
    for (int i = 0; i < fs.num_files; i++) {
        if (strcmp(fs.files[i].filename, filename) == 0) {
            printf("File already exists: %s\n", filename);
            return;
        }
    }
    File file;
    strcpy(file.filename, filename);
    file.size = size;
    int num_blocks_needed = size / BLOCK_SIZE;
    if (size % BLOCK_SIZE != 0) {
        num_blocks_needed++;
    }
    int blocks_allocated = 0;
    for (int i = 0; i < MAX_BLOCKS; i++) {
        if (blocks_allocated == num_blocks_needed) {
            break;
        }
        if (fs.blocks[i][0] == '\0') {
            file.blocks[blocks_allocated] = i;
            blocks_allocated++;
            fs.num_blocks++;
        }
    }
    fs.files[fs.num_files] = file;
    fs.num_files++;
    printf("File created: %s\n", filename);
}

void delete_file(char* filename) {
    for (int i = 0; i < fs.num_files; i++) {
        if (strcmp(fs.files[i].filename, filename) == 0) {
            for (int j = 0; j < 10; j++) {
                if (fs.files[i].blocks[j] != -1) {
                    fs.blocks[fs.files[i].blocks[j]][0] = '\0';
                    fs.num_blocks--;
                }
            }
            for (int k = i; k < fs.num_files - 1; k++) {
                fs.files[k] = fs.files[k + 1];
            }
            fs.num_files--;
            printf("File deleted: %s\n", filename);
            return;
        }
    }
    printf("File not found: %s\n", filename);
}

void list_files() {
    printf("File system:\n");
    for (int i = 0; i < fs.num_files; i++) {
        printf("%s (%d bytes, %d blocks)\n", fs.files[i].filename, fs.files[i].size, fs.files[i].size / BLOCK_SIZE);
    }
}

int main() {
    init_file_system();
    create_file("file1.txt", 1024);
    create_file("file2.txt", 2048);
    create_file("file3.txt", 3072);
    create_file("file4.txt", 4096);
    list_files();
    delete_file("file2.txt");
    list_files();
    create_file("file5.txt", 512);
    list_files();
    delete_file("file4.txt");
    delete_file("file4.txt");
    list_files();
    return 0;
}