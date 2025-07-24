//FormAI DATASET v1.0 Category: File system simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define BLOCK_SIZE 1024
#define BLOCK_NUM 1000

// structure to represent file
typedef struct file {
    char *name;
    int size;
    int block_num;
    int block_ptr[10];
} file;

// structure to represent block
typedef struct block {
    int index;
    char *data;
    bool occupied;
} block;

// variables to represent file system
file files[100];
block blocks[1000];
int free_blocks[BLOCK_NUM];
int next_free_block;

// function to initialize file system
void init_file_system() {
    int i;

    // initialize files
    for (i = 0; i < 100; i++) {
        files[i].name = NULL;
        files[i].size = -1;
        files[i].block_num = -1;
        memset(files[i].block_ptr, -1, sizeof(files[i].block_ptr));
    }

    // initialize blocks
    for (i = 0; i < 1000; i++) {
        blocks[i].index = i;
        blocks[i].data = malloc(BLOCK_SIZE);
        blocks[i].occupied = false;
    }

    // initialize free block list
    for (i = 0; i < BLOCK_NUM; i++) {
        free_blocks[i] = i;
    }

    // set next free block pointer
    next_free_block = 0;
}

// function to allocate block
int allocate_block() {
    int block_index = free_blocks[next_free_block++];

    // mark block as occupied
    blocks[block_index].occupied = true;

    return block_index;
}

// function to deallocate block
void deallocate_block(int block_index) {
    // mark block as unoccupied
    blocks[block_index].occupied = false;

    // add block to free block list
    free_blocks[--next_free_block] = block_index;
}

// function to create file in file system
void create_file(char *name, int size) {
    int i, block_index;

    // search for free file structure
    for (i = 0; i < 100; i++) {
        if (files[i].name == NULL) {
            files[i].name = malloc(strlen(name) + 1);
            strcpy(files[i].name, name);
            files[i].size = size;
            files[i].block_num = size / BLOCK_SIZE + (size % BLOCK_SIZE != 0);

            // allocate blocks for file
            for (int j = 0; j < files[i].block_num; j++) {
                block_index = allocate_block();
                files[i].block_ptr[j] = block_index;
            }

            break;
        }
    }
}

// function to delete file from file system
void delete_file(char *name) {
    int i, j, block_index;

    // search for file
    for (i = 0; i < 100; i++) {
        if (files[i].name != NULL && strcmp(files[i].name, name) == 0) {
            // deallocate blocks of file
            for (j = 0; j < files[i].block_num; j++) {
                block_index = files[i].block_ptr[j];
                deallocate_block(block_index);
                files[i].block_ptr[j] = -1;
            }

            // free file name
            free(files[i].name);
            files[i].name = NULL;
            files[i].size = -1;
            files[i].block_num = -1;
            memset(files[i].block_ptr, -1, sizeof(files[i].block_ptr));

            break;
        }
    }
}

// function to read file from file system
void read_file(char *name) {
    int i, block_index, offset = 0;
    char buffer[BLOCK_SIZE];

    // search for file
    for (i = 0; i < 100; i++) {
        if (files[i].name != NULL && strcmp(files[i].name, name) == 0) {
            // read blocks of file
            for (int j = 0; j < files[i].block_num; j++) {
                block_index = files[i].block_ptr[j];
                memcpy(buffer, blocks[block_index].data, BLOCK_SIZE);
                printf("%.*s", files[i].size - offset > BLOCK_SIZE ? BLOCK_SIZE : files[i].size - offset, buffer);
                offset += BLOCK_SIZE;
            }

            break;
        }
    }
}

// function to write file to file system
void write_file(char *name, char *data) {
    int i, j, block_index, offset = 0;

    // search for file
    for (i = 0; i < 100; i++) {
        if (files[i].name != NULL && strcmp(files[i].name, name) == 0) {
            // write data to blocks of file
            for (j = 0; j < files[i].block_num; j++) {
                block_index = files[i].block_ptr[j];
                memcpy(blocks[block_index].data, data + offset, BLOCK_SIZE);
                offset += BLOCK_SIZE;
            }

            break;
        }
    }
}

// function to print file system
void print_file_system() {
    int i, j, block_index;

    printf("Files:\n");
    for (i = 0; i < 100; i++) {
        if (files[i].name != NULL) {
            printf("%s\t%d\t", files[i].name, files[i].size);
            for (j = 0; j < files[i].block_num; j++) {
                block_index = files[i].block_ptr[j];
                printf("%d ", block_index);
            }
            printf("\n");
        }
    }

    printf("Free Blocks:\n");
    for (i = 0; i < BLOCK_NUM; i++) {
        if (blocks[i].occupied == false) {
            printf("%d ", blocks[i].index);
        }
    }
    printf("\n");
}

int main() {
    init_file_system();
    create_file("file1", 2048);
    write_file("file1", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed sit amet felis vitae odio hendrerit aliquet. Maecenas vitae odio ac leo maximus posuere. Maecenas quis orci velit. ");
    print_file_system();
    read_file("file1");
    delete_file("file1");
    print_file_system();

    return 0;
}