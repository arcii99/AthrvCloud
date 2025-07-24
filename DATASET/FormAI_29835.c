//FormAI DATASET v1.0 Category: File system simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_SYSTEM_SIZE 1024 // define the maximum size of the file system
#define NO_OF_BLOCKS 32 // define the number of blocks in the file system
#define BLOCK_SIZE 32 // define the block size of the system

typedef struct _block
{
    char data[BLOCK_SIZE];
    int next_block;
} Block;

Block filesystem[NO_OF_BLOCKS]; // declare the file system
int free_block = 0; // initialize the first block as the free_block

void initFileSystem()
{
    // set all blocks in the file system to be free
    for(int i=0; i<NO_OF_BLOCKS; i++)
    {
        filesystem[i].next_block = -1;
    }
}

int allocateBlock()
{
    // allocate a new block and update the free_block
    int allocated = free_block;
    free_block = filesystem[free_block].next_block;
    filesystem[allocated].next_block = -1;
    return allocated;
}

void freeBlock(int block_num)
{
    // free a used block and update the free_block
    filesystem[block_num].next_block = free_block;
    free_block = block_num;
}

void writeFile(char* filename, char* data)
{
    int file_block = allocateBlock();
    int data_len = strlen(data);
    int curr_block = file_block;
    int data_index = 0;
    
    // write data to the allocated blocks
    while(data_index < data_len)
    {
        strncpy(filesystem[curr_block].data, &data[data_index], BLOCK_SIZE);
        data_index += BLOCK_SIZE;
        
        if(data_len - data_index > 0)
        {
            curr_block = allocateBlock();
            filesystem[file_block].next_block = curr_block;
        }
    }
    
    // write the filename to the first block of the file
    strncpy(filesystem[file_block].data, filename, BLOCK_SIZE);
}

void readFile(char* filename)
{
    int curr_block = 0;
    while(curr_block != -1)
    {
        // compare the filename in the current block and print the block data if it matches
        if(strcmp(filesystem[curr_block].data, filename) == 0)
        {
            curr_block = filesystem[curr_block].next_block;
            while(curr_block != -1)
            {
                printf("%s", filesystem[curr_block].data);
                curr_block = filesystem[curr_block].next_block;
            }
            printf("\n");
            return;
        }
        else
        {
            curr_block = filesystem[curr_block].next_block;
        }
    }
    
    printf("File not found.\n");
}

void deleteFile(char* filename)
{
    int curr_block = 0;
    int prev_block = -1;
    while(curr_block != -1)
    {
        // compare the filename in the current block and free the blocks if it matches
        if(strcmp(filesystem[curr_block].data, filename) == 0)
        {
            if(prev_block == -1)
            {
                freeBlock(curr_block);
            }
            else
            {
                filesystem[prev_block].next_block = filesystem[curr_block].next_block;
                freeBlock(curr_block);
            }
            return;
        }
        else
        {
            prev_block = curr_block;
            curr_block = filesystem[curr_block].next_block;
        }
    }
    
    printf("File not found.\n");
}

int main()
{
    initFileSystem();
    
    // test cases
    writeFile("file1.txt", "hello world ");
    writeFile("file2.txt", "this is a test ");
    writeFile("file3.txt", "of the file system. ");
    
    readFile("file1.txt");
    readFile("file2.txt");
    readFile("file3.txt");
    
    deleteFile("file2.txt");
    readFile("file2.txt");
    
    deleteFile("file1.txt");
    deleteFile("file3.txt");
    
    return 0;
}