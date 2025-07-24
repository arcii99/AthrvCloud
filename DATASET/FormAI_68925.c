//FormAI DATASET v1.0 Category: File system simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define FILE_NAME_LENGTH 20
#define BLOCK_SIZE 512

typedef struct {
    char name[FILE_NAME_LENGTH];
    int size;
    int blocks[10];
} file;

typedef struct {
    int used; // 1 if block is used, 0 otherwise
    int next; // index of next block in file
} block;

int main() {

    // Initialize the file system
    file files[MAX_FILES];
    block blocks[MAX_FILES][10];
    int free_blocks = MAX_FILES*10;
    int i, j;
    for (i = 0; i < MAX_FILES; i++) {
        files[i].size = 0;
        for (j = 0; j < 10; j++) {
            blocks[i][j].used = 0;
            blocks[i][j].next = -1;
        }
    }

    // Demonstrate creating a new file
    file new_file;
    strcpy(new_file.name, "test.txt");
    new_file.size = 1024;
    int num_blocks = (new_file.size + BLOCK_SIZE - 1) / BLOCK_SIZE;
    if (num_blocks <= free_blocks) {
        int current_block = 0;
        for (i = 0; i < MAX_FILES; i++) {
            if (files[i].size == 0) {
                files[i] = new_file;
                for (j = 0; j < num_blocks && current_block < MAX_FILES*10; j++) {
                    while (blocks[current_block/MAX_FILES][current_block%10].used) {
                        current_block++;
                    }
                    free_blocks--;
                    blocks[i][j].used = 1;
                    blocks[i][j].next = (j < num_blocks - 1) ? (current_block+1) : -1;
                    files[i].blocks[j] = current_block;
                    current_block++;
                }
                break;
            }
        }
        printf("Created new file %s with size %d\n", new_file.name, new_file.size);
    } else {
        printf("Not enough free blocks to create file\n");
    }

    // Demonstrate reading a file
    int file_index;
    for (i = 0; i < MAX_FILES; i++) {
        if (strcmp(files[i].name, "test.txt") == 0) {
            file_index = i;
            break;
        }
    }
    if (i == MAX_FILES) {
        printf("File not found\n");
    } else {
        printf("File %s:\n", files[file_index].name);
        for (j = 0; j < num_blocks; j++) {
            printf("Block %d: ", j);
            if (blocks[file_index][j].used) {
                printf("Data here\n");
            } else {
                printf("Empty\n");
            }
        }
    }

    // Demonstrate deleting a file
    for (i = 0; i < MAX_FILES; i++) {
        if (strcmp(files[i].name, "test.txt") == 0) {
            for (j = 0; j < num_blocks; j++) {
                blocks[i][j].used = 0;
                free_blocks++;
            }
            files[i].size = 0;
            printf("Deleted file %s\n", files[i].name);
            break;
        }
    }
    if (i == MAX_FILES) {
        printf("File not found\n");
    }

    return 0;
}