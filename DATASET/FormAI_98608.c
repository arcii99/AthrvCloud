//FormAI DATASET v1.0 Category: File system simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 1024
#define MAX_BLOCKS 100

typedef struct {
    char file_name[100];
    int start_block;
    int num_blocks;
} File_Entry;

typedef struct {
    char block[BLOCK_SIZE];
} Block;

Block blocks[MAX_BLOCKS];
File_Entry file_table[MAX_BLOCKS];

int num_free_blocks = MAX_BLOCKS;

void print_file_table() {
    printf("File Table:\n");
    printf("File Name\tStart Block\tNum Blocks\n");

    for (int i = 0; i < MAX_BLOCKS; i++) {
        if (file_table[i].num_blocks > 0) {
            printf("%s\t\t%d\t\t%d\n", file_table[i].file_name, file_table[i].start_block, file_table[i].num_blocks);
        }
    }

    printf("\n");
}

void create_file(char* file_name, int num_blocks) {
    if (num_free_blocks < num_blocks) {
        printf("Error: not enough free blocks to create file\n");
        return;
    }

    for (int i = 0; i < MAX_BLOCKS; i++) {
        if (file_table[i].num_blocks == 0) {
            strncpy(file_table[i].file_name, file_name, 100);
            file_table[i].num_blocks = num_blocks;

            int start_block = -1;
            for (int j = 0; j < MAX_BLOCKS; j++) {
                if (blocks[j].block[0] == '\0') {
                    if (start_block == -1) start_block = j;
                    num_free_blocks--;
                    if (num_free_blocks == 0) break;
                    if (num_free_blocks == num_blocks - 1) break;
                } else {
                    start_block = -1;
                }
            }

            if (start_block == -1) {
                printf("Error: not enough contiguous free blocks to create file\n");
                file_table[i].num_blocks = 0;
                num_free_blocks += num_blocks;
                return;
            }

            file_table[i].start_block = start_block;

            for (int j = 0; j < num_blocks; j++) {
                memset(blocks[start_block + j].block, 0, BLOCK_SIZE);
            }

            printf("Created file %s with %d blocks starting at block %d\n", file_name, num_blocks, start_block);
            print_file_table();
            return;
        }
    }

    printf("Error: file table is full\n");
}

void delete_file(char* file_name) {
    for (int i = 0; i < MAX_BLOCKS; i++) {
        if (file_table[i].num_blocks > 0 && strcmp(file_table[i].file_name, file_name) == 0) {
            memset(file_table[i].file_name, 0, 100);
            int start_block = file_table[i].start_block;
            int num_blocks = file_table[i].num_blocks;
            file_table[i].start_block = 0;
            file_table[i].num_blocks = 0;
            num_free_blocks += num_blocks;
            for (int j = 0; j < num_blocks; j++) {
                memset(blocks[start_block + j].block, 0, BLOCK_SIZE);
            }
            printf("Deleted file %s\n", file_name);
            print_file_table();
            return;
        }
    }

    printf("Error: file %s not found\n", file_name);
}

void write_file(char* file_name, char* data) {
    for (int i = 0; i < MAX_BLOCKS; i++) {
        if (file_table[i].num_blocks > 0 && strcmp(file_table[i].file_name, file_name) == 0) {
            int start_block = file_table[i].start_block;
            int num_blocks = file_table[i].num_blocks;

            int data_len = strlen(data);
            int bytes_written = 0;
            for (int j = 0; j < num_blocks; j++) {
                int bytes_left = BLOCK_SIZE;
                if (data_len - bytes_written < BLOCK_SIZE) {
                    bytes_left = data_len - bytes_written;
                }
                memcpy(blocks[start_block + j].block, data + bytes_written, bytes_left);
                bytes_written += bytes_left;
            }

            printf("Wrote %d bytes to file %s\n", bytes_written, file_name);
            return;
        }
    }

    printf("Error: file %s not found\n", file_name);
}

void read_file(char* file_name) {
    for (int i = 0; i < MAX_BLOCKS; i++) {
        if (file_table[i].num_blocks > 0 && strcmp(file_table[i].file_name, file_name) == 0) {
            int start_block = file_table[i].start_block;
            int num_blocks = file_table[i].num_blocks;

            int bytes_read = 0;
            for (int j = 0; j < num_blocks; j++) {
                printf("%s", blocks[start_block + j].block);
                bytes_read += strlen(blocks[start_block + j].block);
            }

            printf("\nRead %d bytes from file %s\n", bytes_read, file_name);
            return;
        }
    }

    printf("Error: file %s not found\n", file_name);
}

int main() {
    printf("Creating file system...\n");
    printf("Number of blocks: %d\n", MAX_BLOCKS);
    printf("Block size: %d bytes\n", BLOCK_SIZE);
    printf("Free blocks: %d\n", num_free_blocks);
    printf("\n");

    create_file("test.txt", 3);
    write_file("test.txt", "hello world\n");
    read_file("test.txt");
    delete_file("test.txt");

    create_file("another.txt", 2);
    write_file("another.txt", "test data\n");
    read_file("another.txt");
    delete_file("another.txt");

    return 0;
}