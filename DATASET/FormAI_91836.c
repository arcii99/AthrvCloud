//FormAI DATASET v1.0 Category: File system simulation ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_FILES 100
#define BLOCK_SIZE 1024

typedef struct file_info{
    char name[100];
    int size;
    int start_block;
}file_info;

typedef struct file_allocation_table{
    int block[MAX_FILES];
}file_allocation_table;

void initialize_fat(file_allocation_table* fat){
    int i;
    for(i=0;i<MAX_FILES;i++){
        fat->block[i] = -1;
    }
}

int allocate_blocks(file_allocation_table* fat, int blocks){
    int i, count=0;
    for(i=0;i<MAX_FILES;i++){
        if(fat->block[i] == -1){
            fat->block[i] = 0;
            count++;
            if(count == blocks){
                return i-count+1;
            }
        }
        else{
            count = 0;
        }
    }
    return -1;
}

void display_fat(file_allocation_table* fat){
    int i;
    printf("File Allocation Table:\n");
    for(i=0;i<MAX_FILES;i++){
        printf("Block %d: %d\n", i, fat->block[i]);
    }
}

int main(){
    int block_count = 10;
    int i;
    file_allocation_table fat;
    initialize_fat(&fat);
    file_info files[3];
    strcpy(files[0].name, "file1.txt");
    files[0].size = 2000;
    strcpy(files[1].name, "file2.txt");
    files[1].size = 3500;
    strcpy(files[2].name, "file3.txt");
    files[2].size = 5000;
    for(i=0;i<3;i++){
        int start_block = allocate_blocks(&fat, files[i].size/BLOCK_SIZE + (files[i].size%BLOCK_SIZE ? 1:0));
        if(start_block == -1){
            printf("Error: Not enough space to store %s\n", files[i].name);
            return 0;
        }
        files[i].start_block = start_block;
        printf("%s allocated blocks from %d to %d\n", files[i].name, start_block, start_block+files[i].size/BLOCK_SIZE + (files[i].size%BLOCK_SIZE ? 1:0) - 1);
    }
    display_fat(&fat);
    return 0;
}