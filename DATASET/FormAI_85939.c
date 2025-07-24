//FormAI DATASET v1.0 Category: File system simulation ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_FILE_NAME 100
#define BLOCK_SIZE 512
#define MAX_BLOCKS 100

typedef struct FileAllocationTable
{
    int block_array[MAX_BLOCKS];
}FAT;

typedef struct File
{
    char name[MAX_FILE_NAME];
    int size;
    int start_block;
}File;

int free_blocks[MAX_BLOCKS];
FAT fat[MAX_BLOCKS];
File files[MAX_BLOCKS];
int current_block = 0;

void initialize()
{
    int i;
    // Initializing Free Block List
    for(i=0;i<MAX_BLOCKS;i++)
        free_blocks[i] = i;
    // Initializing File Allocation Table
    for(i=0;i<MAX_BLOCKS;i++)
    {
        int j;
        for(j=0;j<MAX_BLOCKS;j++)
            fat[i].block_array[j] = -1;
    }
}

int get_free_block()
{
    if(current_block>=MAX_BLOCKS)
        return -1;
    int block = free_blocks[current_block];
    current_block++;
    return block;
}

void create_file(char name[], int size)
{
    int i;
    int start_block = -1;
    for(i=0;i<MAX_BLOCKS;i++)
    {
        if(free_blocks[i] == -1)
            continue;
        int j;
        int count = 0;
        for(j=i;j<MAX_BLOCKS;j++)
        {
            if(free_blocks[j] == -1)
                break;
            count++;
            if(count*size>MAX_BLOCKS-i)
                break;
            if(count*size == MAX_BLOCKS-i)
            {
                start_block = i;
                for(int k=i;k<=j;k++)
                    free_blocks[k] = -1;
                break;
            }
        }
        if(start_block!=-1)
            break;
    }
    if(start_block == -1)
    {
        printf("No free blocks to allocate\n");
        return;
    }
    File new_file;
    strcpy(new_file.name,name);
    new_file.size = size;
    new_file.start_block = start_block;
    files[start_block] = new_file;
    for(int i=start_block;i<start_block+size;i++)
    {
        fat[i].block_array[0] = i+1;
    }
    fat[start_block+size-1].block_array[0] = -1;
}

void delete_file(char name[])
{
    int i;
    for(i=0;i<MAX_BLOCKS;i++)
    {
        if(free_blocks[i] == -1)
            continue;
        if(strcmp(files[i].name,name)==0)
            break;
    }
    if(i == MAX_BLOCKS)
    {
        printf("File not found\n");
        return;
    }
    int start_block = files[i].start_block;
    int size = files[i].size;
    for(int i=start_block;i<start_block+size;i++)
    {
        free_blocks[i] = i;
        fat[i].block_array[0] = -1;
    }
    strcpy(files[i].name,"");
    files[i].size = 0;
    files[i].start_block = -1;
}

void display_fat()
{
    printf("Block \t Linked Block\n");
    for(int i=0;i<MAX_BLOCKS;i++)
    {
        if(free_blocks[i]==-1)
            continue;
        printf("%d \t%d\n",i,fat[i].block_array[0]);
    }
}

int main()
{
    initialize();
    create_file("file1",6);
    create_file("file2",3);
    create_file("file3",2);
    display_fat();
    delete_file("file2");
    display_fat();
    create_file("file4",2);
    display_fat();
    return 0;
}