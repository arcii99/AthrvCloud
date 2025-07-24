//FormAI DATASET v1.0 Category: File system simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define BLOCK_SIZE 512
#define NUM_BLOCKS 1000

struct File {
    char name[50];
    int starting_block;
    int num_blocks;
};

struct Directory {
    struct File files[MAX_FILES];
    int num_files;
};

char* disk[NUM_BLOCKS];
int free_blocks = NUM_BLOCKS;
struct Directory dir;

int find_free_block() {
    for(int i=0; i<NUM_BLOCKS; i++) {
        if(disk[i] == NULL) {
            return i;
        }
    }
    return -1;
}

void create_file(char* name, int num_blocks) {
    if(dir.num_files >= MAX_FILES) {
        printf("Maximum number of files reached\n");
        return;
    }
    if(num_blocks > free_blocks) {
        printf("Not enough free space on disk\n");
        return;
    }
    int starting_block = find_free_block();
    if(starting_block == -1) {
        printf("Not enough free space on disk\n");
        return;
    }
    struct File new_file;
    strcpy(new_file.name, name);
    new_file.starting_block = starting_block;
    new_file.num_blocks = num_blocks;
    dir.files[dir.num_files++] = new_file;
    free_blocks -= num_blocks;
}

void display_directory() {
    printf("Directory:\n");
    for(int i=0; i<dir.num_files; i++) {
        printf("%s (Blocks %d-%d)\n", dir.files[i].name, dir.files[i].starting_block, 
               dir.files[i].starting_block+dir.files[i].num_blocks-1);
    }
}

void write_to_file(char* name, char* data) {
    for(int i=0; i<dir.num_files; i++) {
        if(strcmp(dir.files[i].name, name) == 0) {
            int block_ptr = dir.files[i].starting_block;
            int blocks_remaining = dir.files[i].num_blocks;
            while(blocks_remaining > 0) {
                if(disk[block_ptr] == NULL) {
                    disk[block_ptr] = malloc(BLOCK_SIZE);
                }
                int bytes_to_write = BLOCK_SIZE < strlen(data) ? BLOCK_SIZE : strlen(data);
                strncpy(disk[block_ptr], data, bytes_to_write);
                blocks_remaining--;
                block_ptr++;
            }
            printf("Data written to %s\n", name);
            return;
        }
    }
    printf("File not found\n");
}

void read_from_file(char* name, int num_bytes) {
    for(int i=0; i<dir.num_files; i++) {
        if(strcmp(dir.files[i].name, name) == 0) {
            int block_ptr = dir.files[i].starting_block;
            int blocks_remaining = dir.files[i].num_blocks;
            while(blocks_remaining > 0) {
                if(disk[block_ptr] != NULL) {
                    int bytes_to_read = BLOCK_SIZE < num_bytes ? BLOCK_SIZE : num_bytes;
                    printf("%.*s", bytes_to_read, disk[block_ptr]);
                    num_bytes -= BLOCK_SIZE;
                }
                blocks_remaining--;
                block_ptr++;
            }
            printf("\n");
            return;
        }
    }
    printf("File not found\n");
}

int main() {
    // Initialize disk
    for(int i=0; i<NUM_BLOCKS; i++) {
        disk[i] = NULL;
    }
    // Initialize directory
    dir.num_files = 0;

    create_file("file1.txt", 3);
    create_file("file2.txt", 1);
    display_directory();

    write_to_file("file1.txt", "This is some data");
    read_from_file("file1.txt", 10);
    read_from_file("file1.txt", 20);

    write_to_file("file2.txt", "Hello world");
    read_from_file("file2.txt", 20);
    
    return 0;
}