//FormAI DATASET v1.0 Category: File system simulation ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>

#define BLOCK_SIZE 1024
#define NUM_BLOCKS 100

struct File {
    char name[50];
    int start_block;
    int end_block;
};

int n_files = 0;
struct File files[100];

char *disk[NUM_BLOCKS];

void init_disk() {
    for(int i=0; i<NUM_BLOCKS; i++) {
        disk[i] = (char *) malloc(sizeof(char) * BLOCK_SIZE);
    }
}

void create_file(char name[], int size) {
    int blocks_req = size/BLOCK_SIZE + 1;
    int start_block = -1, end_block = -1, count = 0;

    for(int i=0; i<NUM_BLOCKS; i++) {
        if(disk[i][0] == 0 && count == 0) {
            start_block = i;
            count++;
        } else if(disk[i][0] == 0 && count < blocks_req) {
            count++;
        } else if(disk[i][0] == 0 && count == blocks_req) {
            end_block = i;
            break;
        } else {
            count = 0;
        }
    }
    if(start_block == -1 || end_block == -1) {
        printf("Not enough space to create file!\n");
        return;
    }

    struct File file;
    strcpy(file.name, name);
    file.start_block = start_block;
    file.end_block = end_block;
    files[n_files++] = file;

    // Write to disk
    int block = start_block;
    int i = 0;
    while(i < size) {
        strncpy(disk[block], &name[i], BLOCK_SIZE);
        i += BLOCK_SIZE;
        block++;
        if(block == end_block) {
            strncpy(disk[block], &name[i], size-i);
            break;
        }
    }
}

void delete_file(char name[]) {
    int index = -1;
    for(int i=0; i<n_files; i++) {
        if(strcmp(files[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        printf("File not found!\n");
        return;
    }
    int start_block = files[index].start_block;
    int end_block = files[index].end_block;
    for(int i=start_block; i<=end_block; i++) {
        for(int j=0; j<BLOCK_SIZE; j++) {
            disk[i][j] = 0;
        }
    }
    for(int i=index; i<n_files-1; i++) {
        files[i] = files[i+1];
    }
    n_files--;
}

int main() {
    init_disk();
    create_file("hello.txt", 1024);
    create_file("world.txt", 2048);
    delete_file("hello.txt");
    return 0;
}