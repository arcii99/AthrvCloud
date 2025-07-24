//FormAI DATASET v1.0 Category: File system simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME_SIZE 20
#define BLOCK_SIZE 1024
#define BLOCK_CNT 10000

// FCB (File Control Block) structure
typedef struct {
    char name[FILENAME_SIZE];
    unsigned int size;
    unsigned int start_block;
} fcb;

// FAT (File Allocation Table) structure
typedef struct {
    unsigned int next_block;
} fat_entry;

// File System structure
typedef struct {
    char* data;
    fcb* fcbs;
    fat_entry* fat;
    unsigned int fat_size;
} fs;

// Initializes a new file system
fs* init_fs() {
    fs* new_fs = (fs*) malloc(sizeof(fs));
    new_fs->data = (char*) malloc(BLOCK_SIZE * BLOCK_CNT);
    new_fs->fcbs = (fcb*) calloc(BLOCK_CNT, sizeof(fcb));
    new_fs->fat = (fat_entry*) calloc(BLOCK_CNT, sizeof(fat_entry));
    new_fs->fat_size = BLOCK_CNT;

    return new_fs;
}

// Allocates a new block in the FAT
unsigned int allocate_block(fs* fs_ptr) { 
    for (unsigned int i = 0; i < fs_ptr->fat_size; i++) {
        if (fs_ptr->fat[i].next_block == 0) {
            fs_ptr->fat[i].next_block = -1;
            return i;
        }
    }

    return -1;
}

// Deallocates a block in the FAT
void deallocate_block(fs* fs_ptr, unsigned int block) {
    fs_ptr->fat[block].next_block = 0;
}

// Creates a new file in the file system
void create_file(fs* fs_ptr, char* name) {
    unsigned int new_block = allocate_block(fs_ptr);

    if (new_block != -1) {
        fcb new_fcb;
        strncpy(new_fcb.name, name, FILENAME_SIZE);
        new_fcb.size = 0;
        new_fcb.start_block = new_block;

        fs_ptr->fcbs[new_block] = new_fcb;
    }
}

// Writes data to a file in the file system
void write_file(fs* fs_ptr, char* name, char* data) {
    for (unsigned int i = 0; i < fs_ptr->fat_size; i++) {
        if (strcmp(fs_ptr->fcbs[i].name, name) == 0) {
            unsigned int block = fs_ptr->fcbs[i].start_block;

            while (fs_ptr->fat[block].next_block != -1) {
                block = fs_ptr->fat[block].next_block;
            }

            unsigned int data_len = strlen(data);
            unsigned int blocks_needed = (data_len / BLOCK_SIZE) + 1;

            for (unsigned int j = 0; j < blocks_needed; j++) {
                unsigned int new_block = allocate_block(fs_ptr);
                fs_ptr->fat[block].next_block = new_block;
                block = new_block;

                if (j == 0) {
                    strncpy(fs_ptr->data + (block * BLOCK_SIZE), data, BLOCK_SIZE);
                    fs_ptr->fcbs[i].size = data_len;
                } else {
                    strncpy(fs_ptr->data + (block * BLOCK_SIZE), data + (j * BLOCK_SIZE), BLOCK_SIZE);
                }
            }

            break;
        }
    }
}

// Reads data from a file in the file system
char* read_file(fs* fs_ptr, char* name) {
    for (unsigned int i = 0; i < fs_ptr->fat_size; i++) {
        if (strcmp(fs_ptr->fcbs[i].name, name) == 0) {
            unsigned int block = fs_ptr->fcbs[i].start_block;
            unsigned int size = fs_ptr->fcbs[i].size;
            char* data = (char*) malloc(size + 1);

            for (unsigned int j = 0; j < (size / BLOCK_SIZE) + 1; j++) {
                strncpy(data + (j * BLOCK_SIZE), fs_ptr->data + (block * BLOCK_SIZE), BLOCK_SIZE);
                block = fs_ptr->fat[block].next_block;
            }

            data[size] = '\0';
            return data;
        }
    }

    return NULL;
}

// Deletes a file from the file system
void delete_file(fs* fs_ptr, char* name) {
    for (unsigned int i = 0; i < fs_ptr->fat_size; i++) {
        if (strcmp(fs_ptr->fcbs[i].name, name) == 0) {
            unsigned int block = fs_ptr->fcbs[i].start_block;

            while (fs_ptr->fat[block].next_block != -1) {
                unsigned int next_block = fs_ptr->fat[block].next_block;
                deallocate_block(fs_ptr, block);
                block = next_block;
            }

            deallocate_block(fs_ptr, block);
            memset(&fs_ptr->fcbs[i], 0, sizeof(fcb));
            break;
        }
    }
}

int main() {
    fs* my_fs = init_fs();
    
    // create and write to a file
    create_file(my_fs, "my_file.txt");
    write_file(my_fs, "my_file.txt", "Hello, world!");
    printf("%s\n", read_file(my_fs, "my_file.txt"));

    // delete the file
    delete_file(my_fs, "my_file.txt");

    return 0;
}