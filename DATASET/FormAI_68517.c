//FormAI DATASET v1.0 Category: File system simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 50
#define MAX_FILE_NAME 20
#define BLOCK_SIZE 512
#define NUM_BLOCKS 1000

typedef struct {
    int size;
    char name[MAX_FILE_NAME];
    int blocks[10];
} File;

typedef struct {
    char* data;
    int next_block;
} Block;

File file_table[MAX_FILES];
Block disk[NUM_BLOCKS];

void initialize_disk() {
    int i;
    for(i=0;i<NUM_BLOCKS;i++) {
        disk[i].data = (char*)malloc(BLOCK_SIZE*sizeof(char));
        disk[i].next_block = -1;
    }
}

int find_free_block() {
    int i;
    for(i=0;i<NUM_BLOCKS;i++) {
        if(disk[i].next_block == -1) 
            return i;
    }
    return -1;
}

int create_file(char* name) {
    int i;
    for(i=0;i<MAX_FILES;i++) {
        if(file_table[i].size == 0) {
            int free_block = find_free_block();
            if(free_block == -1) return -1;
            file_table[i].size = 0;
            strcpy(file_table[i].name,name);
            file_table[i].blocks[0] = free_block;
            disk[free_block].next_block = -1;
            return i;
        }
    }   
    return -1;
}

int write_file(int index, char* data) {
    int write_index = file_table[index].size;
    int block_index = file_table[index].blocks[write_index/BLOCK_SIZE];
    int offset = write_index%BLOCK_SIZE;
    int i = 0;
    while(i < strlen(data)) {
        if(offset == BLOCK_SIZE) {
            int free_block = find_free_block();
            if(free_block == -1) return -1;
            disk[block_index].next_block = free_block;
            block_index = free_block;
            disk[free_block].next_block = -1;
            offset = 0;
        }
        disk[block_index].data[offset] = data[i];
        offset++;i++;
        file_table[index].size++;
    }
    return 0;
}

char* read_file(int index) {
    int read_index = 0;
    int block_index = file_table[index].blocks[0];
    char* result = (char*)malloc(BLOCK_SIZE*sizeof(char));
    int offset = 0;
    while(read_index < file_table[index].size) {
        if(offset == BLOCK_SIZE) {
            block_index = disk[block_index].next_block;
            offset = 0;
        }
        result[read_index] = disk[block_index].data[offset];
        read_index++;offset++;
    }
    return result;
}

int main() {
    initialize_disk();
    int file_index = create_file("example.txt");
    if(file_index==-1) {
        printf("Could not create file\n");
        return 0;
    }
    char* data = "This is an example file\n";
    int res = write_file(file_index,data);
    if(res==-1) {
        printf("Could not write to file\n");
        return 0;
    }
    char* result = read_file(file_index);
    printf("Contents of file: %s",result);
    return 0;
}