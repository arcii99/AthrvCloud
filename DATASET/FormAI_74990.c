//FormAI DATASET v1.0 Category: File system simulation ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BLOCK_SIZE 512
#define NUM_BLOCKS 100
#define FILE_NAME_LENGTH 30

typedef struct file
{
    char name[FILE_NAME_LENGTH];
    int size;
    int start_block;
} File;

char block[NUM_BLOCKS][BLOCK_SIZE];
int allocated_blocks[NUM_BLOCKS];

void init_fs()
{
    memset(block, 0, BLOCK_SIZE * NUM_BLOCKS);
    memset(allocated_blocks, 0, sizeof(allocated_blocks));
}

int allocate_block()
{
    for (int i = 0; i < NUM_BLOCKS; i++)
    {
        if (!allocated_blocks[i])
        {
            allocated_blocks[i] = 1;
            return i;
        }
    }

    return -1;
}

void deallocate_block(int block_num)
{
    allocated_blocks[block_num] = 0;
}

int create_file(char* name, int size)
{
    int start_block = allocate_block();
    if (start_block == -1)
    {
        printf("Error: Could not allocate block for file\n");
        return -1;
    }

    int blocks_needed = (size / BLOCK_SIZE) + 1;
    if (blocks_needed > NUM_BLOCKS)
    {
        printf("Error: File is too large for file system\n");
        deallocate_block(start_block);
        return -1;
    }

    File* file = (File*)block[start_block];
    strncpy(file->name, name, FILE_NAME_LENGTH);
    file->size = size;
    file->start_block = start_block;

    for (int i = 1; i < blocks_needed; i++)
    {
        int block_num = allocate_block();
        if (block_num == -1)
        {
            printf("Error: Could not allocate block for file\n");
            deallocate_block(start_block);
            return -1;
        }

        file = (File*)block[block_num];
        file->start_block = start_block;
    }

    return 0;
}

void delete_file(char* name)
{
    for (int i = 0; i < NUM_BLOCKS; i++)
    {
        File* file = (File*)block[i];
        if (strcmp(file->name, name) == 0)
        {
            file->size = 0;
            deallocate_block(i);
        }
    }
}

int main()
{
    init_fs();

    create_file("example.txt", 1024);
    delete_file("example.txt");

    return 0;
}