//FormAI DATASET v1.0 Category: File system simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_SIZE 20
#define MAX_FILE_COUNT 100

typedef struct {
    char name[MAX_FILENAME_SIZE];
    int size;
    char data[100];
} file;

typedef struct {
    int block_size;
    int max_blocks;
    int used_blocks;
    file files[MAX_FILE_COUNT];
    int blocks[100];
} file_system;

void initialize_file_system(file_system* fs, int block_size, int max_blocks) {
    fs->block_size = block_size;
    fs->max_blocks = max_blocks;
    fs->used_blocks = 0;
    for (int i=0; i<max_blocks; i++) {
        fs->blocks[i] = 0;
    }
}

int find_empty_block(file_system* fs) {
    for (int i=0; i<fs->max_blocks; i++) {
        if (fs->blocks[i] == 0) {
            fs->blocks[i] = 1;
            fs->used_blocks++;
            return i;
        }
    }
    return -1;
}

void add_file(file_system* fs, char* name, int size, char* data) {
    if (fs->used_blocks == fs->max_blocks) {
        printf("Error: File system is full\n");
        return;
    }
    if (strlen(name) > MAX_FILENAME_SIZE) {
        printf("Error: File name is too long\n");
        return;
    }
    if (size > (fs->max_blocks - fs->used_blocks) * fs->block_size) {
        printf("Error: File is too big\n");
        return;
    }
    file f;
    strcpy(f.name, name);
    f.size = size;
    strcpy(f.data, data);
    int blocks_needed = (size + fs->block_size - 1) / fs->block_size;
    int block_index = find_empty_block(fs);
    f.data[0] = block_index;
    for (int i=0; i<blocks_needed-1; i++) {
        block_index = find_empty_block(fs);
        f.data[(i+1)*fs->block_size] = block_index;
    }
    fs->files[fs->used_blocks-1] = f;
}

void delete_file(file_system* fs, char* name) {
    for (int i=0; i<fs->used_blocks; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            int block_index = fs->files[i].data[0];
            while (block_index != -1) {
                fs->blocks[block_index] = 0;
                fs->used_blocks--;
                block_index = fs->files[i].data[block_index];
            }
            for (int j=i+1; j<fs->used_blocks+1; j++) {
                fs->files[j-1] = fs->files[j];
            }
            printf("File %s deleted\n", name);
            return;
        }
    }
    printf("Error: File not found\n");
}

void print_file_system(file_system* fs) {
    int num_empty_blocks = fs->max_blocks - fs->used_blocks;
    printf("File system:\n");
    printf("Block size: %d\n", fs->block_size);
    printf("Max blocks: %d\n", fs->max_blocks);
    printf("Used blocks: %d\n", fs->used_blocks);
    printf("Empty blocks: %d\n", num_empty_blocks);
    printf("\n");
    for (int i=0; i<fs->used_blocks; i++) {
        printf("File %d:\n", i+1);
        printf("Name: %s\n", fs->files[i].name);
        printf("Size: %d bytes\n", fs->files[i].size);
        printf("Blocks:\n");
        int block_index = fs->files[i].data[0];
        while (block_index != -1) {
            printf("%d ", block_index);
            block_index = fs->files[i].data[block_index];
        }
        printf("\n");
        printf("\n");
    }
}

int main() {
    int block_size = 10;
    int max_blocks = 10;
    file_system fs;
    initialize_file_system(&fs, block_size, max_blocks);
    add_file(&fs, "file1", 20, "This is file1.");
    add_file(&fs, "file2", 30, "This is file2.");
    add_file(&fs, "file3", 15, "This is file3.");
    print_file_system(&fs);
    delete_file(&fs, "file2");
    print_file_system(&fs);
    return 0;
}