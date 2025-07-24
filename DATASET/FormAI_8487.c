//FormAI DATASET v1.0 Category: File system simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BLOCKS 1000 /* Maximum number of blocks in the file system */
#define MAX_BLOCK_SIZE 1024 /* Maximum size of each block */

struct block {
    int id; /* Id of the block */
    char data[MAX_BLOCK_SIZE]; /* Data stored in the block */
};

struct file {
    int id; /* Id of the file */
    char name[50]; /* Name of the file */
    int size; /* Size of the file */
    int block_ids[MAX_BLOCKS]; /* Ids of the blocks that store the file */
};

struct block blocks[MAX_BLOCKS];
struct file files[MAX_BLOCKS];
int num_blocks = 0, num_files = 0;

int get_block_id() {
    int i;
    for(i=0;i<num_blocks;i++) {
        if(blocks[i].id == -1) {
            return i;
        }
    }
    printf("Error: Maximum number of blocks reached!\n");
    exit(0);
}

void create_block() {
    blocks[num_blocks].id = num_blocks;
    memset(blocks[num_blocks].data, 0, sizeof(blocks[num_blocks].data));
    num_blocks++;
}

void create_file(char name[], char data[]) {
    files[num_files].id = num_files;
    strcpy(files[num_files].name, name);
    files[num_files].size = strlen(data);
    int num_blocks_required = (files[num_files].size / MAX_BLOCK_SIZE) + 1;
    int i, j;
    for(i=0;i<num_blocks_required;i++) {
        int block_id = get_block_id();
        files[num_files].block_ids[i] = block_id;
        for(j=0;j<MAX_BLOCK_SIZE && (i*MAX_BLOCK_SIZE+j)<files[num_files].size;j++) {
            blocks[block_id].data[j] = data[i*MAX_BLOCK_SIZE+j];
        }
    }
    num_files++;
}

void read_file(int file_id) {
    int i, j;
    printf("Reading file %s:\n", files[file_id].name);
    for(i=0;i<(files[file_id].size/MAX_BLOCK_SIZE)+1;i++) {
        printf("Block %d:\n", i+1);
        for(j=0;j<MAX_BLOCK_SIZE && (i*MAX_BLOCK_SIZE+j)<files[file_id].size;j++) {
            printf("%c", blocks[files[file_id].block_ids[i]].data[j]);
        }
        printf("\n");
    }
}

int main() {
    int i;
    for(i=0;i<MAX_BLOCKS;i++) {
        blocks[i].id = -1;
    }

    create_block();
    create_file("test1.txt", "Hello world!");

    read_file(0);

    return 0;
}