//FormAI DATASET v1.0 Category: File system simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILENAME 20
#define BLOCK_SIZE 1024
#define MAX_BLOCKS 1000

typedef struct {
    char filename[MAX_FILENAME];
    int start_block;
    int size;
} file;

typedef struct {
    int used_blocks[MAX_BLOCKS];
    file files[MAX_FILES];
    int num_files;
} filesystem;

void initialize_filesystem(filesystem* fs) {
    memset(fs->used_blocks, 0, MAX_BLOCKS * sizeof(int));
    fs->num_files = 0;
}

int allocate_block(filesystem* fs) {
    int i;
    for (i = 0; i < MAX_BLOCKS; i++) {
        if (!fs->used_blocks[i]) {
            fs->used_blocks[i] = 1;
            return i;
        }
    }
    return -1;  // No free blocks
}

void add_file(filesystem* fs, char* filename, int size) {
    if (fs->num_files >= MAX_FILES) {
        printf("ERROR: Filesystem is full!\n");
        return;
    }
    
    int start_block = allocate_block(fs);
    if (start_block == -1) {
        printf("ERROR: Filesystem is out of space!\n");
        return;
    }
    
    file new_file;
    strcpy(new_file.filename, filename);
    new_file.start_block = start_block;
    new_file.size = size;
    fs->files[fs->num_files++] = new_file;
}

void delete_file(filesystem* fs, char* filename) {
    int i;
    for (i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].filename, filename) == 0) {
            int block_num = fs->files[i].start_block;
            int num_blocks = (fs->files[i].size + BLOCK_SIZE - 1) / BLOCK_SIZE;
            int j;
            for (j = 0; j < num_blocks; j++) {
                fs->used_blocks[block_num + j] = 0;
            }
            fs->num_files--;
            fs->files[i] = fs->files[fs->num_files];
            return;
        }
    }
    printf("ERROR: File not found!\n");
}

void list_files(filesystem* fs) {
    int i;
    for (i = 0; i < fs->num_files; i++) {
        printf("%s (%d bytes)\n", fs->files[i].filename, fs->files[i].size);
    }
}

int main() {
    filesystem fs;
    initialize_filesystem(&fs);
    
    add_file(&fs, "example.txt", 500);
    add_file(&fs, "image.png", 1500);
    list_files(&fs);
    
    delete_file(&fs, "example.txt");
    list_files(&fs);
    
    return 0;
}