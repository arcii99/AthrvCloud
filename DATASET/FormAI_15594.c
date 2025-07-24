//FormAI DATASET v1.0 Category: File system simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512
#define FILE_NAME_SIZE 20
#define FILE_TYPE_SIZE 5
#define MAX_FILES 20

typedef struct {
    int size;
    int blocks[10];
} file;

typedef struct {
    char name[FILE_NAME_SIZE];
    char type[FILE_TYPE_SIZE];
    int size;
    int allocated_blocks;
    int blocks[10];
} file_metadata;

typedef struct {
    int block_size;
    int free_blocks;
    int used_blocks;
    file_metadata entries[MAX_FILES];
    file blocks[MAX_FILES];
} file_system;

void init_file_system(file_system *fs, int block_size) {
    fs->block_size = block_size;
    fs->free_blocks = MAX_FILES;
    fs->used_blocks = 0;

    for (int i = 0; i < MAX_FILES; i++) {
        fs->entries[i].size = 0;
        fs->entries[i].allocated_blocks = 0;
        strcpy(fs->entries[i].name, "");
        strcpy(fs->entries[i].type, "");
        
        for (int j = 0; j < 10; j++) {
            fs->entries[i].blocks[j] = -1;
            fs->blocks[i].blocks[j] = -1;
        }
    }
}

int allocate_block(file_system *fs) {
    if (fs->free_blocks == 0) {
        return -1;
    }
    
    for (int i = 0; i < MAX_FILES; i++) {
        if (fs->entries[i].allocated_blocks == 0) {
            fs->entries[i].allocated_blocks = 1;
            fs->free_blocks--;
            fs->used_blocks++;
            return i;
        }
    }
}

int create_file(file_system *fs, char *name, char *type, int size) {
    int file_index = allocate_block(fs);
    
    if (file_index == -1) {
        return -1;
    }
    
    strcpy(fs->entries[file_index].name, name);
    strcpy(fs->entries[file_index].type, type);
    fs->entries[file_index].size = size;
    
    int blocks_needed = (size + BLOCK_SIZE - 1) / BLOCK_SIZE;
    
    if (blocks_needed > 10) {
        return -1;
    }
    
    for (int i = 0; i < blocks_needed; i++) {
        int block_index = allocate_block(fs);
        
        if (block_index == -1) {
            return -1;
        }
        
        fs->entries[file_index].blocks[i] = block_index;
        fs->blocks[block_index].size = (i == blocks_needed - 1) ? size % BLOCK_SIZE : BLOCK_SIZE;
    }
    
    return file_index;
}

int delete_file(file_system *fs, int file_index) {
    if (fs->entries[file_index].allocated_blocks == 1) {
        fs->entries[file_index].allocated_blocks = 0;
        fs->free_blocks++;
        fs->used_blocks--;
        
        for (int i = 0; i < 10; i++) {
            int block_index = fs->entries[file_index].blocks[i];
            
            if (block_index != -1) {
                fs->entries[file_index].blocks[i] = -1;
                fs->blocks[block_index].size = -1;
                fs->free_blocks++;
                fs->used_blocks--;
            }
        }
        
        return 0;
    } else {
        return -1;
    }
}

void list_files(file_system *fs) {
    printf("\nFiles in file system:\n");
    
    for (int i = 0; i < MAX_FILES; i++) {
        if (fs->entries[i].allocated_blocks == 1) {
            printf("%s.%s - %d bytes\n", fs->entries[i].name, fs->entries[i].type, fs->entries[i].size);
        }
    }
}

int main() {
    file_system fs;
    init_file_system(&fs, BLOCK_SIZE);
    
    int file_index1 = create_file(&fs, "file1", "txt", 1024);
    int file_index2 = create_file(&fs, "file2", "pdf", 4096);
    int file_index3 = create_file(&fs, "file3", "png", 3072);
    
    printf("Created files:\n");
    list_files(&fs);
    
    int result = delete_file(&fs, file_index2);
    
    if (result == 0) {
        printf("\nDeleted file:\n");
        list_files(&fs);
    } else {
        printf("Failed to delete file.\n");
    }
    
    return 0;
}