//FormAI DATASET v1.0 Category: File system simulation ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BLOCKSIZE 1024
#define MAX_BLOCKS 4

struct directory_entry {
    char name[100];
    int block_ptr;
};

struct file {
    int size;
    int block_ptr[MAX_BLOCKS];
};

struct block {
    char data[BLOCKSIZE];
    int next_block;
};

int main() {
    int i, j;
    struct directory_entry dir[10];
    struct file file[10];
    struct block block[MAX_BLOCKS];
    int free_blocks[MAX_BLOCKS];
    int free_block_ptr = 0;

    // Initialize free_blocks array
    for(i=0;i<MAX_BLOCKS;i++) {
        free_blocks[i] = i+1;
    }
    free_blocks[MAX_BLOCKS-1] = -1;

    // Initialize directory entries
    strcpy(dir[0].name, "file1.txt");
    dir[0].block_ptr = 0;
    strcpy(dir[1].name, "file2.txt");
    dir[1].block_ptr = 1;

    // Initialize file contents
    strcpy(block[0].data, "Hello world!");
    block[0].next_block = 1;
    strcpy(block[1].data, "This is a file system simulation.");
    block[1].next_block = -1;

    // Set file pointers
    file[0].size = strlen(block[0].data) + strlen(block[1].data);
    file[0].block_ptr[0] = 0;
    file[0].block_ptr[1] = 1;

    // Print directory
    printf("Directory:\n");
    for(i=0;i<2;i++) {
        printf("%s\t%d\n", dir[i].name, dir[i].block_ptr);
    }

    // Print file contents
    printf("\nFile contents:\n");
    for(i=0;i<2;i++) {
        printf("%s:", dir[i].name);
        for(j=0;j<MAX_BLOCKS;j++) {
            if(file[i].block_ptr[j] == -1) {
                break;
            }
            printf("%s", block[file[i].block_ptr[j]].data);
        }
        printf("\n");
    }

    // Allocate new block
    int new_block = free_blocks[free_block_ptr];
    free_block_ptr += 1;
    printf("\nAllocated new block: %d\n", new_block);

    // Write to new block
    strcpy(block[new_block].data, "More text added to file1.txt");
    block[new_block].next_block = -1;

    // Update file pointers
    file[0].size += strlen(block[new_block].data);
    file[0].block_ptr[2] = new_block;
    printf("\nFile pointers updated\n");

    // Print updated file contents
    printf("\nUpdated file contents:\n");
    for(i=0;i<2;i++) {
        printf("%s:", dir[i].name);
        for(j=0;j<MAX_BLOCKS;j++) {
            if(file[i].block_ptr[j] == -1) {
                break;
            }
            printf("%s", block[file[i].block_ptr[j]].data);
        }
        printf("\n");
    }

    return 0;
}