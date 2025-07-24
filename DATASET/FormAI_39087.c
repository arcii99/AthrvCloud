//FormAI DATASET v1.0 Category: File system simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512
#define NUM_BLOCKS 4096
#define FILE_NAME_LEN 16
#define FILE_TABLE_ENTRIES 16

typedef struct {
    char file_name[FILE_NAME_LEN];
    int start_block;
    int num_blocks;
} file_table_entry;

typedef struct {
    int free_block_list[NUM_BLOCKS];
    file_table_entry file_table[FILE_TABLE_ENTRIES];
} fs_t;

void init_fs(fs_t *fs) {
    memset(fs->free_block_list, -1, sizeof(fs->free_block_list));
    for (int i = 0; i < FILE_TABLE_ENTRIES; i++) {
        memset(fs->file_table[i].file_name, 0, FILE_NAME_LEN);
        fs->file_table[i].start_block = -1;
        fs->file_table[i].num_blocks = 0;
    }
}

int allocate_block(fs_t *fs) {
    for (int i = 0; i < NUM_BLOCKS; i++) {
        if (fs->free_block_list[i] == -1) {
            fs->free_block_list[i] = 0;
            return i;
        }
    }
    return -1; // no free blocks
}

void free_block(fs_t *fs, int block_num) {
    fs->free_block_list[block_num] = -1;
}

void add_file(fs_t *fs, char *file_name, int num_blocks) {
    int start_block = allocate_block(fs);
    if (start_block == -1) {
        printf("Error: no free blocks\n");
        return;
    }
    for (int i = 1; i < num_blocks; i++) {
        int block_num = allocate_block(fs);
        if (block_num == -1) {
            printf("Error: no free blocks\n");
            return;
        }
    }
    for (int i = 0; i < FILE_TABLE_ENTRIES; i++) {
        if (fs->file_table[i].start_block == -1) {
            strncpy(fs->file_table[i].file_name, file_name, FILE_NAME_LEN);
            fs->file_table[i].start_block = start_block;
            fs->file_table[i].num_blocks = num_blocks;
            return;
        }
    }
    printf("Error: file table full\n");
}

void delete_file(fs_t *fs, char *file_name) {
    for (int i = 0; i < FILE_TABLE_ENTRIES; i++) {
        if (strncmp(fs->file_table[i].file_name, file_name, FILE_NAME_LEN) == 0) {
            for (int j = fs->file_table[i].start_block; j < fs->file_table[i].start_block + fs->file_table[i].num_blocks; j++) {
                free_block(fs, j);
            }
            memset(fs->file_table[i].file_name, 0, FILE_NAME_LEN);
            fs->file_table[i].start_block = -1;
            fs->file_table[i].num_blocks = 0;
            return;
        }
    }
    printf("Error: file not found\n");
}

int main(int argc, char **argv) {
    fs_t fs;
    init_fs(&fs);
    add_file(&fs, "file1.txt", 2);
    add_file(&fs, "file2.txt", 3);
    delete_file(&fs, "file1.txt");
    return 0;
}